#include "FeedService.h"
#include "Config.h"
#include "HttpRequest.h"
#include "FileHandler.h"
#include "AuthenticationService.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include "FeedResponse.h"
#include "JsonParser.h"


FeedService::FeedService(QSharedPointer<HttpRequest> httpRequest) :
  parser(new JsonParser),
  articles(new QVector<Article*>),
  logger(new Logger("FeedService")),
  httpRequest(httpRequest) {
  connect(this, SIGNAL(sendRequestSignal(QString)), httpRequest.data(), SLOT(getRequest(QString)));
}

void FeedService::sendRequestData() {
  AuthenticationService authService(httpRequest);
  logger->info(authService.readToken());
  QString path = Config::FEEDPATH + "?token=" + authService.readToken();
  sendRequestSignal(path);
}

void FeedService::replyReady(QJsonObject replyJson) {
  logger->info("Reply finished");
  FeedResponse*  feedResponse = (FeedResponse*)parser->fromJsonObjectToMetaObject(&FeedResponse::staticMetaObject, replyJson);
  if (!feedResponse->isError()) {
    generateArticleVector(replyJson);
    successResponse(); //Signal to ScreenManager
  } else {
    logger->error("Error: " + feedResponse->getError());
    failedResponse(); //Signal to ScreenManager
  }  
  disconnect(httpRequest.data(), SIGNAL(replyReady(QJsonObject)), this, SLOT(replyReady(QJsonObject)));
}

void FeedService::generateArticleVector(QJsonObject replyJson) {
  *articles = parser->parseFromObjectToArticleVector(replyJson);
  if (articles->size() == 0) {
    logger->info("There are no Articles to show.");
  } else {
    logger->debug("Articles count: " + QString(articles->size()));
  }
}

QSharedPointer<QVector<Article*>> FeedService::getArticles() {
  return articles;
}
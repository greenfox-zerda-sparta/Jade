#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QMessageBox>
#include "FeedService.h"
#include "Config.h"
#include "HttpRequest.h"
#include "FileHandler.h"
#include "AuthenticationService.h"
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
  QString path = Config::FEEDPATH + "?token=" + authService.readToken();
  sendRequestSignal(path); // Signal to HTTPRequest
}

void FeedService::replyReady(QJsonObject replyJson) {
  logger->info("Reply finished");
  FeedResponse*  feedResponse = (FeedResponse*)parser->fromJsonObjectToMetaObject(&FeedResponse::staticMetaObject, replyJson);
  if (isSuccess(feedResponse->getError())) {
    logger->info("Success");
    generateArticleVector(replyJson);
    successResponse(); //Signal to ScreenManager
  } else {
    logger->error("Error: " + feedResponse->getError());
    QMessageBox msgBox;
    msgBox.setText(feedResponse->getError() + "\n" + "Please try again!");
    msgBox.exec();
    failedResponse(); //Signal to ScreenManager
  }  
  disconnect(httpRequest.data(), SIGNAL(replyReady(QJsonObject)), this, SLOT(replyReady(QJsonObject)));
}

bool FeedService::isSuccess(QString error) {
  return error == "";
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
#include "FeedService.h"
#include "Config.h"
#include "HttpRequest.h"
#include "FileHandler.h"
#include "AuthenticationService.h"
#include <QNetworkRequest>
#include <QNetworkReply>


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
  *articles = parser->parseFromObjectToArticleVector(replyJson);
  if (articles->size() == 0) {
    logger->info("There are no Articles to show.");
  } else {
    logger->debug("Articles count: " + QString(articles->size()));
  }
  onReady(); //Signal to ScreenManager
  disconnect(httpRequest.data(), SIGNAL(replyReady(QJsonObject)), this, SLOT(replyReady(QJsonObject)));
}

QSharedPointer<QVector<Article*>> FeedService::getArticles() {
  return articles;
}
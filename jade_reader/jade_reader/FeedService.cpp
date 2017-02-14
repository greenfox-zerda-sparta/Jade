#include "FeedService.h"
#include "Config.h"
#include "HttpRequest.h"
#include <QNetworkRequest>
#include <QNetworkReply>


FeedService::FeedService(QSharedPointer<HttpRequest> httpRequest) :
  parser(new JsonParser),
  articles(new QVector<Article*>),
  logger(new Logger("FeedService")),
  httpRequest(httpRequest) {
  connect(httpRequest.data(), SIGNAL(getReady(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void FeedService::getFeed() {
  httpRequest->getRequest();
  logger->info("getFeed - getrequest from manager");
}

void FeedService::replyFinished(QNetworkReply* reply) {
  logger->info("replyFinished - got data from server");
  networkReply = reply;
  *articles = parser->parseFromStringToArticleVector(networkReply->readAll());
  logger->info("articles size " + QString(articles->size()));
  networkReply->deleteLater();
  networkReply = NULL;
  this->onReady(articles.data());
}


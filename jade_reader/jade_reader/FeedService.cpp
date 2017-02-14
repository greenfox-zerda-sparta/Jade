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
  connect(httpRequest.data(), SIGNAL(getReady(QString)), this, SLOT(replyFinished(QString)));
}

void FeedService::getFeed() {
  httpRequest->getRequest();
  logger->info("getFeed - getrequest from manager");
}

void FeedService::replyFinished(QString replyJson) {
  logger->info("replyFinished - got data from server");
  *articles = parser->parseFromStringToArticleVector(replyJson);
  logger->info("articles size " + QString(articles->size()));
  this->onReady(articles.data());
}


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
  connect(httpRequest.data(), SIGNAL(getReady(QJsonDocument)), this, SLOT(replyFinished(QJsonDocument)));
}

void FeedService::getFeed() {
  httpRequest->getRequest(Config::FEEDPATH);
  logger->info("getFeed - getrequest from manager");
}

void FeedService::replyFinished(QJsonDocument replyJson) {
  logger->info("replyFinished - got data from server");
  *articles = parser->parseFromDocumentToArticleVector(replyJson);
  logger->info("articles size " + QString(articles->size()));
  this->onReady(articles.data());
}


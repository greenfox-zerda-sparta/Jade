#include "FeedService.h"
#include <QNetworkRequest>
#include <QNetworkReply>


FeedService::FeedService() {
  manager = new QNetworkAccessManager(this);
  parser = new JsonParser;
  articles = new QVector<Article*>;
}

FeedService::~FeedService() {
  delete articles;
  delete parser;
  delete manager;
}

void FeedService::getFeed() {
  QUrl url("http://zerda-reader-mockback.gomix.me/feed");
  QNetworkRequest request = QNetworkRequest(url);
  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  manager->get(request);
}

void FeedService::replyFinished(QNetworkReply* reply) {
  *articles = parser->parseFromStringToArticleVector(reply->readAll());
  this->onReady(articles);
}
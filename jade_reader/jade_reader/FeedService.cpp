#include "FeedService.h"
#include "Config.h"
#include <QNetworkRequest>
#include <QNetworkReply>


FeedService::FeedService():
  manager(new QNetworkAccessManager(this)),
  parser(new JsonParser),
  articles(new QVector<Article*>) {}

FeedService::~FeedService() {}

void FeedService::getFeed() {
  QUrl url(Config::SERVERURL + Config::FEEDPATH);
  QNetworkRequest request = QNetworkRequest(url);
  connect(manager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  manager->get(request);
}

void FeedService::replyFinished(QNetworkReply* reply) {
  *articles = parser->parseFromStringToArticleVector(reply->readAll());
  this->onReady(articles.data());
}
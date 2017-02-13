#include "FeedService.h"
#include "Config.h"
#include <QNetworkRequest>
#include <QNetworkReply>


FeedService::FeedService():
  manager(new QNetworkAccessManager(this)),
  parser(new JsonParser),
  articles(new QVector<Article*>) {
  networkReply = NULL;
  QUrl url(Config::SERVERURL + Config::FEEDPATH);
  request = QNetworkRequest(url);
  connect(manager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

FeedService::~FeedService() {}

void FeedService::getFeed() {
  manager->get(request);
}

void FeedService::replyFinished(QNetworkReply* reply) {
  networkReply = reply;
  *articles = parser->parseFromStringToArticleVector(networkReply->readAll());
  networkReply->deleteLater();
  networkReply = NULL;
  this->onReady(articles.data());
}


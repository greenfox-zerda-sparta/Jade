#include "FeedService.h"
#include <QNetworkRequest>
#include <QNetworkReply>

FeedService::FeedService() {
  manager = new QNetworkAccessManager(this);
  reply = new QString;
}

FeedService::~FeedService() {
  delete reply;
  delete manager;
}

void FeedService::getFeed() {
  QUrl url("http://zerda-reader-mockback.gomix.me/feed");
  QNetworkRequest request = QNetworkRequest(url);
  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  manager->get(request);
}

void FeedService::replyFinished(QNetworkReply* reply) {
  *(this->reply) = reply->readAll();
  this->onReady(this->reply);
}
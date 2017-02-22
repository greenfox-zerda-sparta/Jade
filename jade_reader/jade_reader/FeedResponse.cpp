#include "FeedResponse.h"

FeedResponse::FeedResponse() {
  this->error = "";
}

QString FeedResponse::getError() {
  return error;
}

void FeedResponse::setError(QString error) {
  this->error = error;
}

QJsonArray FeedResponse::getFeed() {
  return feed;
}

void FeedResponse::setFeed(QJsonArray feed) {
  this->feed = feed;
}

bool FeedResponse::isError() {
  return error != "";
}
#include "Article.h"
#include "DateParser.h"

Article::Article() {}

Article::Article(Article* article) : id(article->getId()), title(article->getTitle()), description(article->getDescription()), created(article->getCreated()), feedName(article->getFeedName()), feedId(article->getFeedId()), favorite(article->getFavorite()), opened(article->getOpened()), url(article->getUrl()) {}

quint64 Article::getId() {
  return id;
}

void Article::setId(quint64 id) {
  this->id = id;
}

QString Article::getTitle() {
  return title;
}

void Article::setTitle(QString title) {
  this->title = title;
}

QString Article::getDescription() {
  return description;
}

void Article::setDescription(QString description) {
  this->description = description;
}

QString Article::getCreated() {
  return created;
}

void Article::setCreated(QString created) {
  this->created = created;
}

QString Article::getFeedName() {
  return feedName;
}

void Article::setFeedName(QString feedName) {
  this->feedName = feedName;
}

quint64 Article::getFeedId() {
  return feedId;
}

void Article::setFeedId(quint64 feedId) {
  this->feedId = feedId;
}

bool Article::getFavorite() {
  return favorite;
}

void Article::setFavorite(bool favorite) {
  this->favorite = favorite;
}

bool Article::getOpened() {
  return opened;
}

void Article::setOpened(bool opened) {
  this->opened = opened;
}

QString Article::getUrl() {
  return url;
}

void Article::setUrl(QString url) {
  this->url = url;
}

Article::Article(quint64 id, QString title, QString description, qint64 created, QString feedName, quint64 feedId, bool favorite, bool opened, QString url) {
  this->id = id;
  this->title = title;
  this->description = description;
  this->feedName = feedName;
  this->feedId = feedId;
  this->favorite = favorite;
  this->opened = opened;
  this->url = url;
  this->created = DateParser::parseDate(created);
}

Article::~Article() {}
#include "Article.h"
#include "DateParser.h"

Article::Article() {}

Article::Article(Article* article) : id(article->getId()), title(article->getTitle()), description(article->getDescription()), created(article->getCreated()), feed_name(article->getFeedName()), feed_id(article->getFeedId()), favorite(article->getFavorite()), opened(article->getOpened()), url(article->getUrl()) {}

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
  this->created = DateParser::parseDate(created.toInt());
}

QString Article::getFeedName() {
  return feed_name;
}

void Article::setFeedName(QString feedName) {
  this->feed_name = feedName;
}

quint64 Article::getFeedId() {
  return feed_id;
}

void Article::setFeedId(quint64 feedId) {
  this->feed_id = feedId;
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
  this->feed_name = feedName;
  this->feed_id = feedId;
  this->favorite = favorite;
  this->opened = opened;
  this->url = url;
  this->created = DateParser::parseDate(created);
}

Article::~Article() {}
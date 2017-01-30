#include "Article.h"
#include <QDateTime>
#include <QDebug>
#include <QLocale>

quint64 Article::getId() {
  return id;
}

QString Article::getTitle() {
  return title;
}

QString Article::getDescription() {
  return description;
}

QString Article::getCreated() {
  return created;
}

QString Article::getFeedName() {
  return feedName;
}

quint64 Article::getFeedId() {
  return feedId;
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

Article::Article(quint64 id, QString title, QString description, qint64 created, QString feedName, quint64 feedId, bool favorite, bool opened, QString url) {
  this->id = id;
  this->title = title;
  this->description = description;
  this->feedName = feedName;
  this->feedId = feedId;
  this->favorite = favorite;
  this->opened = opened;
  this->url = url;
  this->created = dateParser(created);
}

Article::~Article() {}

QString Article::dateParser(qint64 date) {
  QDateTime qdate;
  qdate.setMSecsSinceEpoch(date * 1000);
  QLocale us(QLocale::English, QLocale::UnitedStates);
  QString dateStringEnglish = us.toString(qdate, "MMMM d, yyyy");
  return dateStringEnglish;
}
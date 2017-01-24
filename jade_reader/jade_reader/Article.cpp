#include "Article.h"
#include "QDateTime"

QString Article::getTitle() {
  return title;
}

QString Article::getDescription() {
  return description;
}

QString Article::getCreated() {
  return created;
}

Article::Article(QString title, QString description, qint64 created) {
  this->title = title;
  this->description = description;
  this->created = dateParser(created);
}

Article::~Article() {}

QString Article::dateParser(qint64 date) {
  QDateTime time;
  time.setMSecsSinceEpoch(date * 1000);
  return time.toString("MMMM d, yyyy");
}
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
  QDateTime time;
  time.setMSecsSinceEpoch(created * 1000);
  this->created = time.toString("MMMM d, yyyy");
}

Article::~Article() {}
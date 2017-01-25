#include "Article.h"
#include <QDateTime>
#include <QDebug>
#include <QLocale>

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
  QDateTime qdate;
  qdate.setMSecsSinceEpoch(date * 1000);
  QLocale us(QLocale::English, QLocale::UnitedStates);
  QString dateStringEnglish = us.toString(qdate, "MMMM d, yyyy");
  return dateStringEnglish;
}
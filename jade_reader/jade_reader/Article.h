#pragma once
#include <QString>

class Article {
private:
  QString title;
  QString description;
  QString created;
public:
  QString getTitle();
  QString getDescription();
  QString getCreated();
  Article(QString title, QString description, qint64 created);
  ~Article();
};
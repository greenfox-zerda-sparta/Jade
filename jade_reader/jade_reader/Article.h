#pragma once
#include <QString>

class Article {
private:
  QString title;
  QString description;
public:
  QString getTitle();
  QString getDescription();
  Article(QString title, QString description);
  ~Article();
};
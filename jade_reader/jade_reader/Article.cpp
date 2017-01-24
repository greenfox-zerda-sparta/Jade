#include "Article.h"

QString Article::getTitle() {
  return title;
}

QString Article::getDescription() {
  return description;
}

Article::Article(QString title, QString description): title(title), description(description) {

}

Article::~Article() {}
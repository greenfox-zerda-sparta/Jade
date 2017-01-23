#include "Article.h"

QString Article::getImg() {
  return img;
}

QString Article::getTitle() {
  return title;
}

QString Article::getDescription() {
  return description;
}

Article::Article(QString img, QString title, QString description): img(img), title(title), description(description) {

}

Article::~Article() {}
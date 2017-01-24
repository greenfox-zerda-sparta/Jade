#include "testjson.h"
#include "JsonParser.h"

void TestJson::checkTitle() {
  QString content = "{\"feed\": [{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}]}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  QCOMPARE(articles[0]->getTitle(), QString("Fox on the Moon"));
}

void TestJson::checkDescription() {
  QString content = "{\"feed\": [{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}]}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  QCOMPARE(articles[0]->getDescription(), QString("This is the description"));
}

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

void TestJson::checkQVectorSizeWithoutArticle() {
  QString content = "{\"feed\": []}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  QCOMPARE(articles.length(), 0);
}

void TestJson::checkQVectorSizeForOneArticle() {
  QString content = "{\"feed\": [{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}]}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  QCOMPARE(articles.length(), 1);
}

void TestJson::checkQVectorSizeForThreeArticle() {
  QString content = "{\"feed\": [{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}, {\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}, {\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}]}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  QCOMPARE(articles.length(), 3);
}

void TestJson::checkQVectorSizeWithNotValidJson() {
  QString content = "{\"feed\": [{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}, {\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}]}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  QCOMPARE(articles.length(), 0);
}

void TestJson::checkQVectorSizeWithNotValidJsonKey() {
  QString content = "{\"news\": [{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}]}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  QCOMPARE(articles.length(), 0);
}

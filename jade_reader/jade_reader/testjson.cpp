#include "testjson.h"
#include "JsonParser.h"

void TestJson::checkDescription() {
  QString content = "{\"feed\": [{\"title\" : \"Fox on the Moon\", \"description\": \"This is the description\"}]}";
  JsonParser jsonParser;
  QVector<Article*> articles = jsonParser.parseFromStringToArticleVector(content);
  //QCOMPARE(articles[], QString("HELLO"));
}

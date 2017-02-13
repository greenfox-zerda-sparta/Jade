#include "JsonParser.h"
#include "Utils.h"

QVector<Article*> JsonParser::parseFromStringToArticleVector(QString content) {
  QVector<Article*> articles;
  QJsonObject jsonObject = parseToJsonObject(content);
  QJsonArray jsonArray = jsonObject["feed"].toArray();
  foreach(const QJsonValue & value, jsonArray) {
    Article*  article = (Article*)Utils::fromJson(&Article::staticMetaObject, value.toObject());
    articles.push_back(new Article(article));
  }
  return articles;
}

QString JsonParser::postLoginMessagetoJson(QString email, QString password) {
  QJsonObject jsonObject;
  jsonObject.insert("email", QJsonValue(email));
  jsonObject.insert("password", QJsonValue(password));
  QJsonDocument doc(jsonObject);
  return doc.toJson(QJsonDocument::Compact);
}

QJsonObject JsonParser::parseToJsonObject(QString input) {
  return QJsonDocument::fromJson(input.toLatin1()).object();
}
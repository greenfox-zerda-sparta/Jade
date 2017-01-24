#include "JsonParser.h"

JsonParser::JsonParser() {}

QVector<Article*> JsonParser::parseFromStringToArticleVector(QString content) {
  QVector<Article*> articles;
  QJsonParseError *error = Q_NULLPTR;
  QByteArray byteArray;
  byteArray.append(content);
  QJsonDocument jsonResponse = QJsonDocument::fromJson(byteArray, error);
  QJsonObject jsonObject = jsonResponse.object();
  QJsonArray jsonArray = jsonObject["feed"].toArray();
  foreach(const QJsonValue & value, jsonArray) {
    QJsonObject obj = value.toObject();
    QString title = obj["title"].toString();
    QString description = obj["description"].toString();
    qint64 created = obj["created"].toDouble();
    articles.push_back(new Article(title, description, created));
  }
  return articles;
}

JsonParser::~JsonParser() {}
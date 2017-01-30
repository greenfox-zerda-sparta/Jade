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
    quint64 id = obj["id"].toDouble();
    QString title = obj["title"].toString();
    QString description = obj["description"].toString();
    qint64 created = obj["created"].toDouble();
    QString feedName = obj["feed_name"].toString();
    quint64 feedId = obj["feed_id"].toDouble();
    bool favorite = obj["favorite"].toBool();
    bool opened = obj["opened"].toBool();
    QString url = obj["url"].toString();
    articles.push_back(new Article(id, title, description, created, feedName, feedId, favorite, opened, url));
  }
  return articles;
}

JsonParser::~JsonParser() {}
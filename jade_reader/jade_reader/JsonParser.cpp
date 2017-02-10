#include "JsonParser.h"

QVector<Article*> JsonParser::parseFromStringToArticleVector(QString content) {
  QVector<Article*> articles;
  QJsonObject jsonObject = parseToJsonObject(content);
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

QString JsonParser::postLoginMessagetoJson(QString email, QString password) {
  const QString emailKey = "email";
  QJsonValue emailValue(email);
  const QString passwordKey = "password";
  QJsonValue passwordValue(password);
  QJsonObject jsonObject;
  jsonObject.insert(emailKey, emailValue);
  jsonObject.insert(passwordKey, passwordValue);
  QJsonDocument doc(jsonObject);
  QString param(doc.toJson(QJsonDocument::Compact));
  return param;
}

QJsonObject JsonParser::parseToJsonObject(QString input) {
  QJsonParseError *error = Q_NULLPTR;
  QByteArray byteArray;
  byteArray.append(input);
  QJsonDocument jsonResponse = QJsonDocument::fromJson(byteArray, error);
  return jsonResponse.object();
}
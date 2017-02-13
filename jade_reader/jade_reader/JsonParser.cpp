#include "JsonParser.h"
#include "Utils.h"
#include <QDebug>

QVector<Article*> JsonParser::parseFromStringToArticleVector(QString content) {
  QVector<Article*> articles;
  QJsonObject jsonObject = parseToJsonObject(content);
  QJsonArray jsonArray = jsonObject["feed"].toArray();
  foreach(const QJsonValue & value, jsonArray) {
    QJsonObject obj = value.toObject();
    Article*  article = (Article*)Utils::fromJson(&Article::staticMetaObject, obj);
    articles.push_back(new Article(article));
    articles.push_back(article);
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
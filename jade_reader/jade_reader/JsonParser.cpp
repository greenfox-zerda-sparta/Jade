#include "JsonParser.h"

QJsonObject JsonParser::parseToJsonObject(QString input) {
  return QJsonDocument::fromJson(input.toLatin1()).object();
}

QObject* JsonParser::fromJsonObjectToMetaObject(const QMetaObject* meta, QJsonObject& jsonObject) {
  QObject* object = meta->newInstance();
  for (int i = 0; i < meta->propertyCount(); i++) {
    QMetaProperty property = meta->property(i);
    property.write(object, jsonObject.value(property.name()).toVariant());
  }
  return object;
}

QVector<Article*> JsonParser::parseFromStringToArticleVector(QString content) {
  QVector<Article*> articles;
  QJsonObject jsonObject = parseToJsonObject(content);
  QJsonArray jsonArray = jsonObject["feed"].toArray();
  foreach(const QJsonValue & value, jsonArray) {
    Article*  article = (Article*)fromJsonObjectToMetaObject(&Article::staticMetaObject, value.toObject());
    articles.push_back(new Article(article));
  }
  return articles;
}

QString JsonParser::toJson(const QMetaObject* meta) {
  QJsonObject jsonObject;
  for (int i = 0; i < meta->propertyCount(); i++) {
    QMetaProperty property = meta->property(i);
    jsonObject.insert(property.name(), QJsonValue(property.name()));
  } 
  QJsonDocument doc(jsonObject);
  return doc.toJson(QJsonDocument::Compact);
}
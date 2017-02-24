#include "JsonParser.h"
#include <QDebug>
#include "FileHandler.h"

QJsonObject JsonParser::parseToJsonObject(QString input) {
  return QJsonDocument::fromJson(input.toUtf8()).object();
}

QVector<Article*> JsonParser::parseFromObjectToArticleVector(QJsonObject content) {
  QVector<Article*> articles;
  QJsonArray jsonArray = content["feed"].toArray();
  foreach(const QJsonValue & value, jsonArray) {
    Article*  article = (Article*)fromJsonObjectToMetaObject(&Article::staticMetaObject, value.toObject());
    articles.push_back(new Article(article));
  }
  return articles;
}

QObject* JsonParser::fromJsonObjectToMetaObject(const QMetaObject* meta, QJsonObject& jsonObject) {
  QObject* object = meta->newInstance();
  for (int i = 0; i < meta->propertyCount(); i++) {
    QMetaProperty property = meta->property(i);
    property.write(object, jsonObject.value(property.name()).toVariant());
  }
  return object;
}

QJsonObject JsonParser::toJsonObject(QObject* object) {
  QJsonObject jsonObject;
  for (int i = 0; i < object->metaObject()->propertyCount(); i++) {
    QMetaProperty property = object->metaObject()->property(i);
    if (property.read(object) != "") {
      jsonObject.insert(property.name(), QJsonValue::fromVariant(property.read(object)));
    }
  }
  QJsonDocument doc(jsonObject);
  return doc.object();
}
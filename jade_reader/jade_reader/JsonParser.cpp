#include "JsonParser.h"
#include <QDebug>

QJsonObject JsonParser::parseToJsonObject(QString input) {
  return QJsonDocument::fromJson(input.toLatin1()).object();
}

QJsonDocument JsonParser::parseToJsonDocument(QString input) {
  return QJsonDocument::fromJson(input.toLatin1());
}

QVector<Article*> JsonParser::parseFromDocumentToArticleVector(QJsonDocument content) {
  QVector<Article*> articles;
  QJsonObject jsonObject = content.object();
  QJsonArray jsonArray = jsonObject["feed"].toArray();
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

QJsonDocument JsonParser::toJsonDocument(QObject* object) {
  QJsonObject jsonObject;
  for (int i = 0; i < object->metaObject()->propertyCount(); i++) {
    QMetaProperty property = object->metaObject()->property(i);
    if (property.read(object) != "") {
      jsonObject.insert(property.name(), QJsonValue::fromVariant(property.read(object)));
    }
  }
  QJsonDocument doc(jsonObject);
  return doc;
}
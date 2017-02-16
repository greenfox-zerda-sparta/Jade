#pragma once
#include "jade_reader.h"
#include "Article.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QMetaProperty>
#include <QObject>

class JsonParser {
public:
  static QJsonObject parseToJsonObject(QString input);
  QVector<Article*> parseFromObjectToArticleVector(QJsonObject content);
  QObject* fromJsonObjectToMetaObject(const QMetaObject* meta, QJsonObject& jsonObject);
  QJsonObject toJsonObject(QObject* object);
};
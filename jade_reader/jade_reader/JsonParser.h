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

class JsonParser {
public:
  QVector<Article*> parseFromStringToArticleVector(QString content);
  QString toJson(const QMetaObject* meta);
  QJsonObject parseToJsonObject(QString input);
  QObject* fromJsonObjectToMetaObject(const QMetaObject* meta, QJsonObject& jsonObject);
};
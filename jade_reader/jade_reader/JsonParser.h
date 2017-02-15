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
  QJsonObject parseToJsonObject(QString input);
  static QJsonDocument parseToJsonDocument(QString input);
  QVector<Article*> parseFromDocumentToArticleVector(QJsonDocument content);
  QObject* fromJsonObjectToMetaObject(const QMetaObject* meta, QJsonObject& jsonObject);
  QJsonDocument toJsonDocument(QObject* object);
};
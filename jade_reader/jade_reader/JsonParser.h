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
  QString postLoginMessagetoJson(QString email, QString password);
  QJsonObject parseToJsonObject(QString input);
  QObject* fromJson(const QMetaObject* meta, QJsonObject& jsonObject);
};
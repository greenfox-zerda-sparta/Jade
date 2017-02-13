#pragma once
#include <QObject>

class Utils {
public:
  static QObject* fromQStringJson(const QMetaObject& meta, QString& json);
  static QObject* fromJson(const QMetaObject* meta, QJsonObject& jsonObject);
};
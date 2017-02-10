#pragma once
#include <QObject>

class Utils {
public:
  Utils();
  ~Utils();
  static QObject* fromJson(const QMetaObject& meta, QString& json);
  static QObject* fromJson(const QMetaObject* meta, QJsonObject& jsonObject);
  static QVariant jsonValueToProperty(QObject* object, QMetaProperty& property, QJsonValue value);
};


#include "Utils.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaProperty>

QObject* Utils::fromQStringJson(const QMetaObject& meta, QString& json) {
  auto jsonObject = QJsonDocument::fromJson(json.toLatin1()).object();
  return fromJson(&meta, jsonObject);
}

QObject* Utils::fromJson(const QMetaObject* meta, QJsonObject& jsonObject) {
  QObject* object = meta->newInstance();
  for (int i = 0; i < meta->propertyCount(); i++) {
    QMetaProperty property = meta->property(i);
    property.write(object, jsonObject.value(property.name()).toVariant());
  }
  return object;
}

#include "Utils.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaProperty>
#include <QDebug>

Utils::Utils() {}
Utils::~Utils() {}

QObject* Utils::fromQStringJson(const QMetaObject& meta, QString& json) {
  auto jsonObject = QJsonDocument::fromJson(json.toLatin1()).object();
  return fromJson(&meta, jsonObject);
}

QObject* Utils::fromJson(const QMetaObject* meta, QJsonObject& jsonObject) {
  QObject* object = meta->newInstance();
  int propertyStart = QObject::staticMetaObject.propertyCount();
  for (int i = propertyStart; i < meta->propertyCount(); ++i) {
    QMetaProperty property = meta->property(i);
    auto value = jsonValueToProperty(object, property, jsonObject.value(property.name()));
    qDebug() << property.write(object, value);
  }
  return object;
}

QVariant Utils::jsonValueToProperty(QObject* object, QMetaProperty& property, QJsonValue value) {
  auto type = property.userType();
  auto typeName = QString(property.typeName());
  if (value.isArray()) {
    //todo array
  } else if (value.isObject()) {
    switch (type) {
      default:
      auto jsonObject = value.toObject();
      return QVariant::fromValue(fromJson(QMetaType::metaObjectForType(type), jsonObject));
      break;
    }
    //todo other meta object types
  } else {
    //primitive types
    return value.toVariant();
  }
}

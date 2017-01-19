#pragma once
#include "qt_json_4.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>

class JsonParser {
public:
  JsonParser();
  QStringList parseFromStringToQStringList(std::string);
  ~JsonParser();
};


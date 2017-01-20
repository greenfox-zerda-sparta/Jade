#pragma once
#include "jade_reader.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>

class JsonParser {
public:
	JsonParser();
	QStringList parseFromStringToQStringList(std::string, const char* key);
	~JsonParser();
};


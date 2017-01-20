#include "JsonParser.h"

JsonParser::JsonParser() {}

QStringList JsonParser::parseFromStringToQStringList(std::string content, const char* key) {
	QStringList titles;
	QJsonParseError *error = Q_NULLPTR;
	QByteArray byteArray(content.c_str(), content.length());
	QJsonDocument jsonResponse = QJsonDocument::fromJson(byteArray, error);
	QJsonObject jsonObject = jsonResponse.object();
	QJsonArray jsonArray = jsonObject["news"].toArray();
	foreach(const QJsonValue & value, jsonArray) {
		QJsonObject obj = value.toObject();
		titles.append(obj[key].toString());
	}
	return titles;
}

JsonParser::~JsonParser() {}

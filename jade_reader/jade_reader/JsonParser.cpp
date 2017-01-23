#include "JsonParser.h"

JsonParser::JsonParser() {}

std::vector <Article*> JsonParser::parseFromStringToArticleVector(std::string content) {
	std::vector <Article*> articles;
	QJsonParseError *error = Q_NULLPTR;
	QByteArray byteArray(content.c_str(), content.length());
	QJsonDocument jsonResponse = QJsonDocument::fromJson(byteArray, error);
	QJsonObject jsonObject = jsonResponse.object();
	QJsonArray jsonArray = jsonObject["news"].toArray();
	foreach(const QJsonValue & value, jsonArray) {
		QJsonObject obj = value.toObject();
		std::string img = obj["img"].toString().toUtf8().constData();
		std::string title = obj["title"].toString().toUtf8().constData();
		std::string description = obj["description"].toString().toUtf8().constData();
		articles.push_back(new Article(img, title, description));
	}
	return articles;
}

JsonParser::~JsonParser() {}

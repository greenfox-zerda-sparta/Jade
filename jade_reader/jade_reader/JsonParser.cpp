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
		QString img = obj["img"].toString();
		QString title = obj["title"].toString();
		QString description = obj["description"].toString();
		articles.push_back(new Article(img, title, description));
	}
	return articles;
}

JsonParser::~JsonParser() {}

#include "JsonParser.h"

JsonParser::JsonParser() {}

QVector <Article*> JsonParser::parseFromStringToArticleVector(QString content) {
	QVector <Article*> articles;
	QJsonParseError *error = Q_NULLPTR;
	QByteArray byteArray;
  byteArray.append(content);
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

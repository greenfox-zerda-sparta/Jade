#pragma once
#include "jade_reader.h"
#include "Article.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>
#include <vector>

class JsonParser {
public:
	JsonParser();
	std::vector <Article*> parseFromStringToArticleVector(std::string);
	~JsonParser();
};


#pragma once
#include <QString>

class Article {
private:
	QString img;
	QString title;
	QString description;
public:
	QString getImg();
	QString getTitle();
	QString getDescription();
	Article(QString img, QString title, QString description);
	~Article();
};


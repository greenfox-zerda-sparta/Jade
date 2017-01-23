#pragma once
#include "Article.h"
#include <QLabel>

class LabelCreator
{
public:
	LabelCreator();
	~LabelCreator();
	QLabel* createLabelFromArticle(Article*);
};


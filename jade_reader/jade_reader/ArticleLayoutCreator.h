#pragma once
#include "Article.h"
#include "ArticleLayout.h"


class ArticleLayoutCreator {
public:
  ArticleLayout* createLayout(Article*);
};
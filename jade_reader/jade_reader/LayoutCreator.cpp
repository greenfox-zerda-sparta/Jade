#include "LayoutCreator.h"

LayoutCreator::LayoutCreator() {}

LayoutCreator::~LayoutCreator() {}

ArticleLayout* LayoutCreator::createLayout(Article* article) {
  ArticleLayout* al = new ArticleLayout(article);
  return al;
}
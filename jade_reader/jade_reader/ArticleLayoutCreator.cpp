#include "ArticleLayoutCreator.h"

ArticleLayout* ArticleLayoutCreator::createLayout(Article* article) {
  ArticleLayout* al = new ArticleLayout(article);
  return al;
}
#include "testDateParser.h"
#include "Article.h"
#include "QDebug"

void TestDateParser::checkIfDateInEnglish() {
  Article article(2345525, "a", "b", 1485266405, "fn", 43673, false, true, "http://fox.com/moon");
  QString english = ("January 24, 2017");
  QCOMPARE(article.getCreated(), english);
}

void TestDateParser::checkArticleContents() {
  Article article(2345525, "a", "b", 1485266405, "fn", 43673, false, true, "http://fox.com/moon");
  quint64 id = 2345525;
  quint64 feedId = 43673;
  QCOMPARE(article.getId(), id);
  QCOMPARE(article.getTitle(), QString("a"));
  QCOMPARE(article.getDescription(), QString("b"));
  QCOMPARE(article.getFeedName(), QString("fn"));
  QCOMPARE(article.getFeedId(), feedId);
  QCOMPARE(article.getFavorite(), false);
  QCOMPARE(article.getOpened(), true);
  QCOMPARE(article.getUrl(), QString("http://fox.com/moon"));
}

void TestDateParser::checkSetters() {
  Article article(2345525, "a", "b", 1485266405, "fn", 43673, false, true, "http://fox.com/moon");
  article.setFavorite(true);
  article.setOpened(false);
  QCOMPARE(article.getFavorite(), true);
  QCOMPARE(article.getOpened(), false);
}
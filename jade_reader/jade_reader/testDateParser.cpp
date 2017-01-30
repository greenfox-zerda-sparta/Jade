#include "testDateParser.h"
#include "Article.h"
#include "QDebug"

void TestDateParser::checkIfDateInEnglish() {
  Article article("a", "b", 1485266405);
  QString english = ("January 24, 2017");
  QCOMPARE(article.getCreated(), english);
}
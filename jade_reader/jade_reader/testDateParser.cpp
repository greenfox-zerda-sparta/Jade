#include "testDateParser.h"
#include "Article.h"
#include "QDebug"

void TestDateParser::checkTest1() {
  Article article("a", "b", 1485266405);
  QString hungarian = QLatin1String("január 24, 2017");
  QString english = ("January 24, 2017");
  QVERIFY(article.getCreated() == hungarian || article.getCreated() == english);
}
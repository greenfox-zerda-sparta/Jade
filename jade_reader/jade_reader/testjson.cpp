#include "testjson.h"

void TestJson::toUpper() {
  QString str = "Hello";
  QCOMPARE(str.toUpper(), QString("HELLO"));
}

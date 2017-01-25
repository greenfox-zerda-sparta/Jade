#ifndef _TEST
#include "Application.h"
#include "Logger.h"
#include <iostream>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Application application;
  application.run();  
  return app.exec();
}
#endif

#ifdef _TEST
#include <QtTest/QtTest>
#include "testjson.h"
#include "testDateParser.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  TestJson testJson;
  TestDateParser testDateParser;
  QTest::qExec(&testJson, argc, argv);
  QTest::qExec(&testDateParser, argc, argv);
  return 0;
}
#endif
#ifndef _TEST
#include "Application.h"

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

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  TestJson testJson;
  return QTest::qExec(&testJson, argc, argv);
}
#endif
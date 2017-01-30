#ifndef TESTLOGGER_H
#define TESTLOGGER_H

#include <QObject>
#include <QtTest/QtTest>
#include <QTextStream>
#include <QString>

class TestLogger: public QObject {
  Q_OBJECT
private:
  QString* buffer;
  QString* buffer2;
  QTextStream* mockCout;
  QTextStream* mockCerr;
private slots:
  void init();
  void cleanup();
  void whenInfoMessageIsEmpty();
  void whenInfoMessageIsReallyLong();
  void whenInfoMessageHasLineBreak();
  void whenLogLevelIsDebug();
  void whenLogLevelIsInfo();
  void whenLogLevelIsWarn();
  void whenLogLevelIsError();
};

#endif
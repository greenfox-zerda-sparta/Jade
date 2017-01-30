#ifndef TESTLOGGER_H
#define TESTLOGGER_H

#include <QObject>
#include <QtTest/QtTest>

class TestLogger : public QObject {
  Q_OBJECT
public:
  private slots :
    void whenInfoMessageIsEmpty();
    void whenInfoMessageIsReallyLong();
    void whenInfoMessageHasLineBreak();
    void whenLogLevelIsDebug();
    void whenLogLevelIsInfo();
    void whenLogLevelIsWarn();
    void whenLogLevelIsError();
};

#endif
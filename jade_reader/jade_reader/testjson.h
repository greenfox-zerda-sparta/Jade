#ifndef TESTJSON_H
#define TESTJSON_H

#include <QObject>
#include <QtTest/QtTest>

class TestJson : public QObject {
  Q_OBJECT
public:
  private slots :
    void checkTitle();
    void checkDescription();
};

#endif // TESTJSON_H

#ifndef TESTDATEPARSER_H
#define TESTDATEPARSER_H

#include <QObject>
#include <QtTest/QtTest>

class TestDateParser : public QObject {
  Q_OBJECT
public:
private slots :
  void checkIfDateInEnglish();
  void checkArticleContents();
  void checkSetters();
};

#endif
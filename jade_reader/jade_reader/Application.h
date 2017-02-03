#pragma once
#include "FileReader.h"
#include "JsonParser.h"
#include <QApplication>

class Application : public QApplication{
Q_OBJECT
private:
  FileReader* fileReader;
  JsonParser* jsonParser;
  QString content;
  QVector<Article*> articles;
public:
  Application(int argc, char* argv[]);
  ~Application();
  void run();
};
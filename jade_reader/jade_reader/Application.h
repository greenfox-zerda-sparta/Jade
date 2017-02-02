#pragma once
#include "FileReader.h"
#include "JsonParser.h"

class Application {
private:
  FileReader* fileReader;
  JsonParser* jsonParser;
  QString content;
  QVector<Article*> articles;
public:
  Application();
  ~Application();
  void run();
};
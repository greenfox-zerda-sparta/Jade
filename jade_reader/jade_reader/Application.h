#pragma once
#include "FileReader.h"
#include "JsonParser.h"
#include "LayoutCreator.h"

class Application {
private:
  QWidget* window;
  FileReader* fileReader;
  JsonParser* jsonParser;
  QVBoxLayout* mainLayout;
  LayoutCreator* layoutCreator;
  QString content;
  QVector <Article*> articles;
public:
  Application();
  ~Application();
  void run();
  void draw();
};
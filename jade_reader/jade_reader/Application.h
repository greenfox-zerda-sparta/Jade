#pragma once
#include "FileReader.h"
#include "JsonParser.h"
#include "LayoutCreator.h"
#include "UserLoginWindow.h"

class Application {
private:
  QWidget* window;
  FileReader* fileReader;
  JsonParser* jsonParser;
  QVBoxLayout* mainLayout;
  LayoutCreator* layoutCreator;
  UserLoginWindow* userLoginWindow;
  QString content;
  QVector <Article*> articles;
public:
  Application();
  ~Application();
  void run();
  void draw();
};
#pragma once
#include "FileReader.h"
#include "JsonParser.h"
#include "LayoutCreator.h"
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qscrollbar.h>
#include <QtWidgets/qsizepolicy.h>

class Application {
private:
  QWidget* window;
  QScrollArea* scrollarea;
  QScrollBar* scrollbar;
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
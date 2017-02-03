#pragma once
#include "FileReader.h"
#include "JsonParser.h"
#include "LayoutCreator.h"
#include "RequestManager.h"
#include <QApplication>

class Application : public QApplication {
  Q_OBJECT
private:
  RequestManager* manager;
  QWidget* window;
  FileReader* fileReader;
  JsonParser* jsonParser;
  QVBoxLayout* mainLayout;
  LayoutCreator* layoutCreator;
  QString content;
  QVector <Article*> articles;
public:
  Application(int argc, char* argv[]);
  ~Application();
  void run();
  void draw();
private slots:
  void readFile();
};
#include "Application.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QtGui>
#include "Logger.h"
#include <iostream>

Application::Application() {
  window = new QWidget();
  fileReader = new FileReader;
  jsonParser = new JsonParser;
  mainLayout = new QVBoxLayout(window);
  layoutCreator = new LayoutCreator;
  content = "";
}

Application::~Application() {
  delete layoutCreator;
  delete fileReader;
  delete jsonParser;
  delete mainLayout;
  delete window;
}

void Application::run() {
  content = fileReader->readFromFileToQString("test.json");
  articles = jsonParser->parseFromStringToArticleVector(content);
  draw();
  Logger logger("Application");
  logger.warn("alma");
  QString* stream = new QString;
  *stream = "kortefa";
  Logger logger2("Main", stream);
  logger2.debug("NYEEEEEEEEEE");
  std::cout << stream->toStdString() << "alma";
}

void Application::draw() {
  mainLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    mainLayout->addLayout(layoutCreator->createLayout(articles[i]), 50);
  }
  window->show();
}
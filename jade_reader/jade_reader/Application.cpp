#include "Application.h"
#include "Logger.h"
#include "LogLevelProvider.h"

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
  Logger logger("Application", LogLevelProvider::getLogLevel());
  logger.info("alma");
}

void Application::draw() {
  mainLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    mainLayout->addLayout(layoutCreator->createLayout(articles[i]), 50);
  }
  window->show();
}
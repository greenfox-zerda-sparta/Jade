#include "Application.h"
#include "Logger.h"
#include "LogLevelProvider.h"


Application::Application() {
  window = new QWidget();
  scrollarea = new QScrollArea();
  fileReader = new FileReader;
  jsonParser = new JsonParser;
  mainLayout = new QVBoxLayout(window);
  layoutCreator = new LayoutCreator;
  
}

Application::~Application() {
  delete layoutCreator;
  delete fileReader;
  delete jsonParser;
  delete mainLayout;
  delete scrollarea;
  delete window;
}

void Application::run() {
  content = fileReader->readFromFileToQString("test.json");
  articles = jsonParser->parseFromStringToArticleVector(content);
  draw();
  LogLevelProvider logLevelProvider;
  Logger logger("Application", logLevelProvider.getLogLevel());
  logger.info("alma");
}

void Application::draw() {
  mainLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    mainLayout->addLayout(layoutCreator->createLayout(articles[i])->layout, 50);
  }
  scrollarea->setWidgetResizable(true);
  scrollarea->setWidget(window);
  scrollarea->show();
}
#include "Application.h"
#include "Logger.h"
#include "LogLevelProvider.h"

Application::Application(int argc, char* argv[]) : QApplication(argc, argv) {
  manager = new RequestManager;
  window = new QWidget();
  fileReader = new FileReader;
  jsonParser = new JsonParser;
  mainLayout = new QVBoxLayout(window);
  layoutCreator = new LayoutCreator;
  content = "";
  connect(manager, SIGNAL(onReady()), this, SLOT(readFile()));
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
  LogLevelProvider logLevelProvider;
  Logger logger("Application", logLevelProvider.getLogLevel());
  logger.info("alma");
  QString email = "bogi@reader.com";
  QString pw = "bogi";
  manager->postLogin(email, pw);

}

void Application::draw() {
  mainLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    mainLayout->addLayout(layoutCreator->createLayout(articles[i]), 50);
  }
  window->show();
}

void Application::readFile() {
  qDebug() << manager->pReply;
}
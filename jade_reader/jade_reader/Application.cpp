#include "Application.h"
#include "FeedWindow.h"


Application::Application(int argc, char* argv[]) : QApplication(argc, argv) {
  fileReader = new FileReader;
  jsonParser = new JsonParser;  
}

Application::~Application() {
  delete fileReader;
  delete jsonParser;
}

void Application::run() {
  content = fileReader->readFromFileToQString("test.json");
  articles = jsonParser->parseFromStringToArticleVector(content);
  FeedWindow* feedWindow = new FeedWindow;
  feedWindow->createWindow(articles);
  feedWindow->show();
}

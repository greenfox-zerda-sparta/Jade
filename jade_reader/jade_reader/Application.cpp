#include "Application.h"
#include "ScreenManager.h"

Application::Application(int argc, char* argv[]) : 
  QApplication(argc, argv),
  loginScreenWidget(new UserLoginScreen),
  signUpScreenWidget(new UserSignUpScreen),
  feedScreen(new FeedWindow),
  screenManager(new ScreenManager(loginScreenWidget.data(), signUpScreenWidget.data(), feedScreen.data())),
  fileReader(new FileReader),
  jsonParser(new JsonParser) {
}

void Application::run() {
  content = fileReader->readFromFileToQString("test.json");
  articles = jsonParser->parseFromStringToArticleVector(content);
  feedScreen->createWindow(articles);
  screenManager->refreshFeedScreen(feedScreen.data());
  screenManager->show();
}

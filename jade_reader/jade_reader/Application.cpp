#include "Application.h"
#include "ScreenManager.h"

Application::Application(int argc, char* argv[]) : QApplication(argc, argv) {
  loginScreenWidget = new UserLoginScreen;
  signUpScreenWidget = new UserSignUpScreen;
  feedScreen = new FeedWindow;
  screenManager = new ScreenManager(loginScreenWidget, signUpScreenWidget, feedScreen);
  fileReader = new FileReader;
  jsonParser = new JsonParser;
}

Application::~Application() {
  delete loginScreenWidget;
  delete signUpScreenWidget;
  delete feedScreen;
  delete fileReader;
  delete jsonParser;
}

void Application::run() {
  screenManager->show();
}

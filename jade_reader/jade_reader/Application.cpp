#include "Application.h"
#include "ScreenManager.h"

Application::Application(int argc, char* argv[]) : 
  QApplication(argc, argv),
  screenManager(new ScreenManager(new UserLoginScreen, new UserSignUpScreen, new FeedWindow)),
  fileReader(new FileReader),
  jsonParser(new JsonParser) {
}

void Application::run() {
  screenManager->show();
}

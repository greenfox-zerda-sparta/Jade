#include "Application.h"

Application::Application(int argc, char* argv[]) : 
  QApplication(argc, argv),
  screenManager(new ScreenManager(new UserLoginScreen, new UserSignUpScreen, new FeedWindow)) {
}

void Application::run() {
  screenManager->show();
}

#include "Application.h"

Application::Application(int argc, char* argv[]): QApplication(argc, argv),
screenManager(new ScreenManager),
httpRequest(new HttpRequest),
authServ(new AuthenticationService(httpRequest)) {}

Application::~Application() {
  screenManager->deleteLater();
}

void Application::run() {
  if (authServ->isAuthenticated()) {
    screenManager->fetchFeed();
  } else {
    screenManager->showLoginScreen();
  }
  screenManager->show();
}
#include "Application.h"
#include "ScreenManager.h"

Application::Application(int argc, char* argv[]) : QApplication(argc, argv),
  screenManager(new ScreenManager)
  {}

Application::~Application() {
  screenManager->deleteLater();
}

void Application::run() {
  screenManager->show();
}

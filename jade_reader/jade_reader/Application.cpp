#include "Application.h"
#include "ScreenManager.h"

Application::Application(int argc, char* argv[]) : QApplication(argc, argv),
  screenManager(new ScreenManager)
  {}

/*Application::~Application() {
  //delete screenManager;
}*/

void Application::run() {
  screenManager->show();
}

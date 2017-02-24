#pragma once
#include "ScreenManager.h"
#include <QApplication>
#include "AuthenticationService.h"
#include <QSharedPointer>

class Application: public QApplication {
  Q_OBJECT
private:
  ScreenManager* screenManager;
  QSharedPointer<HttpRequest> httpRequest;
  QSharedPointer<AuthenticationService> authServ;
public:
  Application(int argc, char* argv[]);
  ~Application();
  void run();
};
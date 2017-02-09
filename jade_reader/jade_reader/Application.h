#pragma once
#include "FileReader.h"
#include "JsonParser.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "FeedWindow.h"
#include "ScreenManager.h"
#include <QApplication>
#include <QScopedPointer>

class Application : public QApplication{
Q_OBJECT
private:
  QScopedPointer<ScreenManager> screenManager;
public:
  Application(int argc, char* argv[]);
  //~Application();
  void run();
};
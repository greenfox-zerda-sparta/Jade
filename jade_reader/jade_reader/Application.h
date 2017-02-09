#pragma once
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "FeedWindow.h"
#include "ScreenManager.h"
#include <QApplication>
#include <QScopedPointer>

class Application : public QApplication{
Q_OBJECT
private:
  QString content;
  QVector<Article*> articles;
  ScreenManager* screenManager;
public:
  Application(int argc, char* argv[]);
  ~Application();
  void run();
};
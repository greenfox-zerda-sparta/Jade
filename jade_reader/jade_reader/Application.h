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
  QString content;
  QVector<Article*> articles;
  QScopedPointer<FileReader> fileReader;
  QScopedPointer<JsonParser> jsonParser;
  QScopedPointer<ScreenManager> screenManager;
public:
  Application(int argc, char* argv[]);
  void run();
};
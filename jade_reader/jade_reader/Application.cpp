#include "Application.h"
#include "ScreenManager.h"
#include "Article.h"
#include "Utils.h"
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>

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
  QString json = "{\"title\" : \"alma\"}";
  Article*  article = (Article*)Utils::fromJson(Article::staticMetaObject, json);
  const QMetaObject* metaObject = article->metaObject();
  QStringList properties;
  qDebug() << metaObject->propertyCount();
  qDebug() << metaObject->className();
  for (int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i) {
    properties << QString::fromLatin1(metaObject->property(i).name());
    qDebug() << QString::fromLatin1(metaObject->property(i).name());
  }  
  screenManager->show();
}

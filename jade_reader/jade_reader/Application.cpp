#include "Application.h"
#include "Utils.h"
#include "JsonParser.h"
#include <QMetaProperty>
#include <QJsonObject>
#include <QVariant>

Application::Application(int argc, char* argv[]): QApplication(argc, argv),
screenManager(new ScreenManager) {}

Application::~Application() {
  screenManager->deleteLater();
}

void Application::run() {
  QString json = "{\"title\" : \"alma\", \"id\" : \"1\"}";
  Article*  article = (Article*)Utils::fromQStringJson(Article::staticMetaObject, json);
  qDebug() << article->getTitle();
  qDebug() << article->getId();
  screenManager->show();
}

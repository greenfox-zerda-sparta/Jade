#include "Application.h"
#include "Utils.h"
#include <QMetaProperty>

Application::Application(int argc, char* argv[]): QApplication(argc, argv),
screenManager(new ScreenManager) {}

Application::~Application() {
  screenManager->deleteLater();
}

void Application::run() {
  QString json = "{\"title\" : \"alma\"}";
  //Article*  article = (Article*)Utils::fromJson(Article::staticMetaObject, json);
  Article*  article = new Article;
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

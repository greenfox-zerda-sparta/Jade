#include "RequestManager.h"
#include <QEventLoop>
#include <QNetworkRequest>
#include <QNetworkReply>

RequestManager::RequestManager() {
  manager = new QNetworkAccessManager;
}

QString RequestManager::getFeed(QString url) {
  QNetworkRequest request = QNetworkRequest(QUrl(url));
  QEventLoop eventLoop;

  connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
  reply = manager->get(request);

  eventLoop.exec();
  return reply->readAll();
}

QString RequestManager::postLogin(QString _email, QString _password) {
  QUrl url("http://zerda-reader-mockback.gomix.me/user/login");
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QString param = "{\"email\":\"";
  param += _email;
  param += "\",\"password\":\"";
  param += _password;
  param += "\"}";
  QEventLoop eventLoop;

  connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
  reply = manager->post(request, param.toUtf8());

  eventLoop.exec();
  return reply->readAll();
}

QString RequestManager::postSignup(QString _email, QString _password) {
  QUrl url("http://zerda-reader-mockback.gomix.me/user/signup");
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QString param = "{\"email\":\"";
  param += _email;
  param += "\",\"password\":\"";
  param += _password;
  param += "\"}";
  QEventLoop eventLoop;

  connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
  reply = manager->post(request, param.toUtf8());

  eventLoop.exec();
  return reply->readAll();
}

RequestManager::~RequestManager() {
  delete manager;
}
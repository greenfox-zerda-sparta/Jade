#include "RequestManager.h"
#include <QEventLoop>
#include <QNetworkRequest>
#include <QNetworkReply>

RequestManager::RequestManager() {
  manager = new QNetworkAccessManager;
}

QString RequestManager::postRequest(QString _url, QString _email, QString _password) {
  QUrl url(_url);
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

QString RequestManager::getFeed() {
  QUrl url("http://zerda-reader-mockback.gomix.me/feed");
  QNetworkRequest request = QNetworkRequest(url);
  QEventLoop eventLoop;

  connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
  reply = manager->get(request);

  eventLoop.exec();
  return reply->readAll();
}

QString RequestManager::postLogin(QString _email, QString _password) {
  return postRequest("http://zerda-reader-mockback.gomix.me/user/login", _email, _password);
}

QString RequestManager::postSignup(QString _email, QString _password) {
  return postRequest("http://zerda-reader-mockback.gomix.me/user/signup", _email, _password);
}

RequestManager::~RequestManager() {
  delete manager;
}
#include "RequestManager.h"
#include <QEventLoop>
#include <QNetworkRequest>
#include <QNetworkReply>

RequestManager::RequestManager() {
  manager = new QNetworkAccessManager(this);
}

void RequestManager::postRequest(QString _url, QString _email, QString _password) {
  QUrl url(_url);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QString param = "{\"email\":\"";
  param += _email;
  param += "\",\"password\":\"";
  param += _password;
  param += "\"}";
  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  reply = manager->post(request, param.toUtf8());
}

void RequestManager::getFeed() {
  QUrl url("http://zerda-reader-mockback.gomix.me/feed");
  QNetworkRequest request = QNetworkRequest(url);

  connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  reply = manager->get(request);
}

void RequestManager::postLogin(QString _email, QString _password) {
  postRequest("http://zerda-reader-mockback.gomix.me/user/login", _email, _password);
}

void RequestManager::postSignup(QString _email, QString _password) {
  postRequest("http://zerda-reader-mockback.gomix.me/user/signup", _email, _password);
}

RequestManager::~RequestManager() {
  delete manager;
}

void RequestManager::replyFinished(QNetworkReply* reply) {
  pReply =  reply->readAll();
  onReady();
}
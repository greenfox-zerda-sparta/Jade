#include "AuthenticationService.h"
#include <QNetworkRequest>
#include <QNetworkReply>

AuthenticationService::AuthenticationService() : 
  logger(new Logger("AuthenticationService")),
  manager(new QNetworkAccessManager(this)),
  jsonParser(new JsonParser) {
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  postRequest("http://zerda-reader-mockback.gomix.me/user/login", _email, _password);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  postRequest("http://zerda-reader-mockback.gomix.me/user/signup", _email, _password);
}

void AuthenticationService::postRequest(QString _url, QString _email, QString _password) {
  QUrl url(_url);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QString param = jsonParser->postLoginMessagetoJson(_email, _password);
  connect(manager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  manager->post(request, param.toUtf8());
}

void AuthenticationService::getResult(QJsonObject& jsonObject) {
  QString result = jsonObject["result"].toString();
  if (result == "fail") {
    logger->error("Failed to sign in.");
  } else {
    logger->info("Success");
    token = jsonObject["token"].toString();
    logger->info(token.toUtf8());
  }
}

void AuthenticationService::replyFinished(QNetworkReply* reply) {
  pReply = reply->readAll();
  logger->info(pReply.toUtf8());
  getResult(jsonParser->parseToJsonObject(pReply));
}
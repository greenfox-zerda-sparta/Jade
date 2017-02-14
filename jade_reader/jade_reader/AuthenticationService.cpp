#include "AuthenticationService.h"
#include "Config.h"
#include <QNetworkRequest>
#include <QNetworkReply>

AuthenticationService::AuthenticationService() : 
  logger(new Logger("AuthenticationService")),
  jsonParser(new JsonParser) {
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  postRequest(Config::SERVERURL + Config::LOGINPATH, _email, _password);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  postRequest(Config::SERVERURL + Config::SIGNUPPATH, _email, _password);
}

void AuthenticationService::postRequest(QString _url, QString _email, QString _password) {
  QUrl url(_url);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QString param = jsonParser->postLoginMessagetoJson(_email, _password);
  connect(HttpRequest::networkAccessManager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyAuthenticationFinished(QNetworkReply*)));
  HttpRequest::networkAccessManager->post(request, param.toUtf8());
}

void AuthenticationService::getResult(QJsonObject& jsonObject) {
  QString result = jsonObject["result"].toString();
  if (result == "fail") {
    logger->error("Failed: " + jsonObject["message"].toString().toUtf8());
  } else {
    logger->info("Success");
    token = jsonObject["token"].toString();
  }
}

void AuthenticationService::replyAuthenticationFinished(QNetworkReply* reply) {
  this->reply = reply->readAll();
  logger->info(this->reply.toUtf8());
  getResult(jsonParser->parseToJsonObject(this->reply));
}
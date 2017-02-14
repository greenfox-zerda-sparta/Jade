#include "AuthenticationService.h"
#include "Config.h"
#include <QNetworkRequest>
#include <QNetworkReply>

AuthenticationService::AuthenticationService(QSharedPointer<HttpRequest> httpRequest) :
  logger(new Logger("AuthenticationService")),
  jsonParser(new JsonParser),
  httpRequest(httpRequest) {
  connect(httpRequest.data(), SIGNAL(postReady(QString)), this, SLOT(replyAuthenticationFinished(QString)));
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  QString param = jsonParser->postLoginMessagetoJson(_email, _password);
  httpRequest->postRequest(Config::SERVERURL + Config::LOGINPATH, param);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  QString param = jsonParser->postLoginMessagetoJson(_email, _password);
  httpRequest->postRequest(Config::SERVERURL + Config::SIGNUPPATH, param);
}

//void AuthenticationService::postRequest(QString _url, QString _email, QString _password) {
//  QUrl url(_url);
//  QNetworkRequest request = QNetworkRequest(url);
//  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
//  QString param = jsonParser->postLoginMessagetoJson(_email, _password);
//  connect(HttpRequest::networkAccessManager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyAuthenticationFinished(QNetworkReply*)));
//  HttpRequest::networkAccessManager->post(request, param.toUtf8());
//}

void AuthenticationService::getResult(QJsonObject& jsonObject) {
  QString result = jsonObject["result"].toString();
  if (result == "fail") {
    logger->error("Failed: " + jsonObject["message"].toString().toUtf8());
  } else {
    logger->info("Success");
    token = jsonObject["token"].toString();
  }
}

void AuthenticationService::replyAuthenticationFinished(QString replyJson) {
  logger->info(replyJson.toUtf8());
  getResult(jsonParser->parseToJsonObject(replyJson));
}
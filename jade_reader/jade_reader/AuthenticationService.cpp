#include "AuthenticationService.h"
#include "Config.h"
#include "PostData.h"
#include "AuthResponse.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonDocument>

bool AuthenticationService::isSuccess(QString result) {
  return result == "success";
}

AuthenticationService::AuthenticationService(QSharedPointer<HttpRequest> httpRequest) :
  logger(new Logger("AuthenticationService")),
  jsonParser(new JsonParser),
  httpRequest(httpRequest) {
  connect(httpRequest.data(), SIGNAL(postReady(QJsonDocument)), this, SLOT(replyAuthenticationFinished(QJsonDocument)));
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  PostData* postData = new PostData(_email, _password);
  QJsonDocument json = jsonParser->toJsonDocument((QObject*)postData);
  httpRequest->postRequest(Config::SERVERURL + Config::LOGINPATH, json);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  PostData* postData = new PostData(_email, _password);
  QJsonDocument json = jsonParser->toJsonDocument((QObject*)postData);
  httpRequest->postRequest(Config::SERVERURL + Config::SIGNUPPATH, json);
}

void AuthenticationService::getResult(QJsonObject& jsonObject) {
  AuthResponse*  authResponse = (AuthResponse*)jsonParser->fromJsonObjectToMetaObject(&AuthResponse::staticMetaObject, jsonObject);
  if (!isSuccess(authResponse->getResult())) {
    logger->error("Failed: " + authResponse->getMessage().toUtf8());
  } else {
    logger->info("Success");
    token = authResponse->getToken();
  }
}

void AuthenticationService::replyAuthenticationFinished(QJsonDocument replyJson) {
  getResult(replyJson.object());
}
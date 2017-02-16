#include "AuthenticationService.h"
#include "Config.h"
#include "PostData.h"
#include "AuthResponse.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonObject>

bool AuthenticationService::isSuccess(QString result) {
  return result == "success";
}

AuthenticationService::AuthenticationService(QSharedPointer<HttpRequest> httpRequest) :
  logger(new Logger("AuthenticationService")),
  jsonParser(new JsonParser),
  httpRequest(httpRequest) {
  connect(httpRequest.data(), SIGNAL(postReady(QJsonObject)), this, SLOT(replyAuthenticationFinished(QJsonObject)));
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  PostData* postData = new PostData(_email, _password);
  QJsonObject json = jsonParser->toJsonObject((QObject*)postData);
  httpRequest->postRequest(Config::LOGINPATH, json);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  PostData* postData = new PostData(_email, _password);
  QJsonObject json = jsonParser->toJsonObject((QObject*)postData);
  httpRequest->postRequest(Config::SIGNUPPATH, json);
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

void AuthenticationService::replyAuthenticationFinished(QJsonObject replyJson) {
  getResult(replyJson);
}
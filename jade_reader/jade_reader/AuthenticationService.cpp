#include "AuthenticationService.h"
#include "Config.h"
#include "PostData.h"
#include "AuthResponse.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>

bool AuthenticationService::isSuccess(QString result) {
  return result == "success";
}

AuthenticationService::AuthenticationService(QSharedPointer<HttpRequest> httpRequest) :
  logger(new Logger("AuthenticationService")),
  jsonParser(new JsonParser),
  httpRequest(httpRequest) {
  connect(this, SIGNAL(postRequest(QString, QString)), httpRequest.data(), SLOT(postRequest(QString, QString)));
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  PostData* postData = new PostData(_email, _password);
  QString param = jsonParser->toJson((QObject*)postData);
  postRequest(Config::SERVERURL + Config::LOGINPATH, param);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  PostData* postData = new PostData(_email, _password);
  QString param = jsonParser->toJson((QObject*)postData);
  postRequest(Config::SERVERURL + Config::SIGNUPPATH, param);
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

void AuthenticationService::replyReady(QString replyJson) {
  logger->info(replyJson.toUtf8());
  getResult(jsonParser->parseToJsonObject(replyJson));
  disconnect(httpRequest.data(), SIGNAL(replyReady(QString)), this, SLOT(replyReady(QString)));
}
#include "AuthenticationService.h"
#include "Config.h"
#include "PostData.h"
#include "AuthResponse.h"
#include "FileHandler.h"
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
  connect(this, SIGNAL(postRequest(QString, QJsonObject)), httpRequest.data(), SLOT(postRequest(QString, QJsonObject)));
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  PostData* postData = new PostData(_email, _password);
  QJsonObject json = jsonParser->toJsonObject((QObject*)postData);
  postRequest(Config::LOGINPATH, json);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  PostData* postData = new PostData(_email, _password);
  QJsonObject json = jsonParser->toJsonObject((QObject*)postData);
  postRequest(Config::SIGNUPPATH, json);
}

void AuthenticationService::getResult(QJsonObject& jsonObject) {
  AuthResponse*  authResponse = (AuthResponse*)jsonParser->fromJsonObjectToMetaObject(&AuthResponse::staticMetaObject, jsonObject);
  if (!isSuccess(authResponse->getResult())) {
    logger->error("Failed: " + authResponse->getMessage().toUtf8());
  } else {
    logger->info("Success");
    token = authResponse->getToken();
    FileHandler::writeToFile(token, "token.txt");
  }
}

void AuthenticationService::replyReady(QJsonObject replyJson) {
  getResult(replyJson);
  disconnect(httpRequest.data(), SIGNAL(replyReady(QJsonObject)), this, SLOT(replyReady(QJsonObject)));
}
#include "AuthenticationService.h"
#include "Config.h"
#include "PostData.h"
#include "AuthResponse.h"
#include "FileHandler.h"
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
  connect(httpRequest.data(), SIGNAL(postReady(QString)), this, SLOT(replyAuthenticationFinished(QString)));
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  PostData* postData = new PostData(_email, _password);
  QString param = jsonParser->toJson((QObject*)postData);
  httpRequest->postRequest(Config::SERVERURL + Config::LOGINPATH, param);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  PostData* postData = new PostData(_email, _password);
  QString param = jsonParser->toJson((QObject*)postData);
  httpRequest->postRequest(Config::SERVERURL + Config::SIGNUPPATH, param);
}

void AuthenticationService::getResult(QJsonObject& jsonObject) {
  AuthResponse*  authResponse = (AuthResponse*)jsonParser->fromJsonObjectToMetaObject(&AuthResponse::staticMetaObject, jsonObject);
  if (!isSuccess(authResponse->getResult())) {
    logger->error("Failed: " + authResponse->getMessage().toUtf8());
  } else {
    logger->info("Success");
    token = authResponse->getToken();
    FileHandler fileHandler;
    fileHandler.writeToFile("token", "token.txt");
  }
}

void AuthenticationService::replyAuthenticationFinished(QString replyJson) {
  logger->info(replyJson.toUtf8());
  getResult(jsonParser->parseToJsonObject(replyJson));
}
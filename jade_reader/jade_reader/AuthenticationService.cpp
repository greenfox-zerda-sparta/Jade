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
  connect(httpRequest.data(), SIGNAL(postReady(QString)), this, SLOT(replyAuthenticationFinished(QString)));
}

void AuthenticationService::postLogin(QString _email, QString _password) {
  logger->info("post Login");
  QString param = jsonParser->postLoginMessagetoJson(_email, _password);
  httpRequest->postRequest(Config::SERVERURL + Config::LOGINPATH, param);
}

void AuthenticationService::postSignup(QString _email, QString _password) {
  logger->info("post Sign Up");
  postRequest(Config::SERVERURL + Config::SIGNUPPATH, _email, _password);
}

void AuthenticationService::postRequest(QString _url, QString _email, QString _password) {
  QUrl url(_url);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  PostData* postData = new PostData(_email, _password);
  QString param = jsonParser->toJson((QObject*)postData);
  logger->info(param.toUtf8());
  connect(manager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
  manager->post(request, param.toUtf8());
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
  }
}

void AuthenticationService::replyAuthenticationFinished(QString replyJson) {
  logger->info(replyJson.toUtf8());
  getResult(jsonParser->parseToJsonObject(replyJson));
}
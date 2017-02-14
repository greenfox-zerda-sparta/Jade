#pragma once
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QScopedPointer>
#include <QSharedPointer>
#include "Logger.h"
#include "JsonParser.h"
#include "HttpRequest.h"

class AuthenticationService : public QObject {
  Q_OBJECT
private slots:
  void replyAuthenticationFinished(QString replyJson);
private:
  QString token;
  QScopedPointer<JsonParser> jsonParser;
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
public:
  AuthenticationService(QSharedPointer<HttpRequest> httpRequest);
  //void postRequest(QString _url, QString _email, QString _password);
  void postLogin(QString _email, QString _password);
  void postSignup(QString _email, QString _password);
  void getResult(QJsonObject& jsonObject);
};


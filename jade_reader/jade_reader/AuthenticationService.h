#pragma once
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QScopedPointer>
#include "Logger.h"
#include "JsonParser.h"
#include "HttpRequest.h"

class AuthenticationService : public QObject {
  Q_OBJECT
private slots:
  void replyAuthenticationFinished(QNetworkReply*);
private:
  QString reply;
  QString token;
  QScopedPointer<JsonParser> jsonParser;
  QScopedPointer<Logger> logger;
public:
  AuthenticationService();
  void postRequest(QString _url, QString _email, QString _password);
  void postLogin(QString _email, QString _password);
  void postSignup(QString _email, QString _password);
  void getResult(QJsonObject& jsonObject);
};


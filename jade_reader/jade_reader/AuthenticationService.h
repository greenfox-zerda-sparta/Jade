#pragma once
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QScopedPointer>
#include <QNetworkAccessManager>
#include "Logger.h"
#include "JsonParser.h"

class AuthenticationService : public QObject {
  Q_OBJECT
private slots:
  void replyFinished(QNetworkReply*);
private:
  QString pReply;
  QString token;
  QScopedPointer<QNetworkAccessManager> manager;
  QScopedPointer<JsonParser> jsonParser;
  QScopedPointer<Logger> logger;
public:
  AuthenticationService();
  void postRequest(QString _url, QString _email, QString _password);
  void postLogin(QString _email, QString _password);
  void postSignup(QString _email, QString _password);
  void getResult(QJsonObject& jsonObject);
  void getToken();
};


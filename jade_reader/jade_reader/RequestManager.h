#pragma once
#include <QObject>
#include <QNetworkAccessManager>

class RequestManager : public QObject {
  Q_OBJECT
private:
  QNetworkAccessManager* manager;
  QNetworkReply* reply;
public:
  RequestManager();
  ~RequestManager();
public:
  QString getFeed(QString url);
  QString postLogin(QString _email, QString _password);
  QString postSignup(QString _email, QString _password);
};
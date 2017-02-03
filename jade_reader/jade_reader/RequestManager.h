#pragma once
#include <QObject>
#include <QNetworkAccessManager>

class RequestManager : public QObject {
  Q_OBJECT
public:
  QNetworkAccessManager* manager;
  QNetworkReply* reply;
  QString postRequest(QString _url, QString _email, QString _password);
  RequestManager();
  ~RequestManager();
  QString getFeed();
  QString postLogin(QString _email, QString _password);
  QString postSignup(QString _email, QString _password);
};
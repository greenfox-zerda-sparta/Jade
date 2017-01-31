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
private:
  QString getRequest(QString url);
  QString loginRequest(QString _email, QString _password);
public slots:
  void getFeed();
};
#pragma once
#include <QObject>
#include <QNetworkAccessManager>

class RequestManager : public QObject {
  Q_OBJECT

signals:
  QNetworkReply* finishedSignal(QNetworkReply*);
  void onReady();
public:
  QString pReply;
  QNetworkAccessManager* manager;
  QNetworkReply* reply;
  QString postRequest(QString _url, QString _email, QString _password);
  RequestManager();
  ~RequestManager();
  QString getFeed();
  void postLogin(QString _email, QString _password);
  QString postSignup(QString _email, QString _password);
public slots:
  void finishedSlot(QNetworkReply*);
  void replyFinished(QNetworkReply*);

};
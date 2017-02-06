#pragma once
#include <QObject>
#include <QNetworkAccessManager>

class RequestManager : public QObject {
  Q_OBJECT

signals:
  //QNetworkReply* finishedSignal(QNetworkReply*);
  void onReady();
public:
  QString pReply;
  QNetworkAccessManager* manager;
  QNetworkReply* reply;
  void postRequest(QString _url, QString _email, QString _password);
  RequestManager();
  ~RequestManager();
  void getFeed();
  void postLogin(QString _email, QString _password);
  void postSignup(QString _email, QString _password);
private slots:
  void replyFinished(QNetworkReply*);
};
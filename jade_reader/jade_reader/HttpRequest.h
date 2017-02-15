#pragma once
#include <QNetworkAccessManager>
#include <QSharedPointer>
#include <QNetworkReply>
#include <QJsonDocument>

class HttpRequest : public QObject {
  Q_OBJECT
private:
  int serviceID;
public:
  static QSharedPointer<QNetworkAccessManager> networkAccessManager;
  HttpRequest();
  void postRequest(QString _url, QJsonDocument json);
  void getRequest();
  void setServiceID(int);
private slots:
  void replyFinished(QNetworkReply*);
signals:
  void postReady(QJsonDocument);
  void getReady(QJsonDocument);
};


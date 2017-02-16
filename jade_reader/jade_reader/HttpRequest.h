#pragma once
#include <QNetworkAccessManager>
#include <QSharedPointer>
#include <QNetworkReply>
#include <QJsonObject>

class HttpRequest : public QObject {
  Q_OBJECT
private:
  int serviceID;
public:
  static QSharedPointer<QNetworkAccessManager> networkAccessManager;
  HttpRequest();
  void postRequest(QString path, QJsonObject json);
  void getRequest(QString path);
  void setServiceID(int);
private slots:
  void replyFinished(QNetworkReply*);
signals:
  void postReady(QJsonObject);
  void getReady(QJsonObject);
};


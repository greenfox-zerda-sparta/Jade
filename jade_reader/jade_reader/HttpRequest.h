#pragma once
#include <QNetworkAccessManager>
#include <QSharedPointer>

class HttpRequest : public QObject {
  Q_OBJECT
private:
  int serviceID;
public:
  static QSharedPointer<QNetworkAccessManager> networkAccessManager;
  HttpRequest();
  void postRequest(QString _url, QString json);
  void getRequest();
  void setServiceID(int);
private slots:
  void replyFinished(QNetworkReply*);
signals:
  void postReady(QNetworkReply*);
  void getReady(QNetworkReply*);
};


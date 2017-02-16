#pragma once
#include <QNetworkAccessManager>
#include <QSharedPointer>
#include <QNetworkReply>

class HttpRequest : public QObject {
  Q_OBJECT
private:
  QSharedPointer<QNetworkAccessManager> networkAccessManager;
  QNetworkReply* netReply;
public:
  HttpRequest();
private slots:
  void replyFinished(QNetworkReply*);
public slots:
  void postRequest(QString _url, QString json);
  void getRequest();
signals:
  void replyReady(QString);
  void getReady(QString);
};


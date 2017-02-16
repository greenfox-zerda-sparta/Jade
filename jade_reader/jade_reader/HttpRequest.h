#pragma once
#include <QNetworkAccessManager>
#include <QSharedPointer>
#include <QNetworkReply>
#include <QJsonObject>

class HttpRequest : public QObject {
  Q_OBJECT
private:
  QSharedPointer<QNetworkAccessManager> networkAccessManager;
public:
  HttpRequest();
private slots:
  void replyFinished(QNetworkReply*);
public slots:
  void postRequest(QString path, QJsonObject json);
  void getRequest(QString path);
signals:
  void replyReady(QJsonObject);
};


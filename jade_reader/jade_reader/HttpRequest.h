#pragma once
#include <QNetworkAccessManager>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QNetworkReply>
#include <QJsonObject>
#include "Logger.h"

class HttpRequest : public QObject {
  Q_OBJECT
private:
  QSharedPointer<QNetworkAccessManager> networkAccessManager;
  QScopedPointer<Logger> logger;
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


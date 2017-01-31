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
  QString getRequest(QString url);
};
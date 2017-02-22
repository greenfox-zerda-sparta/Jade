#pragma once
#include <QObject>
#include <QScopedPointer>
#include "HttpRequest.h"
#include "SubLister.h"
#include "JsonParser.h"
#include "Logger.h"

class SubscriptionService : public QObject {
  Q_OBJECT
signals:
  void listSubscriptions();
private slots:
  void includePath();
  void listReady(QJsonObject);
private:
  QSharedPointer<HttpRequest> httpRequest;
  QScopedPointer<SubLister> subLister;
public:
  SubscriptionService(QSharedPointer<HttpRequest>);
};
#pragma once
#include <QObject>
#include <QScopedPointer>
#include "HttpRequest.h"
#include "SubLister.h"
#include "SubCreator.h"
#include "JsonParser.h"
#include "Logger.h"

class SubscriptionService : public QObject {
  Q_OBJECT
signals:
  void listSubscriptions();
  void createSubscription(QJsonObject);
private slots:
  void includePath();
  void includePath(QJsonObject);
  void listReady(QJsonObject);
  void createReady(QJsonObject);
private:
  QSharedPointer<HttpRequest> httpRequest;
  QScopedPointer<SubLister> subLister;
  QScopedPointer<SubCreator> subCreator;
public:
  SubscriptionService(QSharedPointer<HttpRequest>);
};
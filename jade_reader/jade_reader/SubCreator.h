#pragma once
#include <QObject>
#include <QScopedPointer>
#include "HttpRequest.h"

class SubCreator : public QObject {
  Q_OBJECT
signals:
  void createSubscriptionSignal(QString, QJsonObject);
  void createReady(QJsonObject);
public slots:
  void replyReady(QJsonObject);
private:
  QSharedPointer<HttpRequest> httpRequest;
public:
  SubCreator(QSharedPointer<HttpRequest>);
  void createSubscription(QString, QJsonObject);
};
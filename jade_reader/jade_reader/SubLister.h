#pragma once
#include <QObject>
#include <QScopedPointer>
#include "HttpRequest.h"

class SubLister : public QObject {
  Q_OBJECT
signals:
  void listSubscriptionsSignal(QString);
  void listReady(QJsonObject);
public slots:
  void replyReady(QJsonObject);
private:
  QSharedPointer<HttpRequest> httpRequest;
public:
  SubLister(QSharedPointer<HttpRequest>);
  void listSubsciptions(QString);
};
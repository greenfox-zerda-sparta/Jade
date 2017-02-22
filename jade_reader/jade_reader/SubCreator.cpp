#include "SubCreator.h"

SubCreator::SubCreator(QSharedPointer<HttpRequest> httpRequest) :
  httpRequest(httpRequest) {
  connect(this, SIGNAL(createSubscriptionSignal(QString, QJsonObject)), httpRequest.data(), SLOT(psotRequest(QString, QJsonObject)));
}

void SubCreator::createSubscription(QString path, QJsonObject json) {
  createSubscriptionSignal(path, json);
}

void SubCreator::replyReady(QJsonObject replyJson) {
  createReady(replyJson);
}
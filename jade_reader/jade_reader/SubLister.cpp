#include "SubLister.h"

SubLister::SubLister(QSharedPointer<HttpRequest> httpRequest) :
  httpRequest(httpRequest) {
  connect(this, SIGNAL(listSubscriptionsSignal(QString)), httpRequest.data(), SLOT(getRequest(QString)));
}

void SubLister::listSubsciptions(QString path) {
  listSubscriptionsSignal(path);
}

void SubLister::replyReady(QJsonObject replyJson) {
  listReady(replyJson);
}
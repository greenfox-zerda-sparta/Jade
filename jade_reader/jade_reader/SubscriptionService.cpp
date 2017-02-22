#include "SubscriptionService.h"
#include "Config.h"
#include "FileHandler.h"

SubscriptionService::SubscriptionService(QSharedPointer<HttpRequest> httpRequest) :
  httpRequest(httpRequest),
  subLister(new SubLister(httpRequest)){
  connect(this, SIGNAL(listSubscriptions()), this, SLOT(includePath()));
  connect(subLister.data(), SIGNAL(listReady(QJsonObject)), this, SLOT(listReady(QJsonObject)));
}

void SubscriptionService::includePath() {
  QString path = Config::SUBSCRIPTIONSPATH + "?token=" + FileHandler::readFile("token.txt");
  subLister->listSubsciptions(path);
}

void SubscriptionService::listReady(QJsonObject) {

}
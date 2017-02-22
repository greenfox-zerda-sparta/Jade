#include "SubscriptionService.h"
#include "Config.h"
#include "FileHandler.h"

SubscriptionService::SubscriptionService(QSharedPointer<HttpRequest> httpRequest) :
  httpRequest(httpRequest),
  subLister(new SubLister(httpRequest)),
  subCreator(new SubCreator(httpRequest)) {
  connect(this, SIGNAL(listSubscriptions()), this, SLOT(includePath()));
  connect(this, SIGNAL(createSubscription(QJsonObject)), this, SLOT(includePath(QJsonObject)));
  connect(subLister.data(), SIGNAL(listReady(QJsonObject)), this, SLOT(listReady(QJsonObject)));
  connect(subCreator.data(), SIGNAL(listReady(QJsonObject)), this, SLOT(createReady(QJsonObject)));
}

void SubscriptionService::includePath() {
  QString path = Config::SUBSCRIPTIONSPATH + "?token=" + FileHandler::readFile("token.txt");
  subLister->listSubsciptions(path);
}

void SubscriptionService::includePath(QJsonObject json) {
  QString path = Config::SUBSCRIBEPATH + "?token=" + FileHandler::readFile("token.txt");
  subCreator->createSubscription(path, json);
}


void SubscriptionService::listReady(QJsonObject) {

}

void SubscriptionService::createReady(QJsonObject) {

}
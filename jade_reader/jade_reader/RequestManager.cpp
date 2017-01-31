#include "RequestManager.h"
#include <QEventLoop>
#include <QNetworkRequest>
#include <QNetworkReply>

RequestManager::RequestManager() {
  manager = new QNetworkAccessManager;
}

QString RequestManager::getRequest(QString url) {
  QEventLoop eventLoop;
  connect(manager, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
  QNetworkRequest request = QNetworkRequest(QUrl(url));
  reply = manager->get(request);
  eventLoop.exec();
  return reply->readAll();
}

RequestManager::~RequestManager() {
  delete manager;
}
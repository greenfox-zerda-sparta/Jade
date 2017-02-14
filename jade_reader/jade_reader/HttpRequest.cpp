#include <QUrl>
#include <QNetworkRequest>
#include "HttpRequest.h"
#include "Config.h"

QSharedPointer<QNetworkAccessManager> HttpRequest::networkAccessManager(new QNetworkAccessManager);

HttpRequest::HttpRequest() {
  connect(HttpRequest::networkAccessManager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void HttpRequest::replyFinished(QNetworkReply* reply) {
  if (serviceID == 1) {
    postReady(reply->readAll());
  } else if (serviceID == 2) {
    getReady(reply->readAll());
  }
  reply->deleteLater();
}

void HttpRequest::setServiceID(int ID) {
  serviceID = ID;
}

void HttpRequest::postRequest(QString _url,  QString json) {
  serviceID = 1;
  QUrl url(_url);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  HttpRequest::networkAccessManager->post(request, json.toUtf8());
}

void HttpRequest::getRequest() {
  serviceID = 2;
  QUrl url(Config::SERVERURL + Config::FEEDPATH);
  QNetworkRequest request = QNetworkRequest(url);
  HttpRequest::networkAccessManager->get(request);
}
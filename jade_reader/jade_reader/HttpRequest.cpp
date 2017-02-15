#include <QUrl>
#include <QNetworkRequest>
#include "HttpRequest.h"
#include "Config.h"
#include "JsonParser.h"

QSharedPointer<QNetworkAccessManager> HttpRequest::networkAccessManager(new QNetworkAccessManager);

HttpRequest::HttpRequest() {
  connect(HttpRequest::networkAccessManager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void HttpRequest::replyFinished(QNetworkReply* reply) {
  if (serviceID == 1) {
    postReady(JsonParser::parseToJsonDocument(reply->readAll()));
  } else if (serviceID == 2) {
    getReady(JsonParser::parseToJsonDocument(reply->readAll()));
  }
  reply->deleteLater();
}

void HttpRequest::setServiceID(int ID) {
  serviceID = ID;
}

void HttpRequest::postRequest(QString _url,  QJsonDocument json) {
  serviceID = 1;
  QUrl url(_url);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  HttpRequest::networkAccessManager->post(request, json.toJson(QJsonDocument::Compact).data());
}

void HttpRequest::getRequest() {
  serviceID = 2;
  QUrl url(Config::SERVERURL + Config::FEEDPATH);
  QNetworkRequest request = QNetworkRequest(url);
  HttpRequest::networkAccessManager->get(request);
}
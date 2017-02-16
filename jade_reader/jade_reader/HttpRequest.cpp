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
    postReady(JsonParser::parseToJsonObject(reply->readAll()));
  } else if (serviceID == 2) {
    getReady(JsonParser::parseToJsonObject(reply->readAll()));
  }
  reply->deleteLater();
}

void HttpRequest::setServiceID(int ID) {
  serviceID = ID;
}

void HttpRequest::postRequest(QString path, QJsonObject json) {
  serviceID = 1;
  QUrl url(Config::SERVERURL + path);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QJsonDocument doc(json);
  HttpRequest::networkAccessManager->post(request, doc.toJson(QJsonDocument::Compact));
}

void HttpRequest::getRequest(QString path) {
  serviceID = 2;
  QUrl url(Config::SERVERURL + path);
  QNetworkRequest request = QNetworkRequest(url);
  HttpRequest::networkAccessManager->get(request);
}
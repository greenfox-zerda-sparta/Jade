#include <QUrl>
#include <QNetworkRequest>
#include "HttpRequest.h"
#include "Config.h"
#include "JsonParser.h"

HttpRequest::HttpRequest() :
  networkAccessManager(new QNetworkAccessManager),
  logger(new Logger("HttpRequest")){
  connect(HttpRequest::networkAccessManager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void HttpRequest::replyFinished(QNetworkReply* reply) {
  replyReady(JsonParser::parseToJsonObject(reply->readAll()));
  reply->deleteLater();
}

void HttpRequest::postRequest(QString path, QJsonObject json) {
  QUrl url(Config::SERVERURL + path);
  logger->info((Config::SERVERURL + path).toUtf8());
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QJsonDocument doc(json);
  connect(this, SIGNAL(replyReady(QJsonObject)), sender(), SLOT(replyReady(QJsonObject)));
  networkAccessManager->post(request, doc.toJson(QJsonDocument::Compact));
}

void HttpRequest::getRequest(QString path) {
  QUrl url(Config::SERVERURL + path);
  logger->info((Config::SERVERURL + path).toUtf8());
  QNetworkRequest request = QNetworkRequest(url);
  connect(this, SIGNAL(replyReady(QJsonObject)), sender(), SLOT(replyReady(QJsonObject)));
  networkAccessManager->get(request);
}
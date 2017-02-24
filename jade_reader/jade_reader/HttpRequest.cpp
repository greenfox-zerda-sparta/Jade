#include <QUrl>
#include <QNetworkRequest>
#include "HttpRequest.h"
#include "Config.h"
#include "JsonParser.h"
#include "FileHandler.h"

HttpRequest::HttpRequest() :
  networkAccessManager(new QNetworkAccessManager) {
  connect(HttpRequest::networkAccessManager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void HttpRequest::replyFinished(QNetworkReply* reply) {
  QString temp = reply->readAll();
  QString string;
  if (temp[0] == '[') {
    string = "{\"itt a key\":" + temp + '}';
  } else {
    string = temp;
  }
  qDebug() << string;
  replyReady(JsonParser::parseToJsonObject(string));
  reply->deleteLater();
}

void HttpRequest::postRequest(QString path, QJsonObject json) {
  QUrl url(Config::SERVERURL + path);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QJsonDocument doc(json);
  connect(this, SIGNAL(replyReady(QJsonObject)), sender(), SLOT(replyReady(QJsonObject)));
  networkAccessManager->post(request, doc.toJson(QJsonDocument::Compact));
}

void HttpRequest::getRequest(QString path) {
  QUrl url(Config::SERVERURL + path);
  QNetworkRequest request = QNetworkRequest(url);
  qDebug() << sender();
  connect(this, SIGNAL(replyReady(QJsonObject)), sender(), SLOT(replyReady(QJsonObject)));
  networkAccessManager->get(request);
}
#include <QUrl>
#include <QNetworkRequest>
#include "HttpRequest.h"
#include "Config.h"
#include "FeedWindow.h"

HttpRequest::HttpRequest() :
  networkAccessManager(new QNetworkAccessManager) {
  connect(networkAccessManager.data(), SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void HttpRequest::replyFinished(QNetworkReply* reply) {
  replyReady(reply->readAll());
}

void HttpRequest::postRequest(QString _url,  QString json) {
  QUrl url(_url);
  QNetworkRequest request = QNetworkRequest(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

  connect(this, SIGNAL(replyReady(QString)), sender(), SLOT(replyReady(QString)));

  networkAccessManager->post(request, json.toUtf8());
}

void HttpRequest::getRequest() {
  QUrl url(Config::SERVERURL + Config::FEEDPATH);
  QNetworkRequest request = QNetworkRequest(url);

  connect(this, SIGNAL(replyReady(QString)), sender(), SLOT(replyReady(QString)));

  networkAccessManager->get(request);
}
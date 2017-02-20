#include "FeedService.h"
#include "Config.h"
#include "HttpRequest.h"
#include "FileHandler.h"
#include <QNetworkRequest>
#include <QNetworkReply>


FeedService::FeedService(QSharedPointer<HttpRequest> httpRequest) :
  parser(new JsonParser),
  articles(new QVector<Article*>),
  logger(new Logger("FeedService")),
  httpRequest(httpRequest) {
  //connect(this, SIGNAL(refreshSignal(QString)), httpRequest.data(), SLOT(getRequest(QString)));
  connect(this, SIGNAL(refreshSignal(QString)), this, SLOT(getToken(QString)));
  connect(this, SIGNAL(refreshSignalWithToken(QString)), httpRequest.data(), SLOT(getRequest(QString)));
}

void FeedService::getToken(QString path) {
  path += "?token=" + FileHandler::readFile("token.txt");
  refreshSignalWithToken(path);
}

void FeedService::replyReady(QJsonObject replyJson) {
  logger->info("replyFinished - got data from server");
  *articles = parser->parseFromObjectToArticleVector(replyJson);
  logger->info("articles size " + QString(articles->size()));
  this->onReady(articles.data());
  disconnect(httpRequest.data(), SIGNAL(replyReady(QJsonObject)), this, SLOT(replyReady(QJsonObject)));
}


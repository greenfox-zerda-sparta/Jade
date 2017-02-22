#pragma once
#include <QObject>
#include <QScopedPointer>
#include <QNetWorkReply>
#include <QJsonObject>
#include "JsonParser.h"
#include "Logger.h"
#include "HttpRequest.h"

class FeedService : public QObject {
  Q_OBJECT
signals:
  void failedResponse();
  void successResponse();
  void sendRequestSignal(QString);
public slots:
  void replyReady(QJsonObject);
  void sendRequestData();
private:
  QScopedPointer<JsonParser> parser;
  QSharedPointer<QVector<Article*>> articles;
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
  void generateArticleVector(QJsonObject);
public:
  FeedService(QSharedPointer<HttpRequest>);
  QSharedPointer<QVector<Article*>> getArticles();
};
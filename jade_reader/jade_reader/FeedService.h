#pragma once
#include <QObject>
#include <QScopedPointer>
#include <QNetWorkReply>
#include "JsonParser.h"
#include "Logger.h"
#include "HttpRequest.h"

class FeedService : public QObject {
  Q_OBJECT
signals:
  void onReady(QVector<Article*>*);
private slots:
  void replyFinished(QNetworkReply*);
private:
  QScopedPointer<JsonParser> parser;
  QScopedPointer<QVector<Article*>> articles;
  QNetworkReply* networkReply;
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
public:
  FeedService(QSharedPointer<HttpRequest>);
  void getFeed();
};
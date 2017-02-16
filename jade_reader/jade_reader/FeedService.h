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
  void refreshSignal();
  void onReady(QVector<Article*>*);
public slots:
  void replyReady(QString);
private:
  QScopedPointer<JsonParser> parser;
  QScopedPointer<QVector<Article*>> articles;
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
public:
  FeedService(QSharedPointer<HttpRequest>);
  void getFeed();
};
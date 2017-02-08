#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include <QScopedPointer>
#include "JsonParser.h"

class FeedService : public QObject {
  Q_OBJECT
signals:
  void onReady(QVector<Article*>*);
private slots:
  void replyFinished(QNetworkReply*);
private:
  QScopedPointer<QNetworkAccessManager> manager;
  QScopedPointer<JsonParser> parser;
  QScopedPointer<QVector<Article*>> articles;
public:
  FeedService();
  ~FeedService();
  void getFeed();
};
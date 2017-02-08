#pragma once
#include <QObject>
#include <QNetworkAccessManager>
#include "JsonParser.h"

class FeedService : public QObject {
  Q_OBJECT
signals:
  void onReady(QVector<Article*>*);
private slots :
  void replyFinished(QNetworkReply*);
private:
  QNetworkAccessManager* manager;
  QString reply;
  JsonParser* parser;
  QVector<Article*>* articles;
public:
  FeedService();
  ~FeedService();
  void getFeed();
};
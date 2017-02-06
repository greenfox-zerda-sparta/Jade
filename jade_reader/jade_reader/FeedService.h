#pragma once
#include <QObject>
#include <QNetworkAccessManager>

class FeedService : public QObject {
  Q_OBJECT
signals:
  void onReady(QString*);
private slots :
  void replyFinished(QNetworkReply*);
private:
  QNetworkAccessManager* manager;
  QString* reply;
public:
  FeedService();
  ~FeedService();
  void getFeed();
};
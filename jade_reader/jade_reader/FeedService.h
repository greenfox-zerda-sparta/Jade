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
  void refreshSignal(QString);
  void onReady(QVector<Article*>*);
  void refreshSignalWithToken(QString);
public slots:
  void replyReady(QJsonObject);
private slots:
  void getToken(QString path);
private:
  QScopedPointer<JsonParser> parser;
  QScopedPointer<QVector<Article*>> articles;
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
public:
  FeedService(QSharedPointer<HttpRequest>);
};
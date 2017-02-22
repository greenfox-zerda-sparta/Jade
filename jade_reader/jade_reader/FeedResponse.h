#pragma once
#include <QObject>
#include <QString>
#include <QJsonArray>

class FeedResponse : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString error READ getError WRITE setError);
  Q_PROPERTY(QJsonArray feed READ getFeed WRITE setFeed);
private:
  QString error;
  QJsonArray feed;
public:
  Q_INVOKABLE FeedResponse();
  QString getError();
  void setError(QString error);
  QJsonArray getFeed();
  void setFeed(QJsonArray feed);
  bool isError();
};


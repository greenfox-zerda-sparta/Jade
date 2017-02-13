#pragma once
#include <QString>
#include <QObject>

class Article : QObject {
  Q_OBJECT
  Q_PROPERTY(quint64 id READ getId);
  Q_PROPERTY(QString title READ getTitle);
  Q_PROPERTY(QString description READ getDescription);
  Q_PROPERTY(QString created READ getCreated);
  /*Q_PROPERTY(QString feedName READ);
  Q_PROPERTY(quint64 feedId);
  Q_PROPERTY(bool favorite);
  Q_PROPERTY(bool opened);
  Q_PROPERTY(QString url);*/
private:
  quint64 id;
  QString title;
  QString description;
  QString created;
  QString feedName;
  quint64 feedId;
  bool favorite;
  bool opened;
  QString url;
public:
  quint64 getId();
  QString getTitle();
  QString getDescription();
  QString getCreated();
  QString getFeedName();
  quint64 getFeedId();
  bool getFavorite();
  void setFavorite(bool favorite);
  bool getOpened();
  void setOpened(bool opened);
  QString getUrl();
  Q_INVOKABLE Article();
  Article(quint64 id, QString title, QString description, qint64 created, QString feedName, quint64 feedId, bool favorite, bool opened, QString url);
  ~Article();
};
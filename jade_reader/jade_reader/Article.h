#pragma once
#include <QString>
#include <QObject>

class Article : QObject {
  Q_OBJECT
  Q_PROPERTY(quint64 id READ getId WRITE setId);
  Q_PROPERTY(QString title READ getTitle WRITE setTitle);
  Q_PROPERTY(QString description READ getDescription WRITE setDescription);
  Q_PROPERTY(QString created READ getCreated WRITE setCreated);
  Q_PROPERTY(QString feedName READ getFeedName WRITE setFeedName);
  Q_PROPERTY(quint64 feedId READ getFeedId WRITE setFeedId);
  Q_PROPERTY(bool favorite READ getFavorite WRITE setFavorite);
  Q_PROPERTY(bool opened READ getOpened WRITE setOpened);
  Q_PROPERTY(QString url READ getUrl WRITE setUrl);
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
  void setId(quint64 id);
  QString getTitle();
  void setTitle(QString title);
  QString getDescription();
  void setDescription(QString description);
  QString getCreated();
  void setCreated(QString created);
  QString getFeedName();
  void setFeedName(QString feedName);
  quint64 getFeedId();
  void setFeedId(quint64 feedId);
  bool getFavorite();
  void setFavorite(bool favorite);
  bool getOpened();
  void setOpened(bool opened);
  QString getUrl();
  void setUrl(QString url);
  Q_INVOKABLE Article();
  Article(Article* article);
  Article(quint64 id, QString title, QString description, qint64 created, QString feedName, quint64 feedId, bool favorite, bool opened, QString url);
  ~Article();
};
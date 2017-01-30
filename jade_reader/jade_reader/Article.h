#pragma once
#include <QString>

class Article {
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
  QString dateParser(qint64 date);
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
  Article(quint64 id, QString title, QString description, qint64 created, QString feedName, quint64 feedId, bool favorite, bool opened, QString url);
  ~Article();
};
#pragma once
#include <QScrollArea>
#include "ArticleLayoutCreator.h"
#include "HeaderLayoutCreator.h"
#include "FeedService.h"

class FeedWindow : public QScrollArea {
Q_OBJECT
signals:
void refreshSignal();
void signOutSignal();
public slots:
void refreshSlot();
void signOutSlot();
private slots:
void loadFeed(QVector<Article*>* articles);
private:
  QSharedPointer<FeedService> feedService;
  QWidget* articleWindow;
  QVBoxLayout* articleContainerLayout;
  ArticleLayoutCreator* layoutCreator;
  HeaderLayoutCreator* headerLayoutCreator;
public:
  FeedWindow(QSharedPointer<HttpRequest>, QWidget* parent = 0);
  ~FeedWindow();
  void createWindow(QVector<Article*>);
  void refreshFeedScreen(QVector<Article*>*);
};


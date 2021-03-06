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
void refreshSignalWithPath(QString);
public slots:
void signOutSlot();
private slots:
void refreshSlot();
void loadFeed(QVector<Article*>* articles);
private:
  QSharedPointer<FeedService> feedService;
  QScopedPointer<QWidget> articleWindow;
  QScopedPointer<QVBoxLayout> articleContainerLayout;
  QScopedPointer<ArticleLayoutCreator> layoutCreator;
  QScopedPointer<HeaderLayoutCreator> headerLayoutCreator;
public:
  FeedWindow(QSharedPointer<HttpRequest>, QWidget* parent = 0);
  void createWindow(QVector<Article*>);
  void refreshFeedScreen(QVector<Article*>*);
};


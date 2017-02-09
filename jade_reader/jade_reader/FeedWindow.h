#pragma once
#include <QScrollArea>
#include "ArticleLayoutCreator.h"
#include "HeaderLayoutCreator.h"

class FeedWindow : public QScrollArea {
Q_OBJECT
signals:
void refreshSignal();
void signOutSignal();
public slots:
void refreshSlot();
void signOutSlot();
private:
  QWidget* articleWindow;
  QVBoxLayout* articleContainerLayout;
  ArticleLayoutCreator* layoutCreator;
  HeaderLayoutCreator* headerLayoutCreator;
public:
  FeedWindow(QWidget* parent = 0);
  ~FeedWindow();
  void createWindow(QVector<Article*>);
};


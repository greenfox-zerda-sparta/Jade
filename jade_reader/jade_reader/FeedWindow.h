#pragma once
#include <QScrollArea>
#include "ArticleLayoutCreator.h"

class FeedWindow : public QScrollArea {
Q_OBJECT
private:
  QWidget* articleWindow;
  QVBoxLayout* articleContainerLayout;
  ArticleLayoutCreator* layoutCreator;
public:
  FeedWindow(QWidget* parent = 0);
  ~FeedWindow();
  void createWindow(QVector<Article*> article);
};


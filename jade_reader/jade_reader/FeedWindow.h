#pragma once
#include <QScrollArea>
#include "ArticleLayoutCreator.h"
#include "HeaderLayoutCreator.h"

class FeedWindow : public QScrollArea {
Q_OBJECT
private:
  QWidget* articleWindow;
  QVBoxLayout* articleContainerLayout;
  ArticleLayoutCreator* layoutCreator;
  HeaderLayoutCreator* headerLayoutCreator;
  //QBoxLayout* headerLayout;
public:
  FeedWindow(QWidget* parent = 0);
  ~FeedWindow();
  void createWindow(QVector<Article*>);
};


#include "FeedWindow.h"

FeedWindow::FeedWindow(QWidget* parent) : QScrollArea(parent) {
  this->setWidgetResizable(true);
  articleWindow = new QWidget;
  headerLayout = new QGridLayout(articleWindow);
  articleContainerLayout = new QVBoxLayout(articleWindow);
  this->setWidget(articleWindow);
  layoutCreator = new ArticleLayoutCreator;
}

FeedWindow::~FeedWindow() {
  delete layoutCreator;
  delete headerLayoutCreator;
  delete headerLayout;
  delete articleContainerLayout;
  delete articleWindow;
}

void FeedWindow::createWindow(QVector<Article*> articles) {
  headerLayout->addLayout(headerLayoutCreator->createHeaderLayout());
  articleContainerLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    articleContainerLayout->addLayout(layoutCreator->createLayout(articles[i])->layout, 50);
  }
}
#include "FeedWindow.h"

FeedWindow::FeedWindow(QWidget* parent) : QScrollArea(parent) {
  this->setWidgetResizable(true);
  articleWindow = new QWidget;
  articleContainerLayout = new QVBoxLayout(articleWindow);
  this->setWidget(articleWindow);
  layoutCreator = new ArticleLayoutCreator;
}

FeedWindow::~FeedWindow() {
  delete layoutCreator;
  delete articleContainerLayout;
  delete articleWindow;
}

void FeedWindow::createWindow(QVector<Article*> articles) {
  articleContainerLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    articleContainerLayout->addLayout(layoutCreator->createLayout(articles[i])->layout);
  }
}
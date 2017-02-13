#include "FeedWindow.h"

FeedWindow::FeedWindow(QWidget* parent) : QScrollArea(parent) {
  this->setWidgetResizable(true);
  articleWindow = new QWidget;
  articleContainerLayout = new QVBoxLayout(articleWindow);
  this->setWidget(articleWindow);
  layoutCreator = new ArticleLayoutCreator;
  headerLayoutCreator = new HeaderLayoutCreator;
  connect(headerLayoutCreator, SIGNAL(refreshSignal()), this, SLOT(refreshSlot()));
  connect(headerLayoutCreator, SIGNAL(signOutSignal()), this, SLOT(signOutSlot()));
}

FeedWindow::~FeedWindow() {
  delete layoutCreator;
  delete headerLayoutCreator;
  delete articleContainerLayout;
  delete articleWindow;
}

void FeedWindow::createWindow(QVector<Article*> articles) {
  articleContainerLayout->addLayout(headerLayoutCreator->createHeaderLayout());
  articleContainerLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    articleContainerLayout->addLayout(layoutCreator->createLayout(articles[i])->layout);
  }
}

void FeedWindow::refreshSlot() {
  refreshSignal();
}

void FeedWindow::signOutSlot() {
  signOutSignal();
}

void FeedWindow::refreshFeedScreen(QVector<Article*> articles) {
  delete articleContainerLayout;
  articleContainerLayout = new QVBoxLayout(articleWindow);
  createWindow(articles);
}
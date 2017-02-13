#include "FeedWindow.h"

FeedWindow::FeedWindow(QWidget* parent) : QScrollArea(parent) {
  this->setWidgetResizable(true);
  articleWindow = new QWidget;
  articleContainerLayout = new QVBoxLayout(articleWindow);
  this->setWidget(articleWindow);
  layoutCreator = new ArticleLayoutCreator;
  headerLayoutCreator = new HeaderLayoutCreator;
  articleContainerLayout->addLayout(headerLayoutCreator->createHeaderLayout());
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
  articleContainerLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    QWidget* widget = new QWidget;
    widget->setLayout(layoutCreator->createLayout(articles[i])->layout);
    articleContainerLayout->addWidget(widget);
  }
}

void FeedWindow::refreshSlot() {
  refreshSignal();
}

void FeedWindow::signOutSlot() {
  signOutSignal();
}

void FeedWindow::refreshFeedScreen(QVector<Article*>* articles) {
  for (int i = articleContainerLayout->count(); i > 0; i--) {
    delete articleContainerLayout->itemAt(articleContainerLayout->count() - 1)->widget();
  }
}
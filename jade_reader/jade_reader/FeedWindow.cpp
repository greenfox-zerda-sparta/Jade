#include "FeedWindow.h"

FeedWindow::FeedWindow(QSharedPointer<HttpRequest> httpRequest, QWidget* parent) : QScrollArea(parent), feedService(new FeedService(httpRequest)) {
  this->setWidgetResizable(true);
  articleWindow = new QWidget;
  articleContainerLayout = new QVBoxLayout(articleWindow);
  this->setWidget(articleWindow);
  layoutCreator = new ArticleLayoutCreator;
  headerLayoutCreator = new HeaderLayoutCreator;
  articleContainerLayout->addLayout(headerLayoutCreator->createHeaderLayout());
  connect(headerLayoutCreator, SIGNAL(refreshSignal()), this, SLOT(refreshSlot()));
  connect(headerLayoutCreator, SIGNAL(signOutSignal()), this, SLOT(signOutSlot()));
  connect(feedService.data(), SIGNAL(onReady(QVector<Article*>*)), this, SLOT(loadFeed(QVector<Article*>*)));
}

FeedWindow::~FeedWindow() {
  delete layoutCreator;
  delete headerLayoutCreator;
  delete articleContainerLayout;
  delete articleWindow;
}

void FeedWindow::createWindow(QVector<Article*> articles) {
  qDebug() << "FeedWindow::createWindow started";
  articleContainerLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    QWidget* widget = new QWidget;
    widget->setLayout(layoutCreator->createLayout(articles[i])->layout);
    articleContainerLayout->addWidget(widget);
  }
}

void FeedWindow::refreshSlot() {
  feedService->getFeed();
}

void FeedWindow::loadFeed(QVector<Article*>* articles) {
  qDebug() << "FeedWindow::loadFeed, article size: " << articles->size();
  refreshFeedScreen(articles);
  createWindow(*articles);
}

void FeedWindow::signOutSlot() {
  signOutSignal();
}

void FeedWindow::refreshFeedScreen(QVector<Article*>* articles) {
  for (int i = articleContainerLayout->count(); i > 0; i--) {
    delete articleContainerLayout->itemAt(articleContainerLayout->count() - 1)->widget();
  }
}
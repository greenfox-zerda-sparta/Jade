#include "FeedWindow.h"
#include "Config.h"

FeedWindow::FeedWindow(QSharedPointer<HttpRequest> httpRequest, QWidget* parent) : 
  QScrollArea(parent), 
  feedService(new FeedService(httpRequest)), 
  articleWindow(new QWidget),
  articleContainerLayout(new QVBoxLayout(articleWindow.data())),
  layoutCreator(new ArticleLayoutCreator),
  headerLayoutCreator(new HeaderLayoutCreator) {
    this->setWidgetResizable(true);
    this->setWidget(articleWindow.data());
    articleContainerLayout->addLayout(headerLayoutCreator->createHeaderLayout().data());
    connect(this, SIGNAL(refreshSignal()), this, SLOT(refreshSlot()));
    connect(this, SIGNAL(refreshSignalWithPath(QString)), feedService.data(), SIGNAL(refreshSignal(QString)));
    connect(headerLayoutCreator.data(), SIGNAL(refreshSignal(QString)), feedService.data(), SIGNAL(refreshSignal(QString)));
    connect(headerLayoutCreator.data(), SIGNAL(signOutSignal()), this, SLOT(signOutSlot()));
    connect(feedService.data(), SIGNAL(onReady(QVector<Article*>*)), this, SLOT(loadFeed(QVector<Article*>*)));
 }

void FeedWindow::createWindow(QVector<Article*> articles) {
  articleContainerLayout->setSizeConstraint(QLayout::SetMaximumSize);
  for (int i = 0; i < articles.size(); ++i) {
    QWidget* widget = new QWidget;
    widget->setLayout(layoutCreator->createLayout(articles[i])->getLayout().data());
    articleContainerLayout->addWidget(widget);
  }
}

void FeedWindow::loadFeed(QVector<Article*>* articles) {
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

void FeedWindow::refreshSlot() {
  refreshSignalWithPath(Config::FEEDPATH);
}
#include "ArticleLayout.h"


ArticleLayout::ArticleLayout(Article* _article) :
  labelCreator(new LabelCreator),
  layout(new QGridLayout()),
  goToLinkButton(new QPushButton()) {
    article = _article;
    goToLinkButton->setText("Go to link");
    markAsReadButton = addMarkAsReadButton();
    markAsFavouriteButton = addMarkFavouriteButton();
    addWidgetsToLayout();
    connect(markAsReadButton.data(), &QAbstractButton::clicked, this, &ArticleLayout::markAsRead);
    connect(goToLinkButton.data(), &QAbstractButton::clicked, this, &ArticleLayout::newBrowserWindow);
}

void ArticleLayout::addWidgetsToLayout() {
  layout->setColumnStretch(0, 99);
  layout->addWidget(labelCreator->createLabelFromQString(article->getTitle()), 0, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator->createLabelFromQString(article->getCreated()), 1, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator->createLabelFromQString(article->getFeedName()), 0, 1, 1, 1, Qt::AlignLeft);
  layout->addWidget(markAsReadButton.data(), 1, 1, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator->createLabelFromQString(article->getDescription()), 2, 0, 1, -1, Qt::AlignLeft);
  layout->addWidget(goToLinkButton.data(), 0, 2);
  layout->addWidget(markAsFavouriteButton.data(), 1, 2);
}

void ArticleLayout::newBrowserWindow() {
  QWidget* widget = Q_NULLPTR;
  QWebEngineView *view = new QWebEngineView(widget);
  view->load(QUrl(article->getUrl()));
  view->show();
  markAsRead();
}

void ArticleLayout::markAsRead() {
  article->setOpened(!article->getOpened());
  article->getOpened() ? markAsReadButton->setText("Mark as unread") : markAsReadButton->setText("Mark as read");
}

void ArticleLayout::markFavourite() {
  article->setFavorite(true);
}

QSharedPointer<QPushButton> ArticleLayout::addMarkAsReadButton() {
  QSharedPointer<QPushButton> markAsReadButton(new QPushButton);
  article->getOpened() ? markAsReadButton->setText("Mark as unread") : markAsReadButton->setText("Mark as read");
  return markAsReadButton;
}

QSharedPointer<QPushButton> ArticleLayout::addMarkFavouriteButton() {
  QSharedPointer<QPushButton> markAsFavouriteButton(new QPushButton);
  if (!article->getFavorite()) {
    markAsFavouriteButton->setText("Mark as Favourite");
  }
  else {
    markAsFavouriteButton->setText("Cancel Favourite");
  }
  return markAsFavouriteButton;
}

QSharedPointer<QGridLayout> ArticleLayout::getLayout() {
  return layout;
}
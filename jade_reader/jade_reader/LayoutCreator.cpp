#include "LayoutCreator.h"
#include <QPushButton>
#include <QLayout>
#include <QWidgetItem>
#include <QWebEngineView>
#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include <iostream>


LayoutCreator::LayoutCreator() {}

LayoutCreator::~LayoutCreator() {}

ArticleLayout::ArticleLayout(Article* _article) {
  article = _article;
  LabelCreator labelCreator;
  layout = new QGridLayout();
  QPushButton* goToLinkButton = new QPushButton();
  QPushButton* markAsReadButton = addMarkAsReadButton();
  QPushButton* markAsFavouriteButton = addMarkFavouriteButton();
  layout->addWidget(labelCreator.createLabelFromQString(article->getTitle()), 0, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getCreated()), 1, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getFeedName()), 0, 1, 1, 1, Qt::AlignLeft);
  layout->addWidget(markAsReadButton, 1, 1, 1, 1, Qt::AlignLeft);
  connect(markAsReadButton, &QAbstractButton::clicked, this, &ArticleLayout::markAsRead);
  layout->addWidget(labelCreator.createLabelFromQString(article->getDescription()), 2, 0, 1, -1, Qt::AlignLeft);
  layout->setColumnStretch(0, 99);
  layout->addWidget(goToLinkButton, 0, 2);
  goToLinkButton->setText("Go to link");
  connect(goToLinkButton, &QAbstractButton::clicked, this, &ArticleLayout::newBrowserWindow);
  layout->addWidget(markAsFavouriteButton, 1, 2);
}

ArticleLayout* LayoutCreator::createLayout(Article* article) {
  ArticleLayout* al = new ArticleLayout(article);
  return al;
}

void ArticleLayout::newBrowserWindow() {
  QWidget* widget = Q_NULLPTR;
  QWebEngineView *view = new QWebEngineView(widget);
  view->load(QUrl(article->getUrl()));
  view->show();
  markAsRead();
}

void ArticleLayout::markAsRead() {
  if (!article->getOpened()) {
    article->setOpened(true);
  } else {
    article->setOpened(false);
    }
}

void ArticleLayout::markFavourite() {
  article->setFavorite(true);
}

QPushButton* ArticleLayout::addMarkAsReadButton() {
  QPushButton* markAsReadButton = new QPushButton;
  if (!article->getOpened()) {
    markAsReadButton->setText("Mark as read");
  } else {
    markAsReadButton->setText("Mark as unread");
    }
  return markAsReadButton;
}

QPushButton* ArticleLayout::addMarkFavouriteButton() {
  QPushButton* markAsFavouriteButton = new QPushButton;
  if (!article->getFavorite()) {
    markAsFavouriteButton->setText("Mark as Favourite");
  }
  else {
    markAsFavouriteButton->setText("Cancel Favourite");
  }
  return markAsFavouriteButton;
}
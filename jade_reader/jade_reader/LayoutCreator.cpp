#include "LayoutCreator.h"
#include "flowlayout.h"
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
  QPushButton *pushButton1 = new QPushButton();
  QPushButton *pushButton2 = new QPushButton();
  layout->addWidget(labelCreator.createLabelFromQString(article->getTitle()), 0, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getCreated()), 1, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getFeedName()), 0, 1, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getUrl()), 1, 1, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getDescription()), 2, 0, 1, -1, Qt::AlignLeft);
  layout->setColumnStretch(0, 99);
  layout->addWidget(pushButton1, 0, 2);
  pushButton1->setText("Go to link");
  connect(pushButton1, &QAbstractButton::clicked, this, &ArticleLayout::newBrowserWindow);
  layout->addWidget(pushButton2, 1, 2);
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
}
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

ArticleLayout* LayoutCreator::createLayout(Article* article) {
  ArticleLayout* al = new ArticleLayout(article);
  return al;
}

void LayoutCreator::openNewBrowserWindow(QGridLayout* layout) {

}

void LayoutCreator::clickOpenBrowser() {
//  openNewBrowserWindow();
}



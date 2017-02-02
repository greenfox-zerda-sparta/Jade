#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWidgetItem>
#include <QtWidgets/QVBoxLayout>
#include <QWebEngineView>
#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include "Article.h"
#include "LabelCreator.h"

class ArticleLayout : public QObject {
  Q_OBJECT
public:
  ArticleLayout(Article* _article);
  QGridLayout* layout;
  Article* article;
  public slots:
  QPushButton* addMarkAsReadButton();
  QPushButton* addMarkFavouriteButton();
  void newBrowserWindow();
  void markFavourite();
  void markAsRead();
};


#pragma once
#include "LabelCreator.h"
#include "Article.h"
#include <QtWidgets/QVBoxLayout>
#include <QPushButton>
#include <QLayout>
#include <QWidgetItem>
#include <QWebEngineView>
#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
class Application;

class ArticleLayout : public QObject{
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

class LayoutCreator: public QObject{
private:
Q_OBJECT
public:
  LayoutCreator();
  ~LayoutCreator();
  ArticleLayout* createLayout(Article*);
};
#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWebEngineView>
#include <QWidget>
#include "Article.h"
#include "LabelCreator.h"

class ArticleLayout : public QObject {
  Q_OBJECT
private:
  LabelCreator* labelCreator;
  QPushButton* markAsReadButton;
  QPushButton* markAsFavouriteButton;
  QPushButton* goToLinkButton;
  void addWidgetsToLayout();
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


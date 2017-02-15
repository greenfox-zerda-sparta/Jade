#pragma once
#include <QPushButton>
#include <QLayout>
#include <QWebEngineView>
#include <QWidget>
#include "Article.h"
#include "LabelCreator.h"

class ArticleLayout : public QObject {
  Q_OBJECT
public slots:
  void newBrowserWindow();
  void markFavourite();
  void markAsRead();
private:
  Article* article;
  QScopedPointer<LabelCreator> labelCreator;
  QSharedPointer<QPushButton> markAsReadButton;
  QSharedPointer<QPushButton> markAsFavouriteButton;
  QSharedPointer<QPushButton> goToLinkButton;
  QSharedPointer<QGridLayout> layout;
  void addWidgetsToLayout();
public:
  ArticleLayout(Article* _article);
  QSharedPointer<QGridLayout> getLayout();
  QSharedPointer<QPushButton> addMarkAsReadButton();
  QSharedPointer<QPushButton> addMarkFavouriteButton();
};


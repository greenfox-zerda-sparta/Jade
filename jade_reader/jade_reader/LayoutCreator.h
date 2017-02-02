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
#include "ArticleLayout.h"


class LayoutCreator: public QObject{
private:
Q_OBJECT
public:
  LayoutCreator();
  ~LayoutCreator();

  ArticleLayout* createLayout(Article*);

};
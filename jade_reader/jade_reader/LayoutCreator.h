#pragma once
#include "LabelCreator.h"
#include "Article.h"
#include <QtWidgets/QVBoxLayout>
class Application;

class LayoutCreator: public QObject{
Q_OBJECT
public:
  QString url;
  LayoutCreator();
  ~LayoutCreator();
  QGridLayout* createLayout(Article*);
  void openNewBrowserWindow(QString);
public slots:
void clickOpenBrowser();
};
#pragma once
#include "LabelCreator.h"
#include "Article.h"
#include <QtWidgets/QVBoxLayout>
class Application;

class LayoutCreator: public QObject{
Q_OBJECT
public:
  LayoutCreator();
  ~LayoutCreator();
  QGridLayout* createLayout(Article*);
  
/*private slots:
  void getFeed();*/
};
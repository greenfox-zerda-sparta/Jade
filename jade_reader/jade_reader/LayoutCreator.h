#pragma once
#include "LabelCreator.h"
#include "Article.h"
#include <QtWidgets/QVBoxLayout>

class LayoutCreator {
public:
  LayoutCreator();
  ~LayoutCreator();
  QVBoxLayout* createLayout(Article*);
};
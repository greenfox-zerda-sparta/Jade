#include "LayoutCreator.h"



LayoutCreator::LayoutCreator()
{
}


LayoutCreator::~LayoutCreator()
{
}

QVBoxLayout* LayoutCreator::createLayout(Article* article) {
  LabelCreator labelCreator;
  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(labelCreator.createLabelFromQString(article->getTitle()));
  layout->addWidget(labelCreator.createLabelFromQString(article->getImg()));
  layout->addWidget(labelCreator.createLabelFromQString(article->getDescription()));
  return layout;
}


#include "LabelCreator.h"

LabelCreator::LabelCreator()
{
}


LabelCreator::~LabelCreator()
{
}

QLabel* LabelCreator::createLabelFromQString(QString input) {
  QLabel* qLabel = new QLabel(input);
  qLabel->setWordWrap(true);
  return qLabel;
}
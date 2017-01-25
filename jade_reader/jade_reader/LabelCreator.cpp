#include "LabelCreator.h"

LabelCreator::LabelCreator() {}


LabelCreator::~LabelCreator() {}

QLabel* LabelCreator::createLabelFromQString(QString input) {
  QLabel* qLabel = new QLabel(input);
  qLabel->setWordWrap(true);
  QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
  //sizePolicy1.setHeightForWidth(qLabel->sizePolicy().hasHeightForWidth());
  qLabel->setSizePolicy(sizePolicy1);
  qLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
  return qLabel;
}
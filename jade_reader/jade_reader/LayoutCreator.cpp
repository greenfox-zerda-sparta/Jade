#include "LayoutCreator.h"
#include <QPushButton>


LayoutCreator::LayoutCreator() {}


LayoutCreator::~LayoutCreator() {}

QGridLayout* LayoutCreator::createLayout(Article* article) {
  LabelCreator labelCreator;

  QGridLayout * layout = new QGridLayout();
  QPushButton *pushButton1 = new QPushButton();
  QPushButton *pushButton2 = new QPushButton();
 // void QGridLayout::addWidget(QWidget *widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment alignment = Qt::Alignment())
  layout->addWidget(labelCreator.createLabelFromQString(article->getTitle()),1,1,1,-1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getCreated()), 2, 1, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getDescription()), 2, 1, 2, -1, Qt::AlignLeft);
  layout->addWidget(pushButton1, 1, 2, 1, 1);
  layout->addWidget(pushButton2, 2, 2, 1, 1);

  return layout;
}
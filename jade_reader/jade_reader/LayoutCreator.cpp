#include "LayoutCreator.h"
#include "flowlayout.h"
#include <QPushButton>
#include <QLayout>
#include <QWidgetItem>


LayoutCreator::LayoutCreator() {}

LayoutCreator::~LayoutCreator() {}

QGridLayout* LayoutCreator::createLayout(Article* article) {
  LabelCreator labelCreator;

  QGridLayout * layout = new QGridLayout();
  FlowLayout* titleDate = new FlowLayout();
  QPushButton *pushButton1 = new QPushButton();
  QPushButton *pushButton2 = new QPushButton();
  //void QGridLayout::addWidget(QWidget *widget, int fromRow, int fromColumn, int rowSpan, int columnSpan, Qt::Alignment alignment = Qt::Alignment())
  //layout->addItem(titleDate, 1, 1, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getTitle()), 0, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getCreated()), 1, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getDescription()), 2, 0, 1, -1, Qt::AlignLeft);
  layout->setColumnStretch(0, 99);
  layout->addWidget(pushButton1, 0, 1);
  pushButton1->setText("Go to link");
  layout->addWidget(pushButton2, 1, 1);

  return layout;
}
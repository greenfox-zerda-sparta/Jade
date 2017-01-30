#include "LayoutCreator.h"
#include "flowlayout.h"
#include <QPushButton>
#include <QLayout>
#include <QWidgetItem>
#include <QWebEngineView>
#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include <iostream>


LayoutCreator::LayoutCreator() {}

LayoutCreator::~LayoutCreator() {}

QGridLayout* LayoutCreator::createLayout(Article* article) {
  LabelCreator labelCreator;
  QGridLayout * layout = new QGridLayout();
  FlowLayout* titleDate = new FlowLayout();
  QPushButton *pushButton1 = new QPushButton();
  QPushButton *pushButton2 = new QPushButton();
  layout->addWidget(labelCreator.createLabelFromQString(article->getTitle()), 0, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getCreated()), 1, 0, 1, 1, Qt::AlignLeft);
  layout->addWidget(labelCreator.createLabelFromQString(article->getDescription()), 2, 0, 1, -1, Qt::AlignLeft);
  layout->setColumnStretch(0, 99);
  layout->addWidget(pushButton1, 0, 1);
  pushButton1->setText("Go to link");
  connect(pushButton1, SIGNAL(clicked()), this, SLOT(openBrowser(article->getUrl)));
  layout->addWidget(pushButton2, 1, 1);

  return layout;
}

void LayoutCreator::openBrowser(QString url) {
  std::cout << "na" << std::endl;
  QMessageBox msgBox;
  msgBox.setWindowTitle("Hello");
  msgBox.setText("You Clicked " + url);
  msgBox.exec();
  /*QWidget* widget = Q_NULLPTR;
  QWebEngineView *view = new QWebEngineView(widget);
  view->load(QUrl("url"));
  view->show();*/
}
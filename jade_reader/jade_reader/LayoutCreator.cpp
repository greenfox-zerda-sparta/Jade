#include "LayoutCreator.h"
#include "flowlayout.h"
#include <QPushButton>
#include <QLayout>
#include <QWidgetItem>
#include "RequestManager.h"

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
  layout->addWidget(pushButton2, 1, 1);

  RequestManager* manager = new RequestManager;
  connect(pushButton1, SIGNAL(clicked()), manager, SLOT(getFeed()));

  return layout;
}

/*void LayoutCreator::getFeed() {
  RequestManager* manager = new RequestManager;
  //qDebug() << manager->getRequest("http://zerda-reader-mockback.gomix.me/feed");
  QString email = "bogi@reader.com";
  QString pw = "bogi";
  qDebug() << manager->loginRequest(email, pw);
  delete manager;
}*/
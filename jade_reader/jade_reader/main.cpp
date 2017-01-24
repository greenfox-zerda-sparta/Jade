<<<<<<< HEAD
#include <iostream>
#include <QLabel>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QtGui>
#include <QtWidgets/QScrollBar>
#include "FileReader.h"
#include "JsonParser.h"
=======
#include "Application.h"
>>>>>>> f050155de8603328f9d58175dc83f1521d8d4482

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
<<<<<<< HEAD
  QWidget *window = new QWidget;
  QVBoxLayout *layout = new QVBoxLayout;

  layout->addWidget(new QScrollBar(0, layout ));
  

  for (int i = 0; i < titles.size(); ++i) {
    layout->addWidget(new QLabel(titles.at(i)));
    layout->addWidget(new QLabel(images.at(i)));
  }


  window->setLayout(layout);
  window->show();
=======
  Application application;
  application.run();
>>>>>>> f050155de8603328f9d58175dc83f1521d8d4482
  return app.exec();
}
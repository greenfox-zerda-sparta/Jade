#include <iostream>
#include <QLabel>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QtGui>
#include <QtWidgets/QScrollBar>
#include "FileReader.h"
#include "JsonParser.h"

int main(int argc, char *argv[]) {
  FileReader fileReader;
  std::string content = fileReader.readFromFileToString("test.json");

  const char* title_key = "title";
  const char* img_key = "img";
  JsonParser jsonParser;
  QStringList titles = jsonParser.parseFromStringToQStringList(content, title_key);
  QStringList images = jsonParser.parseFromStringToQStringList(content, img_key);

  for (int i = 0; i < titles.size(); ++i) {
    std::cout << titles.at(i).toUtf8().constData() << std::endl;
  }

  for (int i = 0; i < images.size(); ++i) {
    std::cout << images.at(i).toUtf8().constData() << std::endl;
  }

  QApplication app(argc, argv);
  QWidget *window = new QWidget;
  QVBoxLayout *layout = new QVBoxLayout;

  layout->addWidget(new QScrollBar(0, layout ));
  

  for (int i = 0; i < titles.size(); ++i) {
    layout->addWidget(new QLabel(titles.at(i)));
    layout->addWidget(new QLabel(images.at(i)));
  }


  window->setLayout(layout);
  window->show();
  return app.exec();
}
#include <iostream>
#include <QLabel>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QtGui>
#include "FileReader.h"
#include "JsonParser.h"

int main(int argc, char *argv[]) {
  FileReader fileReader;
  std::string content = fileReader.readFromFileToString("test.json");

  const char* title_key = "title";
  const char* img_key = "img";
  const char* description_key = "description";

  JsonParser jsonParser;
  QStringList titles = jsonParser.parseFromStringToQStringList(content, title_key);
  QStringList images = jsonParser.parseFromStringToQStringList(content, img_key);
  QStringList descriptions = jsonParser.parseFromStringToQStringList(content, description_key);

  for (int i = 0; i < titles.size(); ++i) {
    std::cout << titles.at(i).toUtf8().constData() << std::endl;
  }

  for (int i = 0; i < images.size(); ++i) {
    std::cout << images.at(i).toUtf8().constData() << std::endl;
  }

  QApplication app(argc, argv);
  QWidget *window = new QWidget();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->setSizeConstraint(QLayout::SetMaximumSize);

  for (int i = 0; i < titles.size(); ++i) {

    QLabel* label_t = new QLabel(titles.at(i));
    label_t->setWordWrap(true);
    layout->addWidget(label_t);

    QLabel* label_i = new QLabel(images.at(i));
    label_i->setWordWrap(true);
    layout->addWidget(label_i);

    QLabel* label_d = new QLabel(descriptions.at(i));
    label_d->setWordWrap(true);
    layout->addWidget(label_d);
 
  }

  window->setLayout(layout);

  window->show();
  return app.exec();
}
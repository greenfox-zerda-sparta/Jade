#include <iostream>
#include <QLabel>
#include <QtWidgets>
#include <QVBoxLayout>
#include "FileReader.h"
#include "JsonParser.h"

int main(int argc, char *argv[]) {
  FileReader fileReader;
  std::string content = fileReader.readFromFileToString("test.json");

  JsonParser jsonParser;
  QStringList titles = jsonParser.parseFromStringToQStringList(content);

  for (int i = 0; i < titles.size(); ++i) {
    std::cout << titles.at(i).toUtf8().constData() << std::endl;
  }

  QApplication app(argc, argv);
  QWidget *window = new QWidget;
  QVBoxLayout *layout = new QVBoxLayout;

  for (int i = 0; i < titles.size(); ++i) {
    layout->addWidget(new QLabel(titles.at(i)));
  }

  window->setLayout(layout);
  window->show();
  return app.exec();
}
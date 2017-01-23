#include <iostream>
#include <QLabel>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QtGui>
#include "FileReader.h"
#include "JsonParser.h"
#include "LabelCreator.h"

int main(int argc, char *argv[]) {
  FileReader fileReader;
  std::string content = fileReader.readFromFileToString("test.json");
  JsonParser jsonParser;
  std::vector <Article*> articles;
  articles = jsonParser.parseFromStringToArticleVector(content);

  QApplication app(argc, argv);
  QWidget *window = new QWidget();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->setSizeConstraint(QLayout::SetMaximumSize);
  LabelCreator labelCreator;

  for (int i = 0; i < articles.size(); ++i) {
    layout->addWidget(labelCreator.createLabelFromArticle(articles[i]));
  }

  window->setLayout(layout);

  window->show();
  return app.exec();
}
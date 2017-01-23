#include "Application.h"
#include "FileReader.h"
#include "JsonParser.h"
#include "LayoutCreator.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QtGui>

Application::Application() {
}


Application::~Application() {
}

void Application::run() {
	QWidget *window = new QWidget();
	FileReader fileReader;
	QString content = fileReader.readFromFileToQString("test.json");
	JsonParser jsonParser;
	QVector <Article*> articles;
	articles = jsonParser.parseFromStringToArticleVector(content);
	QVBoxLayout *layout = new QVBoxLayout(window);
	layout->setSizeConstraint(QLayout::SetMaximumSize);
  LayoutCreator layoutCreator;
	for (int i = 0; i < articles.size(); ++i) {
		layout->addLayout(layoutCreator.createLayout(articles[i]));
	}
	window->show();
}	
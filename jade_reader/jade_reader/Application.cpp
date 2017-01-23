#include "Application.h"



Application::Application() {
}


Application::~Application() {
}

void Application::run() {
	QWidget *window = new QWidget();
	FileReader fileReader;
	std::string content = fileReader.readFromFileToString("test.json");
	JsonParser jsonParser;
	std::vector <Article*> articles;
	articles = jsonParser.parseFromStringToArticleVector(content);
	QVBoxLayout *layout = new QVBoxLayout();
	layout->setSizeConstraint(QLayout::SetMaximumSize);
	LabelCreator labelCreator;
	for (int i = 0; i < articles.size(); ++i) {
		layout->addWidget(labelCreator.createLabelFromArticle(articles[i]));
	}

	window->setLayout(layout);
	window->show();
}	
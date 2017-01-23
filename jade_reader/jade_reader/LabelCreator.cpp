#include "LabelCreator.h"



LabelCreator::LabelCreator()
{
}


LabelCreator::~LabelCreator()
{
}

QLabel * LabelCreator::createLabelFromArticle(Article * article) {
	std::string label= "";
	label += article->getTitle() + "<br>" + article->getImg() + "<br>" + article->getDescription();
	QString qString = QString(label.c_str());
	QLabel* qLabel = new QLabel(qString);
	qLabel->setWordWrap(true);
	return qLabel;

}

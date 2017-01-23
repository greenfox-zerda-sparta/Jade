#include "LabelCreator.h"



LabelCreator::LabelCreator()
{
}


LabelCreator::~LabelCreator()
{
}

QLabel * LabelCreator::createLabelFromArticle(Article * article) {
	QString label= "";
	label += article->getTitle() + "<br>" + article->getImg() + "<br>" + article->getDescription();
	QLabel* qLabel = new QLabel(label);
	qLabel->setWordWrap(true);
	return qLabel;

}

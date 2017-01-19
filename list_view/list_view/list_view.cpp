#include "list_view.h"

list_view::list_view(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.label->setText("cica");
}

list_view::~list_view()
{

}

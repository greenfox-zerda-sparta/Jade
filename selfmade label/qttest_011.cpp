#include "qttest_011.h"
#include <QtWidgets/QLabel>

qttest_011::qttest_011(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    QLabel *label;
    label = new QLabel(this);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(10, 20, 40, 15));
    label->setText(QApplication::translate("qttest_011Class", "kacsa", Q_NULLPTR));   
}

qttest_011::~qttest_011()
{

}

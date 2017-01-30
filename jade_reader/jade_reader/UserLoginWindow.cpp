#include "UserLoginWindow.h"
#include <QFormLayout>

UserLoginWindow::UserLoginWindow(QWidget *parent) : QDialog(parent) {
  emailLineEdit = new QLineEdit(parent);
  passwordLineEdit = new QLineEdit(parent);
  QFormLayout* formLayout = new QFormLayout;
  formLayout->addRow(tr("&Email:"), emailLineEdit);
  formLayout->addRow(tr("&Password:"), passwordLineEdit);
  setLayout(formLayout);
}

UserLoginWindow::~UserLoginWindow() {}

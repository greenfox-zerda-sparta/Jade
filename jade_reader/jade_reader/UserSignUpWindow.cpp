#include "UserSignUpWindow.h"
#include <QFormLayout>

UserSignUpWindow::UserSignUpWindow(QWidget *parent): QDialog(parent) {
  emailLineEdit = new QLineEdit(parent);
  passwordLineEdit = new QLineEdit(parent);
  passwordAgainLineEdit = new QLineEdit(parent);

  QFormLayout* formLayout = new QFormLayout;
  setWindowTitle(tr("JADE READER"));
  formLayout->addRow(tr("&Email:"), emailLineEdit);
  formLayout->addRow(tr("&Password:"), passwordLineEdit);
  formLayout->addRow(tr("&Password again:"), passwordAgainLineEdit);

  signUpButton = new QPushButton(tr("Sign Up"));
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(signUpButton);
}

UserSignUpWindow::~UserSignUpWindow() {}

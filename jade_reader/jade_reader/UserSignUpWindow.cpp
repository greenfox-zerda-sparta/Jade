#include "UserSignUpWindow.h"


UserSignUpWindow::UserSignUpWindow(QWidget *parent): QDialog(parent) {
  emailLineEdit = new QLineEdit(parent);
  passwordLineEdit = new QLineEdit(parent);
  passwordAgainLineEdit = new QLineEdit(parent);
  signUpButton = new QPushButton(tr("Sign Up"));
  backButton = new QPushButton(tr("Back"));

  formLayout = new QFormLayout;
  setWindowTitle(tr("JADE READER"));
  formLayout->addRow(tr("&Email:"), emailLineEdit);
  formLayout->addRow(tr("&Password:"), passwordLineEdit);
  formLayout->addRow(tr("&Password again:"), passwordAgainLineEdit);
    
  mainLayout = new QVBoxLayout(this);
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(signUpButton);
  mainLayout->addWidget(backButton);

  connect(backButton, &QAbstractButton::clicked, this, &UserSignUpWindow::onPushButtonEvent);
}

void UserSignUpWindow::onPushButtonEvent() {
  emit sendRequest();
}

UserSignUpWindow::~UserSignUpWindow() {
  delete emailLineEdit;
  delete passwordLineEdit;
  delete passwordAgainLineEdit;
  delete signUpButton;
  delete backButton;
  delete formLayout;
  delete mainLayout;
}

#include "UserLoginWindow.h"
#include <QDebug>

UserLoginWindow::UserLoginWindow(QWidget *parent) : QDialog(parent) {
  emailLineEdit = new QLineEdit(parent);
  passwordLineEdit = new QLineEdit(parent);
  signInButton = new QPushButton(tr("Sign In"));
  signUpButton = new QPushButton(tr("Sign Up"));

  formLayout = new QFormLayout;
  setWindowTitle(tr("JADE READER"));
  formLayout->addRow(tr("&Email:"), emailLineEdit);
  formLayout->addRow(tr("&Password:"), passwordLineEdit);
  
  mainLayout = new QVBoxLayout(this);
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(signInButton);
  mainLayout->addWidget(signUpButton);

  connect(signUpButton, &QAbstractButton::clicked, this, &UserLoginWindow::onSignUpButtonEvent);
  connect(signInButton, &QAbstractButton::clicked, this, &UserLoginWindow::onSignInButtonEvent);
}

void UserLoginWindow::onSignUpButtonEvent() {
  emit sendRequest();
}

void UserLoginWindow::onSignInButtonEvent() {
  email = emailLineEdit->text();
  password = passwordLineEdit->text();
  qDebug() << email;
  qDebug() << password;
}
#include "UserLoginWindow.h"
#include <QDebug>
#include <QMessageBox>

UserLoginWindow::UserLoginWindow(QWidget *parent) : QDialog(parent) {
  logger = new Logger("UserLoginWindow", "DEBUG");
  emailLineEdit = new QLineEdit(parent);
  passwordLineEdit = new QLineEdit(parent);
  signInButton = new QPushButton(tr("Sign In"));
  signUpButton = new QPushButton(tr("Sign Up"));
  passwordLineEdit->setEchoMode(QLineEdit::Password);

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
  sendRequest();
}

void UserLoginWindow::onSignInButtonEvent() {
  if (emailLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty()) {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Jade Reader");
    msgBox.setText("Email or Password line is empty.");
    msgBox.exec();
    logger->error("Email or Password line is empty.");
  } else {
    email = emailLineEdit->text();
    password = passwordLineEdit->text();
    logger->debug(email);
    logger->debug(password);
  }
}

UserLoginWindow::~UserLoginWindow() {
  delete emailLineEdit;
  delete passwordLineEdit;
  delete signUpButton;
  delete signInButton;
  delete formLayout;
  delete mainLayout;
  delete logger;
}
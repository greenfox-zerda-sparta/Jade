#include "UserSignUpWindow.h"
#include <QDebug>
#include <QMessageBox>

UserSignUpWindow::UserSignUpWindow(QWidget *parent): QDialog(parent) {
  logger = new Logger("UserSignUpWindow", "DEBUG");
  emailLineEdit = new QLineEdit(parent);
  passwordLineEdit = new QLineEdit(parent);
  passwordAgainLineEdit = new QLineEdit(parent);
  signUpButton = new QPushButton(tr("Sign Up"));
  backButton = new QPushButton(tr("Back"));
  passwordLineEdit->setEchoMode(QLineEdit::Password);
  passwordAgainLineEdit->setEchoMode(QLineEdit::Password);

  formLayout = new QFormLayout;
  formLayout->addRow(tr("&Email:"), emailLineEdit);
  formLayout->addRow(tr("&Password:"), passwordLineEdit);
  formLayout->addRow(tr("&Password again:"), passwordAgainLineEdit);
    
  mainLayout = new QVBoxLayout(this);
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(signUpButton);
  mainLayout->addWidget(backButton);

  connect(backButton, &QAbstractButton::clicked, this, &UserSignUpWindow::onBackButtonEvent);
  connect(signUpButton, &QAbstractButton::clicked, this, &UserSignUpWindow::onSignUpButtonEvent);
}

void UserSignUpWindow::onBackButtonEvent() {
  sendRequest();
}

void UserSignUpWindow::onSignUpButtonEvent() {
  if (emailLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty()) {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Jade Reader");
    msgBox.setText("Email or Password line is empty.");
    msgBox.exec();
    logger->error("Email or Password line is empty.");
  } else if (passwordLineEdit->text().compare(passwordAgainLineEdit->text(), Qt::CaseSensitive) != 0) {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Jade Reader");
    msgBox.setText("Passwords don't match.");
    msgBox.exec();
  } else {
    email = emailLineEdit->text();
    password = passwordLineEdit->text();
    passwordAgain = passwordAgainLineEdit->text();
  }
}

UserSignUpWindow::~UserSignUpWindow() {
  delete emailLineEdit;
  delete passwordLineEdit;
  delete passwordAgainLineEdit;
  delete signUpButton;
  delete backButton;
  delete formLayout;
  delete mainLayout;
  delete logger;
}

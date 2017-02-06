#include "UserSignUpScreen.h"
#include <QDebug>
#include <QMessageBox>

UserSignUpScreen::UserSignUpScreen(QWidget *parent): QDialog(parent) {
  logger.reset(new Logger("UserSignUpWindow"));
  emailLineEdit.reset(new QLineEdit(parent));
  passwordLineEdit.reset(new QLineEdit(parent));
  passwordAgainLineEdit.reset(new QLineEdit(parent));
  signUpButton.reset(new QPushButton(tr("Sign Up")));
  backButton.reset(new QPushButton(tr("Back")));
  passwordLineEdit->setEchoMode(QLineEdit::Password);
  passwordAgainLineEdit->setEchoMode(QLineEdit::Password);

  formLayout.reset(new QFormLayout);
  formLayout->addRow(tr("&Email:"), emailLineEdit.data());
  formLayout->addRow(tr("&Password:"), passwordLineEdit.data());
  formLayout->addRow(tr("&Password again:"), passwordAgainLineEdit.data());

  mainLayout.reset(new QVBoxLayout(this));
  mainLayout->addLayout(formLayout.data());
  mainLayout->addWidget(signUpButton.data());
  mainLayout->addWidget(backButton.data());

  connect(backButton.data(), &QAbstractButton::clicked, this, &UserSignUpScreen::onBackButtonEvent);
  connect(signUpButton.data(), &QAbstractButton::clicked, this, &UserSignUpScreen::onSignUpButtonEvent);
}

void UserSignUpScreen::onBackButtonEvent() {
  switchToSignUpSignal();
}

void UserSignUpScreen::onSignUpButtonEvent() {
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
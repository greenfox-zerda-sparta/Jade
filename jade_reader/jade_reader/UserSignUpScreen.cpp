#include "UserSignUpScreen.h"

UserSignUpScreen::UserSignUpScreen(QWidget *parent): QDialog(parent) {
  logger.reset(new Logger("UserSignUpScreen"));
  emailLineEdit.reset(new QLineEdit(parent));
  passwordLineEdit.reset(new QLineEdit(parent));
  passwordAgainLineEdit.reset(new QLineEdit(parent));
  signUpButton.reset(new QPushButton(tr("Sign Up")));
  backButton.reset(new QPushButton(tr("Back")));
  formLayout.reset(new QFormLayout);
  mainLayout.reset(new QVBoxLayout(this));
  msgBox.reset(new QMessageBox);
  msgBox->setWindowTitle("Jade Reader");
  logger->info("Initializing...");

  definePasswordLinesMode();
  initFormLayout();
  initMainLayout();
  defineConnections();
}

void UserSignUpScreen::definePasswordLinesMode() {
  passwordLineEdit->setEchoMode(QLineEdit::Password);
  passwordAgainLineEdit->setEchoMode(QLineEdit::Password);
  logger->info("Define password lines mode");
}

void UserSignUpScreen::defineConnections() {
  connect(backButton.data(), &QAbstractButton::clicked, this, &UserSignUpScreen::onBackButtonEvent);
  connect(signUpButton.data(), &QAbstractButton::clicked, this, &UserSignUpScreen::onSignUpButtonEvent);
  logger->info("Define connections");
}

void UserSignUpScreen::initFormLayout() {
  formLayout->addRow(tr("&Email:"), emailLineEdit.data());
  formLayout->addRow(tr("&Password:"), passwordLineEdit.data());
  formLayout->addRow(tr("&Password again:"), passwordAgainLineEdit.data());
  logger->info("Init Form Layout");
}

void UserSignUpScreen::initMainLayout() {
  mainLayout->addLayout(formLayout.data());
  mainLayout->addWidget(signUpButton.data());
  mainLayout->addWidget(backButton.data());
  logger->info("Init Main Layout");
}

void UserSignUpScreen::onBackButtonEvent() {
  switchToLoginSignal();
  logger->info("Back button pushed...");
}

void UserSignUpScreen::onSignUpButtonEvent() {
  if (emailLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty()) {
    logger->error("Email or Password line is empty.");
    msgBox->setText("Email or Password line is empty.");
    msgBox->exec();
  } else if (passwordLineEdit->text().compare(passwordAgainLineEdit->text(), Qt::CaseSensitive) != 0) {
    logger->error("Passwords don't match.");
    msgBox->setText("Passwords don't match.");
    msgBox->exec();
  } else {
    logger->info("Send request to server...");
    email = emailLineEdit->text();
    password = passwordLineEdit->text();
    passwordAgain = passwordAgainLineEdit->text();
  }
}
#include "UserLoginScreen.h"
#include <QMessageBox>

UserLoginScreen::UserLoginScreen(QWidget *parent): QDialog(parent) {
  logger.reset(new Logger("UserLoginScreen"));
  emailLineEdit.reset(new QLineEdit(parent));
  passwordLineEdit.reset(new QLineEdit(parent));
  signInButton.reset(new QPushButton(tr("Sign In")));
  signUpButton.reset(new QPushButton(tr("Sign Up")));
  formLayout.reset(new QFormLayout);
  mainLayout.reset(new QVBoxLayout(this));
  logger->info("Initializing...");
  
  definePasswordLinesMode();
  initFormLayout();
  initMainLayout();
  defineConnections();
}

void UserLoginScreen::definePasswordLinesMode() {
  passwordLineEdit->setEchoMode(QLineEdit::Password);
  logger->info("Define password lines mode");
}

void UserLoginScreen::defineConnections() {
  connect(signUpButton.data(), &QAbstractButton::clicked, this, &UserLoginScreen::onSignUpButtonEvent);
  connect(signInButton.data(), &QAbstractButton::clicked, this, &UserLoginScreen::onSignInButtonEvent);
  logger->info("Define connections");
}

void UserLoginScreen::initFormLayout() {
  formLayout->addRow(tr("&Email:"), emailLineEdit.data());
  formLayout->addRow(tr("&Password:"), passwordLineEdit.data());
  logger->info("Init Form Layout");
}

void UserLoginScreen::initMainLayout() {
  mainLayout->addLayout(formLayout.data());
  mainLayout->addWidget(signInButton.data());
  mainLayout->addWidget(signUpButton.data());
  logger->info("Init Main Layout");
}

void UserLoginScreen::onSignUpButtonEvent() {
  switchToSignUpSignal();
  logger->info("Sign Up button pushed...");
}

void UserLoginScreen::onSignInButtonEvent() {
  logger->info("Sign In button pushed...");
  if (emailLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty()) {
    logger->error("Email or Password line is empty.");
    QMessageBox msgBox;
    msgBox.setWindowTitle("Jade Reader");
    msgBox.setText("Email or Password line is empty.");
    msgBox.exec();
  } else {
    email = emailLineEdit->text();
    password = passwordLineEdit->text();
    swithToFeedSignal();
  }
}
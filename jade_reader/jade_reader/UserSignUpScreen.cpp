#include "UserSignUpScreen.h"

UserSignUpScreen::UserSignUpScreen(QSharedPointer<HttpRequest> httpRequest, QWidget *parent)
  : QDialog(parent),
  logger(new Logger("UserSignUpScreen")),
  emailLineEdit(new QLineEdit(parent)),
  passwordLineEdit(new QLineEdit(parent)),
  passwordAgainLineEdit(new QLineEdit(parent)),
  signUpButton(new QPushButton(tr("Sign Up"))),
  backButton(new QPushButton(tr("Back"))),
  formLayout(new QFormLayout),
  mainLayout(new QVBoxLayout(this)),
  msgBox(new QMessageBox),
  authService(new AuthenticationService(httpRequest)) {
  
  msgBox->setWindowTitle("Jade Reader");
  logger->info("Initializing...");

  definePasswordLinesMode();
  initFormLayout();
  initMainLayout();
  defineConnections();
}

void UserSignUpScreen::definePasswordLinesMode() {
  logger->info("Define password lines mode");
  passwordLineEdit->setEchoMode(QLineEdit::Password);
  passwordAgainLineEdit->setEchoMode(QLineEdit::Password);
}

void UserSignUpScreen::defineConnections() {
  logger->info("Define connections");
  connect(backButton.data(), &QAbstractButton::clicked, this, &UserSignUpScreen::onBackButtonEvent);
  connect(signUpButton.data(), &QAbstractButton::clicked, this, &UserSignUpScreen::onSignUpButtonEvent); 
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
    resetLineEdits();
  } else if (passwordLineEdit->text().compare(passwordAgainLineEdit->text(), Qt::CaseSensitive) != 0) {
    logger->error("Passwords don't match.");
    msgBox->setText("Passwords don't match.");
    msgBox->exec();
    resetLineEdits();
  } else {
    logger->info("Send request to server...");
    email = emailLineEdit->text();
    password = passwordLineEdit->text();
    resetLineEdits();
    authService->postSignup(email, password);
  }
}

void UserSignUpScreen::resetLineEdits() {
  emailLineEdit->clear();
  passwordLineEdit->clear();
  passwordAgainLineEdit->clear();
}
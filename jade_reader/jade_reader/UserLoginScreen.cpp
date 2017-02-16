#include "UserLoginScreen.h"
#include "AuthenticationService.h"

UserLoginScreen::UserLoginScreen(QSharedPointer<HttpRequest> httpRequest, QWidget *parent) :
  QDialog(parent),
  logger(new Logger("UserLoginScreen")),
  emailLineEdit(new QLineEdit(parent)),
  passwordLineEdit(new QLineEdit(parent)),
  signInButton(new QPushButton(tr("Sign In"))),
  signUpButton(new QPushButton(tr("Sign Up"))),
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
    msgBox->setText("Email or Password line is empty.");
    msgBox->exec();
    resetLineEdits();
  } else {
    email = emailLineEdit->text();
    password = passwordLineEdit->text();
    authService->postLogin(email, password);
    resetLineEdits();
    swithToFeedSignal();
  }
}

void UserLoginScreen::resetLineEdits() {
  emailLineEdit->clear();
  passwordLineEdit->clear();
}

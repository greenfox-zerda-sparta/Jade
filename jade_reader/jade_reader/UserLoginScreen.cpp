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
  logger->info("Define password lines mode");
  passwordLineEdit->setEchoMode(QLineEdit::Password);
}

void UserLoginScreen::defineConnections() {
  logger->info("Define connections");
  connect(signUpButton.data(), &QAbstractButton::clicked, this, &UserLoginScreen::onSignUpButtonEvent);
  connect(signInButton.data(), &QAbstractButton::clicked, this, &UserLoginScreen::onSignInButtonEvent);
  connect(authService.data(), SIGNAL(onAuthenticated()), this, SIGNAL(loginSuccess()));
}

void UserLoginScreen::initFormLayout() {
  logger->info("Init Form Layout");
  formLayout->addRow(tr("&Email:"), emailLineEdit.data());
  formLayout->addRow(tr("&Password:"), passwordLineEdit.data());
}

void UserLoginScreen::initMainLayout() {
  logger->info("Init Main Layout");
  mainLayout->addLayout(formLayout.data());
  mainLayout->addWidget(signInButton.data());
  mainLayout->addWidget(signUpButton.data());
}

void UserLoginScreen::onSignUpButtonEvent() {
  logger->info("Sign Up button pushed...");
  switchToSignUpSignal();
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
  }
}

void UserLoginScreen::resetLineEdits() {
  emailLineEdit->clear();
  passwordLineEdit->clear();
}

#include "UserLoginWindow.h"
#include "UserSignUpWindow.h"
#include <QFormLayout>
#include <QDebug>

UserLoginWindow::UserLoginWindow(QWidget *parent) : QDialog(parent) {
  emailLineEdit = new QLineEdit(parent);
  passwordLineEdit = new QLineEdit(parent);

  QFormLayout* formLayout = new QFormLayout;
  setWindowTitle(tr("JADE READER"));
  formLayout->addRow(tr("&Email:"), emailLineEdit);
  formLayout->addRow(tr("&Password:"), passwordLineEdit);

  signInButton = new QPushButton(tr("Sign In"));
  signUpButton = new QPushButton(tr("Sign Up"));
  QVBoxLayout *mainLayout = new QVBoxLayout(this);
  mainLayout->addLayout(formLayout);
  mainLayout->addWidget(signInButton);
  mainLayout->addWidget(signUpButton);
  //connect(signUpButton, &QAbstractButton::clicked, this, &UserLoginWindow::openSignUpWindow);
  connect(signUpButton, &QAbstractButton::clicked, this, &UserLoginWindow::onEvent);
}

void UserLoginWindow::onEvent() {
  qDebug() << "on event";
  emit sendRequest();
}

void UserLoginWindow::openSignUpWindow() {
  UserSignUpWindow* userSignUpWindow = new UserSignUpWindow();
  userSignUpWindow->show();
}

UserLoginWindow::~UserLoginWindow() {}

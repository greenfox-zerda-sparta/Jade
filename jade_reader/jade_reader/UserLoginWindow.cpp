#include "UserLoginWindow.h"
#include <QFormLayout>

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
}

UserLoginWindow::~UserLoginWindow() {}

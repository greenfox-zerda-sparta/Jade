#include "WindowManager.h"
#include "UserLoginWindow.h"
#include "UserSignUpWindow.h"

WindowManager::WindowManager() {
  loginPageWidget = new UserLoginWindow;
  signUpPageWidget = new UserSignUpWindow;
  setWindowTitle(tr("Jade Reader"));

  centralWidget = new QWidget();

  stackedWidget = new QStackedWidget;
  stackedWidget->addWidget(loginPageWidget);
  stackedWidget->addWidget(signUpPageWidget);

  layout = new QVBoxLayout;
  layout->addWidget(stackedWidget);

  setCentralWidget(centralWidget);
  centralWidget->setLayout(layout);
  connect(loginPageWidget, SIGNAL(sendRequest()), this, SLOT(changePage()));
  connect(signUpPageWidget, SIGNAL(sendRequest()), this, SLOT(changePage()));
}

void WindowManager::changePage() {
  if (stackedWidget->currentIndex() == 0) {
    stackedWidget->setCurrentIndex(1);
  } else if (stackedWidget->currentIndex() == 1) {
    stackedWidget->setCurrentIndex(0);
  }
}

WindowManager::~WindowManager() {
  delete loginPageWidget;
  delete signUpPageWidget;
  delete centralWidget;
  delete layout;
  delete stackedWidget;
}

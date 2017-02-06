#include "ScreenManager.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"

ScreenManager::ScreenManager() {
  stackedWidget = new QStackedWidget;
  centralWidget = new QWidget;
  containerLayout = new QVBoxLayout;
  loginScreenWidget = new UserLoginScreen;
  signUpScreenWidget = new UserSignUpScreen;
  feedScreen = new QScrollArea;
  init();
  connect(loginScreenWidget, SIGNAL(switchToSignUpSignal()), this, SLOT(switchSignUpScreen()));
  connect(signUpScreenWidget, SIGNAL(switchToLoginSignal()), this, SLOT(switchLoginScreen()));
  connect(loginScreenWidget, SIGNAL(swithToFeedSignal()), this, SLOT(switchFeedScreen()));
}

ScreenManager::~ScreenManager() {
  delete loginScreenWidget;
  delete signUpScreenWidget;
  delete feedScreen;
  delete stackedWidget;
  delete centralWidget;
  delete containerLayout;
}

void ScreenManager::init() {
  setWindowTitle(tr("Jade Reader"));
  stackedWidget->addWidget(loginScreenWidget);
  stackedWidget->addWidget(signUpScreenWidget);
  stackedWidget->addWidget(feedScreen);
  containerLayout->addWidget(stackedWidget);
  setCentralWidget(centralWidget);
  centralWidget->setLayout(containerLayout);
}

void ScreenManager::switchLoginScreen() {
  stackedWidget->setCurrentIndex(0);
}

void ScreenManager::switchSignUpScreen() {
  stackedWidget->setCurrentIndex(1);
 }

void ScreenManager::switchFeedScreen() {
  stackedWidget->setCurrentIndex(2);
}
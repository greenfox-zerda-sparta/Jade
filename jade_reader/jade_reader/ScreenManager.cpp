#include "ScreenManager.h"



ScreenManager::ScreenManager() {
  stackedWidget = new QStackedWidget;
  centralWidget = new QWidget;
  containerLayout = new QVBoxLayout;
  loginScreenWidget = new QWidget;
  signUpScreenWidget = new QWidget;
  feedScreen = new QScrollArea;
  init();
  connect(loginScreenWidget, SIGNAL(sendRequest()), this, SLOT(switchScreen()));
  connect(signUpScreenWidget, SIGNAL(sendRequest()), this, SLOT(switchScreen()));
  connect(feedScreen, SIGNAL(sendRequest()), this, SLOT(switchScreen()));
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

void ScreenManager::switchScreen() {

}
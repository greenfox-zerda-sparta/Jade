#include "ScreenManager.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "FeedWindow.h"
#include "FileReader.h"
#include "JsonParser.h"

ScreenManager::ScreenManager() : 
  logger(new Logger("ScreenManager")), 
  httpRequest(new HttpRequest),
  stackedWidget(new QStackedWidget),
  centralWidget(new QWidget),
  containerLayout(new QVBoxLayout),
  loginScreenWidget(new UserLoginScreen(httpRequest)),
  signUpScreenWidget(new UserSignUpScreen(httpRequest)),
  feedScreenWidget(new FeedWindow(httpRequest)) {
  init();
  connect(loginScreenWidget.data(), SIGNAL(switchToSignUpSignal()), this, SLOT(switchSignUpScreen()));
  connect(signUpScreenWidget.data(), SIGNAL(switchToLoginSignal()), this, SLOT(switchLoginScreen()));
  connect(loginScreenWidget.data(), SIGNAL(switchToFeedSignal()), this, SLOT(switchFeedScreen()));
  connect(feedScreenWidget.data(), SIGNAL(signOutSignal()), this, SLOT(signOutSlot()));
  connect(this, SIGNAL(loadFeed()), feedScreenWidget.data(), SIGNAL(refreshSignal()));
}

void ScreenManager::init() {
  setWindowTitle(tr("Jade Reader"));
  stackedWidget->addWidget(loginScreenWidget.data());
  stackedWidget->addWidget(signUpScreenWidget.data());
  stackedWidget->addWidget(feedScreenWidget.data());
  containerLayout->addWidget(stackedWidget.data());
  setCentralWidget(centralWidget.data());
  centralWidget->setLayout(containerLayout.data());
}

void ScreenManager::switchLoginScreen() {
  setScreen(loginScreen);
}

void ScreenManager::switchSignUpScreen() {
  setScreen(signUpScreen);
}

void ScreenManager::switchFeedScreen() {
  loadFeed();
  setScreen(feedScreen);
}

void ScreenManager::signOutSlot() {
  stackedWidget->setCurrentIndex(0);
}

void ScreenManager::setScreen(Screens screen) {
  stackedWidget->setCurrentIndex(screen);
}
#include "ScreenManager.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "AuthenticationService.h"
#include "FeedWindow.h"
#include "FileReader.h"
#include "JsonParser.h"
#include "Config.h"

ScreenManager::ScreenManager() : 
  logger(new Logger("ScreenManager")), 
  httpRequest(new HttpRequest),
  feedService(new FeedService(httpRequest)),
  stackedWidget(new QStackedWidget),
  centralWidget(new QWidget),
  containerLayout(new QVBoxLayout),
  loginScreenWidget(new UserLoginScreen(httpRequest)),
  signUpScreenWidget(new UserSignUpScreen(httpRequest)),
  feedScreenWidget(new FeedWindow(httpRequest)) {
  init();
  defineConnections();
}

void ScreenManager::init() {
  setWindowTitle(tr("Jade Reader"));
  stackedWidget->addWidget(feedScreenWidget.data());
  stackedWidget->addWidget(loginScreenWidget.data());
  stackedWidget->addWidget(signUpScreenWidget.data());
  containerLayout->addWidget(stackedWidget.data());
  setCentralWidget(centralWidget.data());
  centralWidget->setLayout(containerLayout.data());
}

void ScreenManager::defineConnections() {
  connect(signUpScreenWidget.data(), SIGNAL(switchToLoginSignal()), this, SLOT(showLoginScreen()));
  connect(loginScreenWidget.data(), SIGNAL(switchToSignUpSignal()), this, SLOT(switchSignUpScreen()));
  connect(loginScreenWidget.data(), SIGNAL(loginSuccess()), this, SLOT(fetchFeed()));
  connect(feedScreenWidget.data(), SIGNAL(signOutSignal()), this, SLOT(showLoginScreen()));
  connect(feedScreenWidget.data(), SIGNAL(refreshSignal()), this, SLOT(fetchFeed()));
  connect(feedService.data(), SIGNAL(onReady()), this, SLOT(showFeedScreen()));
}

void ScreenManager::showLoginScreen() {
  setScreen(loginScreen);
}

void ScreenManager::switchSignUpScreen() {
  setScreen(signUpScreen);
}

void ScreenManager::fetchFeed() {
  logger->info("Fetching Feed");
  feedService->sendRequestData();
  logger->info("Waiting for the server response");
}

void ScreenManager::showFeedScreen() {
  logger->info("Show Feed Screen");
  feedScreenWidget->loadFeed(feedService->getArticles().data());
  setScreen(feedScreen);
}

void ScreenManager::setScreen(Screens screen) {
  stackedWidget->setCurrentIndex(screen);
}
#include "ScreenManager.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "FeedWindow.h"

ScreenManager::ScreenManager() {
  stackedWidget = new QStackedWidget;
  centralWidget = new QWidget;
  containerLayout = new QVBoxLayout;
  feedService = new FeedService;
  loginScreenWidget = new UserLoginScreen;
  signUpScreenWidget = new UserSignUpScreen;
  feedScreenWidget = new FeedWindow;
  init();
  connect(loginScreenWidget, SIGNAL(switchToSignUpSignal()), this, SLOT(switchSignUpScreen()));
  connect(signUpScreenWidget, SIGNAL(switchToLoginSignal()), this, SLOT(switchLoginScreen()));
  connect(loginScreenWidget, SIGNAL(swithToFeedSignal()), this, SLOT(getFeed()));
  connect(feedService, SIGNAL(onReady(QVector<Article*>*)), this, SLOT(loadFeed(QVector<Article*>*)));
}

ScreenManager::~ScreenManager() {
  delete loginScreenWidget;
  delete signUpScreenWidget;
  delete feedScreenWidget;
  delete stackedWidget;
  delete containerLayout;
  delete centralWidget;
  delete feedService;
}

void ScreenManager::init() {
  setWindowTitle(tr("Jade Reader"));
  stackedWidget->addWidget(loginScreenWidget);
  stackedWidget->addWidget(signUpScreenWidget);
  stackedWidget->addWidget(feedScreenWidget);
  containerLayout->addWidget(stackedWidget);
  setCentralWidget(centralWidget);
  centralWidget->setLayout(containerLayout);
}

void ScreenManager::switchLoginScreen() {
  setScreen(loginScreen);
}

void ScreenManager::switchSignUpScreen() {
  setScreen(signUpScreen);
}

void ScreenManager::switchFeedScreen() {
  setScreen(feedScreen);
}

void ScreenManager::refreshFeedScreen(FeedWindow* feedScreen) {
  this->feedScreenWidget = feedScreen;
}

void ScreenManager::getFeed() {
  feedService->getFeed();
}

void ScreenManager::loadFeed(QVector<Article*>* articles) {
  feedScreenWidget->createWindow(*articles);
  stackedWidget->setCurrentIndex(2);
}

void ScreenManager::setScreen(Screens screen) {
  stackedWidget->setCurrentIndex(screen);
}
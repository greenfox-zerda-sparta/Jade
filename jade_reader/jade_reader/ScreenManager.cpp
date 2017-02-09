#include "ScreenManager.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "FeedWindow.h"

ScreenManager::ScreenManager() {
  stackedWidget = new QStackedWidget;
  centralWidget = new QWidget;
  containerLayout = new QVBoxLayout;
  feedService = new FeedService;
  this->loginScreenWidget = new UserLoginScreen;
  this->signUpScreenWidget = new UserSignUpScreen;
  this->feedScreen = new FeedWindow;
  init();
  connect(loginScreenWidget, SIGNAL(switchToSignUpSignal()), this, SLOT(switchSignUpScreen()));
  connect(signUpScreenWidget, SIGNAL(switchToLoginSignal()), this, SLOT(switchLoginScreen()));
  connect(loginScreenWidget, SIGNAL(swithToFeedSignal()), this, SLOT(getFeed()));
  connect(feedService, SIGNAL(onReady(QVector<Article*>*)), this, SLOT(loadFeed(QVector<Article*>*)));
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

void ScreenManager::refreshFeedScreen(FeedWindow* feedScreen) {
  this->feedScreen = feedScreen;
}

void ScreenManager::getFeed() {
  feedService->getFeed();
}

void ScreenManager::loadFeed(QVector<Article*>* articles) {
  feedScreen->createWindow(*articles);
  stackedWidget->setCurrentIndex(2);
}
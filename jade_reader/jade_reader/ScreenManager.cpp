#include "ScreenManager.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "FeedWindow.h"
#include "FileReader.h"
#include "JsonParser.h"

ScreenManager::ScreenManager(QWidget* loginScreenWidget, QWidget* signUpScreenWidget, FeedWindow* feedScreen) {
  stackedWidget = new QStackedWidget;
  centralWidget = new QWidget;
  containerLayout = new QVBoxLayout;
  feedService = new FeedService;
  this->loginScreenWidget = loginScreenWidget;
  this->signUpScreenWidget = signUpScreenWidget;
  this->feedScreen = feedScreen;
  init();
  connect(loginScreenWidget, SIGNAL(switchToSignUpSignal()), this, SLOT(switchSignUpScreen()));
  connect(signUpScreenWidget, SIGNAL(switchToLoginSignal()), this, SLOT(switchLoginScreen()));
  connect(loginScreenWidget, SIGNAL(swithToFeedSignal()), this, SLOT(loadEmptyFeed()));
  connect(feedService, SIGNAL(onReady(QVector<Article*>*)), this, SLOT(loadFeed(QVector<Article*>*)));
  connect(feedScreen, SIGNAL(refreshSignal()), this, SLOT(getFeed()));
  connect(feedScreen, SIGNAL(signOutSignal()), this, SLOT(signOutSlot()));
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
  feedScreen->refreshFeedScreen(articles);
  qDebug() << "loadFeed " << articles->size();
  feedScreen->createWindow(*articles);
}

void ScreenManager::loadEmptyFeed() {
  FileReader fileReader;
  JsonParser jsonParser;
  QVector<Article*> articles;
  QString content = fileReader.readFromFileToQString("test.json");
  articles = jsonParser.parseFromStringToArticleVector(content);
  stackedWidget->addWidget(feedScreen);
  feedScreen->createWindow(articles);
  stackedWidget->setCurrentIndex(2);
}

void ScreenManager::signOutSlot() {
  stackedWidget->setCurrentIndex(0);
  //loadFeed(articles);
}
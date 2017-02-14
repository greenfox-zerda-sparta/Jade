#include "ScreenManager.h"
#include "UserLoginScreen.h"
#include "UserSignUpScreen.h"
#include "FeedWindow.h"
#include "FileReader.h"
#include "JsonParser.h"

ScreenManager::ScreenManager() : logger(new Logger("ScreenManager")), httpRequest(new HttpRequest) {
  stackedWidget = new QStackedWidget;
  centralWidget = new QWidget;
  containerLayout = new QVBoxLayout;
  loginScreenWidget = new UserLoginScreen;
  signUpScreenWidget = new UserSignUpScreen;
  feedScreenWidget = new FeedWindow(httpRequest);
  init();
  connect(loginScreenWidget, SIGNAL(switchToSignUpSignal()), this, SLOT(switchSignUpScreen()));
  connect(signUpScreenWidget, SIGNAL(switchToLoginSignal()), this, SLOT(switchLoginScreen()));
  connect(loginScreenWidget, SIGNAL(swithToFeedSignal()), this, SLOT(loadEmptyFeed()));
  connect(feedScreenWidget, SIGNAL(signOutSignal()), this, SLOT(signOutSlot()));
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

void ScreenManager::loadEmptyFeed() {
  FileReader fileReader;
  JsonParser jsonParser;
  QVector<Article*> articles;
  QString content = fileReader.readFromFileToQString("test.json");
  articles = jsonParser.parseFromStringToArticleVector(content);
  feedScreenWidget->createWindow(articles);
  stackedWidget->addWidget(feedScreenWidget);
  stackedWidget->setCurrentIndex(2);
}

void ScreenManager::signOutSlot() {
  stackedWidget->setCurrentIndex(0);
}

void ScreenManager::setScreen(Screens screen) {
  stackedWidget->setCurrentIndex(screen);
}
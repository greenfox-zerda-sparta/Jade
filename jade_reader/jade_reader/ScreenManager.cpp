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
  connect(loginScreenWidget.data(), SIGNAL(swithToFeedSignal()), this, SLOT(loadEmptyFeed()));
  connect(feedScreenWidget.data(), SIGNAL(signOutSignal()), this, SLOT(signOutSlot()));
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
  setScreen(feedScreen);
}

void ScreenManager::loadEmptyFeed() {
  FileReader fileReader;
  JsonParser jsonParser;
  QVector<Article*> articles;
  QString content = fileReader.readFromFileToQString("test.json");
  articles = jsonParser.parseFromObjectToArticleVector(jsonParser.parseToJsonObject(content));
  feedScreenWidget->createWindow(articles);
  stackedWidget->addWidget(feedScreenWidget.data());
  stackedWidget->setCurrentIndex(2);
}

void ScreenManager::signOutSlot() {
  stackedWidget->setCurrentIndex(0);
}

void ScreenManager::setScreen(Screens screen) {
  stackedWidget->setCurrentIndex(screen);
}
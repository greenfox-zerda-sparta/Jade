#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScopedPointer>
#include "FeedService.h"
#include "FeedWindow.h"
#include "Logger.h"

enum Screens {loginScreen, signUpScreen, feedScreen};

class ScreenManager : public QMainWindow {
  Q_OBJECT
private:
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
  QScopedPointer<FeedService> feedService;
  QScopedPointer<QStackedWidget> stackedWidget;
  QScopedPointer<QWidget> centralWidget;
  QScopedPointer<QVBoxLayout> containerLayout;
  QScopedPointer<QWidget> loginScreenWidget;
  QScopedPointer<QWidget> signUpScreenWidget;
  QScopedPointer<FeedWindow> feedScreenWidget;
  void setScreen(Screens);
  void init();
public:
  ScreenManager();
public slots:
  void switchLoginScreen();
  void switchSignUpScreen();
  void switchFeedScreen();
  void loadEmptyFeed();
  void signOutSlot();
};


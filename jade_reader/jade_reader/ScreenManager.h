#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QScopedPointer>
#include "FeedService.h"
#include "FeedWindow.h"
#include "Logger.h"

enum Screens {feedScreen, loginScreen, signUpScreen};

class ScreenManager : public QMainWindow {
  Q_OBJECT
signals:
  void loadFeed();
private:
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
  QSharedPointer<FeedService> feedService;
  QScopedPointer<QStackedWidget> stackedWidget;
  QScopedPointer<QWidget> centralWidget;
  QScopedPointer<QVBoxLayout> containerLayout;
  QScopedPointer<QWidget> loginScreenWidget;
  QScopedPointer<QWidget> signUpScreenWidget;
  QScopedPointer<FeedWindow> feedScreenWidget;
  void setScreen(Screens);
  void init();
  void defineConnections();
public:
  ScreenManager();
public slots:
  void fetchFeed();
  void showLoginScreen();
  void switchSignUpScreen();
  void showFeedScreen();
};


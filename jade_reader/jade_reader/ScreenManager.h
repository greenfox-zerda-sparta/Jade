#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "FeedService.h"
#include "FeedWindow.h"
#include "Logger.h"

enum Screens {loginScreen, signUpScreen, feedScreen};

class ScreenManager : public QMainWindow {
  Q_OBJECT
private:
  QStackedWidget* stackedWidget;
  QWidget* centralWidget;
  QVBoxLayout* containerLayout;
  QWidget* loginScreenWidget;
  QWidget* signUpScreenWidget;
  FeedWindow* feedScreenWidget;
  FeedService* feedService;
  QScopedPointer<Logger> logger;
  QSharedPointer<HttpRequest> httpRequest;
  void setScreen(Screens);
  void init();
public:
  ScreenManager();
  ~ScreenManager();
  void refreshFeedScreen(FeedWindow*);
public slots:
  void switchLoginScreen();
  void switchSignUpScreen();
  void switchFeedScreen();
 /* void getFeed();
  void loadFeed(QVector<Article*>*);*/
  void loadEmptyFeed();
  void signOutSlot();
};


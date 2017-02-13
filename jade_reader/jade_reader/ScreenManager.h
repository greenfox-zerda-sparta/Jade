#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "FeedService.h"
#include "FeedWindow.h"

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
  void getFeed();
  void loadFeed(QVector<Article*>*);
};


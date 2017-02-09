#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "FeedService.h"
#include "FeedWindow.h"

class ScreenManager : public QMainWindow {
  Q_OBJECT
private:
  QStackedWidget* stackedWidget;
  QWidget* centralWidget;
  QVBoxLayout* containerLayout;
  QWidget* loginScreenWidget;
  QWidget* signUpScreenWidget;
  FeedWindow* feedScreen;
  FeedService* feedService;
  void init();
public:
  ScreenManager(QWidget* loginScreenWidget, QWidget* signUpScreenWidget, FeedWindow* feedScreen);
  ~ScreenManager();
  void refreshFeedScreen(FeedWindow*);
public slots:
  void switchLoginScreen();
  void switchSignUpScreen();
  void switchFeedScreen();
  void getFeed();
  void loadFeed(QVector<Article*>*);
  void loadEmptyFeed();
  void signOutSlot();
};


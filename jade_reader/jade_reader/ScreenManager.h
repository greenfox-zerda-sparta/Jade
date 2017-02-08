#pragma once
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>

class ScreenManager : public QMainWindow {
  Q_OBJECT
private:
  QStackedWidget* stackedWidget;
  QWidget* centralWidget;
  QVBoxLayout* containerLayout;
  QWidget* loginScreenWidget;
  QWidget* signUpScreenWidget;
  QScrollArea* feedScreen;
  void init();
public:
  ScreenManager(QWidget* loginScreenWidget, QWidget* signUpScreenWidget, QScrollArea* feedScreen);
  ~ScreenManager();
  void refreshFeedScreen(QScrollArea*);
public slots:
  void switchLoginScreen();
  void switchSignUpScreen();
  void switchFeedScreen();
};


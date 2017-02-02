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
  ScreenManager();
  ~ScreenManager();
public slots:
  void switchScreen();
};


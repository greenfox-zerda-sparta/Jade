#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>

class WindowManager : public QMainWindow {
  Q_OBJECT
private:
  QStackedWidget* stackedWidget;
  QWidget* loginPageWidget;
  QWidget* signUpPageWidget;
  QWidget* centralWidget;
  QVBoxLayout* layout;
public:
  WindowManager();
  ~WindowManager();
public slots:
  void changePage();
};


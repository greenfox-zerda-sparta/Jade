#pragma once

#include <QWidget>
#include <QDialog>
#include <QMainWindow>
#include <QStackedWidget>

class WindowManager : public QMainWindow {
  Q_OBJECT
private:
  QStackedWidget* stackedWidget;
  QWidget* firstPageWidget;
  QWidget* secondPageWidget;
public:
  WindowManager();
  ~WindowManager();
public slots:
  void changePage();
};


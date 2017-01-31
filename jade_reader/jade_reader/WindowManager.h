#pragma once

#include <QWidget>
#include <QDialog>
#include <QMainWindow>

class WindowManager : public QMainWindow {
  Q_OBJECT
private:
  QWidget* firstPageWidget;
  QWidget* secondPageWidget;
  QWidget* thirdPageWidget;
public:
  WindowManager();
  ~WindowManager();
};


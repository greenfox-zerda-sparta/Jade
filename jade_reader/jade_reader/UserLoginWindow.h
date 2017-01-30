#pragma once

#include <QDialog>
#include <QLineEdit>

class UserLoginWindow : public QDialog {
  Q_OBJECT
private:
  QLineEdit* emailLineEdit;
  QLineEdit* passwordLineEdit;
  
public:
  explicit UserLoginWindow(QWidget* parent = Q_NULLPTR);
  ~UserLoginWindow();
};


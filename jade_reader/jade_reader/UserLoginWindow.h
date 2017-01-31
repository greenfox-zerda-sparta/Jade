#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class UserLoginWindow : public QDialog {
  Q_OBJECT
signals :
  void sendRequest();
private:
  QLineEdit* emailLineEdit;
  QLineEdit* passwordLineEdit;
  QPushButton* signInButton;
  QPushButton* signUpButton;
public slots:
  void onEvent();
public:
  explicit UserLoginWindow(QWidget* parent = Q_NULLPTR);
};


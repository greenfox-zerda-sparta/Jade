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
private slots:
  void openSignUpWindow();
public slots:
  void onEvent();
public:
  explicit UserLoginWindow(QWidget* parent = Q_NULLPTR);
  ~UserLoginWindow();
  QPushButton* signUpButton;
};


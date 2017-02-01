#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class UserLoginWindow : public QDialog {
  Q_OBJECT
signals :
  void sendRequest();
private:
  QLineEdit* emailLineEdit;
  QLineEdit* passwordLineEdit;
  QPushButton* signInButton;
  QPushButton* signUpButton;
  QFormLayout* formLayout;
  QVBoxLayout* mainLayout;
  QString email;
  QString password;
private slots:
  void onSignUpButtonEvent();
  void onSignInButtonEvent();
public:
  explicit UserLoginWindow(QWidget* parent = Q_NULLPTR);
  ~UserLoginWindow();;
};


#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QString>
#include "Logger.h"

class UserSignUpWindow : public QDialog {
  Q_OBJECT 
signals:
  void sendRequest();
private:
  Logger* logger;
  QFormLayout* formLayout;
  QVBoxLayout* mainLayout;
  QLineEdit* emailLineEdit;
  QLineEdit* passwordLineEdit;
  QLineEdit* passwordAgainLineEdit;
  QPushButton* signUpButton;
  QPushButton* backButton;
  QString email;
  QString password;
  QString passwordAgain;
private slots:
  void onBackButtonEvent();
  void onSignUpButtonEvent();
public:
  explicit UserSignUpWindow(QWidget* parent = Q_NULLPTR);
  ~UserSignUpWindow();
};


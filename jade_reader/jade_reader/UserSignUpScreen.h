#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QString>
#include <QScopedPointer>
#include "Logger.h"

class UserSignUpScreen: public QDialog {
  Q_OBJECT
signals :
  void switchToSignUpSignal();
private:
  QScopedPointer<Logger> logger;
  QScopedPointer<QFormLayout> formLayout;
  QScopedPointer<QVBoxLayout> mainLayout;
  QScopedPointer<QLineEdit> emailLineEdit;
  QScopedPointer<QLineEdit> passwordLineEdit;
  QScopedPointer<QLineEdit> passwordAgainLineEdit;
  QScopedPointer<QPushButton> signUpButton;
  QScopedPointer<QPushButton> backButton;
  QString email;
  QString password;
  QString passwordAgain;
  void definePasswordLinesMode();
  void defineConnections();
  void initFormLayout();
  void initMainLayout();
private slots:
  void onBackButtonEvent();
  void onSignUpButtonEvent();
public:
  explicit UserSignUpScreen(QWidget* parent = Q_NULLPTR);
};

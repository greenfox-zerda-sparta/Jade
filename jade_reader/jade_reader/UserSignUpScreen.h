#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QString>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QMessageBox>
#include "Logger.h"
#include "AuthenticationService.h"

class UserSignUpScreen: public QDialog {
  Q_OBJECT
signals :
  void switchToLoginSignal();
private slots:
  void onBackButtonEvent();
  void onSignUpButtonEvent();
private:
  QScopedPointer<Logger> logger;
  QScopedPointer<AuthenticationService> authService;
  QScopedPointer<QFormLayout> formLayout;
  QScopedPointer<QVBoxLayout> mainLayout;
  QScopedPointer<QLineEdit> emailLineEdit;
  QScopedPointer<QLineEdit> passwordLineEdit;
  QScopedPointer<QLineEdit> passwordAgainLineEdit;
  QScopedPointer<QPushButton> signUpButton;
  QScopedPointer<QPushButton> backButton;
  QScopedPointer<QMessageBox> msgBox;
  QSharedPointer<HttpRequest> httpRequest;
  QString email;
  QString password;
  QString passwordAgain;
  void definePasswordLinesMode();
  void defineConnections();
  void initFormLayout();
  void initMainLayout();
public:
  explicit UserSignUpScreen(QSharedPointer<HttpRequest> httpRequest, QWidget* parent = Q_NULLPTR);
  void resetLineEdits();
};

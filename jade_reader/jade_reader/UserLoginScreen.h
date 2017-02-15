#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QMessageBox>
#include "Logger.h"
#include "AuthenticationService.h"

class UserLoginScreen: public QDialog {
  Q_OBJECT
signals :
  void switchToSignUpSignal();
  void swithToFeedSignal();
private slots:
  void onSignUpButtonEvent();
  void onSignInButtonEvent();
private:
  QScopedPointer<Logger> logger;
  QScopedPointer<AuthenticationService> authService;
  QScopedPointer<QLineEdit> emailLineEdit;
  QScopedPointer<QLineEdit> passwordLineEdit;
  QScopedPointer<QPushButton> signInButton;
  QScopedPointer<QPushButton> signUpButton;
  QScopedPointer<QFormLayout> formLayout;
  QScopedPointer<QVBoxLayout> mainLayout;
  QScopedPointer<QMessageBox> msgBox;
  QSharedPointer<HttpRequest> httpRequest;
  QString email;
  QString password;
  void definePasswordLinesMode();
  void defineConnections();
  void initFormLayout();
  void initMainLayout();
public:
  explicit UserLoginScreen(QSharedPointer<HttpRequest> httpRequest, QWidget* parent = Q_NULLPTR);
};

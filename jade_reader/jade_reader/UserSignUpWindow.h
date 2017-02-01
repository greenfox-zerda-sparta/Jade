#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class UserSignUpWindow : public QDialog {
  Q_OBJECT 
signals:
  void sendRequest();
private:
  QFormLayout* formLayout;
  QVBoxLayout* mainLayout;
  QLineEdit* emailLineEdit;
  QLineEdit* passwordLineEdit;
  QLineEdit* passwordAgainLineEdit;
  QPushButton* signUpButton;
  QPushButton* backButton;
private slots:
  void onPushButtonEvent();
public:
  explicit UserSignUpWindow(QWidget* parent = Q_NULLPTR);
  ~UserSignUpWindow();
};


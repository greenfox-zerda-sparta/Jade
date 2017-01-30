#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class UserSignUpWindow : public QDialog {
  Q_OBJECT 
private:
  QLineEdit* emailLineEdit;
  QLineEdit* passwordLineEdit;
  QLineEdit* passwordAgainLineEdit;
  QPushButton* signUpButton;
public:
  explicit UserSignUpWindow(QWidget* parent = Q_NULLPTR);
  ~UserSignUpWindow();
};


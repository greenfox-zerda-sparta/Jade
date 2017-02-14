#include "PostData.h"

PostData::PostData() {}

PostData::PostData(QString email, QString password) {
  this->email = email;
  this->password = password;
}

QString PostData::getEmail() {
  return email;
}

void PostData::setEmail(QString email) {
  this->email = email;
}

QString PostData::getPassword() {
  return password;
}

void PostData::setPassword(QString password) {
  this->password = password;
}

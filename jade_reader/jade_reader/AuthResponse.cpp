#include "AuthResponse.h"

AuthResponse::AuthResponse() {
  this->result = "";
  this->message = "";
  this->token = "";
}

QString AuthResponse::getResult() {
  return result;
}

void AuthResponse::setResult(QString result) {
  this->result = result;
}

QString AuthResponse::getMessage() {
  return message;
}

void AuthResponse::setMessage(QString message) {
  this->message = message;
}

QString AuthResponse::getToken() {
  return token;
}

void AuthResponse::setToken(QString token) {
  this->token = token;
}
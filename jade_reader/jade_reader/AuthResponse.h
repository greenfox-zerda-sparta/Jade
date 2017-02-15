#pragma once
#include <QObject>
#include <QString>

class AuthResponse : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString result READ getResult WRITE setResult);
  Q_PROPERTY(QString message READ getMessage WRITE setMessage);
  Q_PROPERTY(QString token READ getToken WRITE setToken);
private:
  QString result;
  QString message;
  QString token;
public:
  Q_INVOKABLE AuthResponse();
  QString getResult();
  void setResult(QString result);
  QString getMessage();
  void setMessage(QString message);
  QString getToken();
  void setToken(QString token);
};
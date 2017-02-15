#pragma once
#include <QObject>
#include <QString>

class PostData : QObject {
  Q_OBJECT
  Q_PROPERTY(QString email READ getEmail WRITE setEmail);
  Q_PROPERTY(QString password READ getPassword WRITE setPassword);
private:
  QString email;
  QString password;
public:
  PostData();
  PostData(QString email, QString password);
  QString getEmail();
  void setEmail(QString email);
  QString getPassword();
  void setPassword(QString password);
};
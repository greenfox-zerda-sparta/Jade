#pragma once
#include <QProcessEnvironment>

class Logger {
private:
  QProcessEnvironment processEnvironment;
  QString baseLevel;
  QString classType;
  QString actualLogLevel;
public:
  Logger(QString classType);
  ~Logger();
  void log(QString message);
  void debug(QString message);
  void info(QString message);
  void warn(QString message);
  void error(QString message);
};


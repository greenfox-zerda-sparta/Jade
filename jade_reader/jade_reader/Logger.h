#pragma once
#include <QProcessEnvironment>
#include <QTextStream>

class Logger {
private:
  QTextStream* _COUT;
  QTextStream* _CERR;
  QProcessEnvironment processEnvironment;
  QString baseLevel;
  QString classType;
  QString actualLogLevel;
  QString* output;
public:
  Logger(QString classType);
  Logger(QString classType, QString* output);
  ~Logger();
  void log(QString message);
  void debug(QString message);
  void info(QString message);
  void warn(QString message);
  void error(QString message);
};


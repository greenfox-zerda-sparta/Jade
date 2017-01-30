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
public:
  Logger(QString classType, QString logLevel);
  Logger(QString classType, QTextStream* mockStreamCout, QTextStream* mockStreamCerr, QString logLevel);
  ~Logger();
  void log(QString message);
  void debug(QString message);
  void info(QString message);
  void warn(QString message);
  void error(QString message);
};


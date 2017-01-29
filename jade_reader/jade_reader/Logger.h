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
  Logger(QString classType);
  Logger(QString classType, QTextStream* mockStreamCout, QTextStream* mockStreamCerr);
  ~Logger();
  void log(QString message);
  void debug(QString message);
  void info(QString message);
  void warn(QString message);
  void error(QString message);
};


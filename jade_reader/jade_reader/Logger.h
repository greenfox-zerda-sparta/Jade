#pragma once
#include <QTextStream>

class Logger {
private:
  QTextStream* _COUT;
  QTextStream* _CERR;
  QString baseLevel;
  QString classType;
  QString actualLogLevel;
  void logCout(QString message);
  void logCerr(QString message);
  bool isLogLevelLessThanWarn();
  bool isMessageDisplayable();
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


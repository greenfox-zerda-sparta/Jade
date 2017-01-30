#pragma once
#include <QTextStream>

class Logger {
private:
  QTextStream* _COUT;
  QTextStream* _CERR;
  QString baseLevel;
  QString classType;
  QString actualLogLevel;
  bool isMessageDisplayable();
public:
  Logger(QString classType, QString logLevel);
  Logger(QString classType, QTextStream* mockStreamCout, QTextStream* mockStreamCerr, QString logLevel);
  void log(QString message, QTextStream* stream);
  void debug(QString message);
  void info(QString message);
  void warn(QString message);
  void error(QString message);
  ~Logger();
};


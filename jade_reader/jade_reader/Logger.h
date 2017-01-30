#pragma once
#include <QTextStream>
#include <QVector>

class Logger {
private:
  QVector<QString> levels;
  QTextStream* _COUT;
  QTextStream* _CERR;
  QString baseLevel;
  QString classType;
  bool isMessageDisplayable(QString logLevel);
  bool isLogLevelLessThanWarn(QString logLevel);
  QTextStream* getStreamByLogLevel(QString logLevel);
public:
  Logger(QString classType);
  Logger(QString classType, QTextStream* mockStreamCout, QTextStream* mockStreamCerr, QString baseLevel);
  void log(QString message, QString logLevel);
  void debug(QString message);
  void info(QString message);
  void warn(QString message);
  void error(QString message);
  ~Logger();
};


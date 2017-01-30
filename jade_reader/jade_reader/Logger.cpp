#include "Logger.h"
#include <QVector>

QVector<QString> levels = {"DEBUG", "INFO", "WARN", "ERROR"};

Logger::Logger(QString classType, QString logLevel) : Logger::Logger(classType, new QTextStream(stdout), new QTextStream(stderr), logLevel) {}

Logger::Logger(QString classType, QTextStream* mockStreamCout, QTextStream* mockStreamCerr, QString logLevel) {
  baseLevel = logLevel;
  this->classType = classType;
  actualLogLevel = "";
  _COUT = mockStreamCout;
  _CERR = mockStreamCerr;
}

void Logger::log(QString message, QTextStream* stream) {
  if (isMessageDisplayable()) {
    *stream << actualLogLevel << " " << classType << " " << message << "\n";
    stream->flush();
  }
}

bool Logger::isMessageDisplayable() {
  return levels.indexOf(actualLogLevel) >= levels.indexOf(baseLevel);
}

void Logger::debug(QString message) {
  actualLogLevel = "DEBUG";
  log(message, _COUT);
}

void Logger::info(QString message) {
  actualLogLevel = "INFO";
  log(message, _COUT);
}

void Logger::warn(QString message) {
  actualLogLevel = "WARN";
  log(message, _CERR);
}

void Logger::error(QString message) {
  actualLogLevel = "ERROR";
  log(message, _CERR);
}

Logger::~Logger() {
  delete _COUT;
  delete _CERR;
}

#include "Logger.h"
#include "LogLevelProvider.h"

Logger::Logger(QString classType) : Logger::Logger(classType, new QTextStream(stdout), new QTextStream(stderr), LogLevelProvider::getLogLevel()) {}

Logger::Logger(QString classType, QTextStream* coutStream, QTextStream* cerrStream, QString baseLevel) {
  levels = {"DEBUG", "INFO", "WARN", "ERROR"};
  this->baseLevel = baseLevel;
  this->classType = classType;
  _COUT = coutStream;
  _CERR = cerrStream;
}

void Logger::log(QString message, QString logLevel) {
  if (isMessageDisplayable(logLevel)) {
    QTextStream* stream = getStreamByLogLevel(logLevel);
    *stream << logLevel << " " << classType << " " << message << "\n";
    stream->flush();
  }
}

bool Logger::isMessageDisplayable(QString logLevel) {
  return levels.indexOf(logLevel) >= levels.indexOf(baseLevel);
}

bool Logger::isLogLevelLessThanWarn(QString logLevel) {
  return levels.indexOf(logLevel) == 0 || levels.indexOf(logLevel) == 1;
}

QTextStream* Logger::getStreamByLogLevel(QString logLevel) {
  return isLogLevelLessThanWarn(logLevel) ? _COUT : _CERR;
}

void Logger::debug(QString message) {
  log(message, "DEBUG");
}

void Logger::info(QString message) {
  log(message, "INFO");
}

void Logger::warn(QString message) {
  log(message, "WARN");
}

void Logger::error(QString message) {
  log(message, "ERROR");
}

Logger::~Logger() {
  /*delete _COUT;
  delete _CERR;*/
}

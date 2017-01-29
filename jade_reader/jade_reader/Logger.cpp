#include "Logger.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QVector>
#include <iostream>

QVector<QString> levels = {"DEBUG", "INFO", "WARN", "ERROR"};


Logger::Logger(QString classType) : Logger::Logger(classType, new QTextStream(stdout), new QTextStream(stderr)) {}

Logger::Logger(QString classType, QTextStream* mockStreamCout, QTextStream* mockStreamCerr) {
  processEnvironment = QProcessEnvironment::systemEnvironment();
  QStringList qStringList = processEnvironment.toStringList();
  baseLevel = processEnvironment.value("LOG", "INFO");
  this->classType = classType;
  actualLogLevel = "";
  _COUT = mockStreamCout;
  _CERR = mockStreamCerr;
}

void Logger::log(QString message) {
  switch (levels.indexOf(baseLevel)) {
    case 0 :
      if (levels.indexOf(actualLogLevel) >= 0) {
        *_COUT << actualLogLevel << " " << classType << " " << message << "\n";
         _COUT->flush();
      }
      break;
    case 1:
      if (levels.indexOf(actualLogLevel) >= 1) {
        *_COUT << actualLogLevel << " " << classType << " " << message << "\n";
        _COUT->flush();
      }
      break;
    case 2 :
      if (levels.indexOf(actualLogLevel) >= 2) {
        *_CERR << actualLogLevel << " " << classType << " " << message << "\n";
        _CERR->flush();
      }
      break;
    case 3 :
      if (levels.indexOf(actualLogLevel) == 3) {
        *_CERR << actualLogLevel << " " << classType << " " << message << "\n";
        _CERR->flush();
      }
      break;
  }
}

void Logger::debug(QString message) {
  actualLogLevel = "DEBUG";
  log(message);
}

void Logger::info(QString message) {
  actualLogLevel = "INFO";
  log(message);
}

void Logger::warn(QString message) {
  actualLogLevel = "WARN";
  log(message);
}

void Logger::error(QString message) {
  actualLogLevel = "ERROR";
  log(message);
}

Logger::~Logger() {}

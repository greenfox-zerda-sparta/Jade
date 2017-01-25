#include "Logger.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QVector>
#include <iostream>

QVector<QString> levels = {"DEBUG", "INFO", "WARN", "ERROR"};


Logger::Logger(QString classType) {
  processEnvironment = QProcessEnvironment::systemEnvironment();
  QStringList qStringList = processEnvironment.toStringList();
  //baseLevel = processEnvironment.value("LOG", "INFO");
  baseLevel = "INFO";
  this->classType = classType;
  actualLogLevel = "";
  _COUT = new QTextStream(stdout);
  _CERR = new QTextStream(stderr);
}

Logger::Logger(QString classType, QString* output) {
  processEnvironment = QProcessEnvironment::systemEnvironment();
  QStringList qStringList = processEnvironment.toStringList();
  //baseLevel = processEnvironment.value("LOG", "INFO");
  baseLevel = "INFO";
  this->classType = classType;
  actualLogLevel = "";
  _COUT = new QTextStream();
  _CERR = new QTextStream();
  QIODevice::OpenMode openMode = QIODevice::ReadWrite;
  this->output = output;
  _COUT->setString(output, openMode);
}

void Logger::log(QString message) {
  switch (levels.indexOf(baseLevel)) {
    case 0 :
    if (levels.indexOf(actualLogLevel) >= 0) {
      *_COUT << actualLogLevel << " Message: " << message << " Class: " << classType << "\n";
       _COUT->flush();
    }
    case 1 :
    if (levels.indexOf(actualLogLevel) >= 1) {
      *_COUT << actualLogLevel << " Message: " << message << " Class: " << classType << "\n";
       _COUT->flush();
    }
    case 2 :
    if (levels.indexOf(actualLogLevel) >= 2) {
      *_CERR << actualLogLevel << " Message: " << message << " Class: " << classType << "\n";
      _CERR->flush();
    }
    case 3 :
    if (levels.indexOf(actualLogLevel) == 3) {
      *_CERR << actualLogLevel << " Message: " << message << " Class: " << classType << "\n";
      _CERR->flush();
    }
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

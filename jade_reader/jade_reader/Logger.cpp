#include "Logger.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QVector>
#include <iostream>

QVector<QString> levels = {"DEBUG", "INFO", "WARN", "ERROR"};


Logger::Logger(QString classType) {
  processEnvironment = QProcessEnvironment::systemEnvironment();
  QStringList qStringList = processEnvironment.toStringList();
  baseLevel = processEnvironment.value("LOG", "INFO");
  this->classType = classType;
  actualLogLevel = "";
}

void Logger::log(QString message) {
  switch (levels.indexOf(baseLevel)) {
    case 0 :
    if (levels.indexOf(actualLogLevel) >= 0) {
      std::cout << actualLogLevel.toUtf8().constData() << " Message: " << message.toUtf8().constData() << " Class: " << classType.toUtf8().constData() << std::endl;
    }
    case 1 :
    if (levels.indexOf(actualLogLevel) >= 1) {
      std::cout << actualLogLevel.toUtf8().constData() << " Message: " << message.toUtf8().constData() << " Class: " << classType.toUtf8().constData() << std::endl;
    }
    case 2 :
    if (levels.indexOf(actualLogLevel) >= 2) {
      std::cerr << actualLogLevel.toUtf8().constData() << " Message: " << message.toUtf8().constData() << " Class: " << classType.toUtf8().constData() << std::endl;
    }
    case 3 :
    if (levels.indexOf(actualLogLevel) == 3) {
      std::cerr << actualLogLevel.toUtf8().constData() << " Message: " << message.toUtf8().constData() << " Class: " << classType.toUtf8().constData() << std::endl;
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

#include "LogLevelProvider.h"
#include <QProcessEnvironment>

QString LogLevelProvider::getLogLevel() {
  QProcessEnvironment processEnvironment = QProcessEnvironment::systemEnvironment();
  QStringList qStringList = processEnvironment.toStringList();
  QString baseLevel = processEnvironment.value("LOG", "INFO");
  return baseLevel;
}

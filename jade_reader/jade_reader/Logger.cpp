#include "Logger.h"
#include <QDebug>
#include <QLoggingCategory>


Logger::Logger() {
  processEnvironment = QProcessEnvironment::systemEnvironment();
  QStringList qStringList = processEnvironment.toStringList();
  for (int i = 0; i < qStringList.size(); ++i) {
    qDebug() << qStringList.at(i).toUtf8().constData();
  }
  debug  = new QLoggingCategory("Debug");
  qDebug() << debug->categoryName();
 }

void Logger::myCategoryFilter(QLoggingCategory *category) {
  if (qstrcmp(category->categoryName(), "alma") == 0) {
    category->setEnabled(QtDebugMsg, true);
  } else {
    //oldCategoryFilter(category);
    qDebug() << "else";
  }
}

Logger::~Logger() {}

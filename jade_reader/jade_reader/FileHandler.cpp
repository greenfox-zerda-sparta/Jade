#include "FileHandler.h"
#include <QTextStream>

void FileHandler::writeToFile(QString toFile, QString filename) {
  QFile file(filename);
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  QTextStream out(&file);
  out << toFile;
  file.close();
}

QString FileHandler::readFile(QString filename) {
  QFile file(filename);
  QString line = "";
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return "";
  }
  QTextStream in(&file);
  while (!in.atEnd()) {
    line = in.readLine();
  }
  return line;
}

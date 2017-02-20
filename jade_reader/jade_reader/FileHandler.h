#pragma once
#include <QFile>
//#include <QSharedPointer>

class FileHandler
{
public:
  static void writeToFile(QString toFile, QString filename);
  static QString readFile(QString filename);
};


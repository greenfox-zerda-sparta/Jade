#pragma once
#include <QFile>
//#include <QSharedPointer>

class FileHandler
{
public:
  void writeToFile(QString toFile, QString filename);
  QString readFile(QString filename);
};


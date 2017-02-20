#pragma once
#include <QFile>

class FileHandler
{
public:
  static void writeToFile(QString toFile, QString filename);
  static QString readFile(QString filename);
};


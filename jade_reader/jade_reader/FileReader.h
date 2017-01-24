#pragma once
#include <string>
#include <fstream>
#include <QString>

class FileReader {
public:
  FileReader();
  QString readFromFileToQString(std::string fileName);
  ~FileReader();
};
#include "FileReader.h"



FileReader::FileReader() {}
QString FileReader::readFromFileToQString(std::string fileName) {
  std::string json = "";
  std::string word;

  std::ifstream file(fileName.c_str());
  if (file.is_open()) {
    while (getline(file, word)) {
      json += word;
    }
  }
  return QString::fromStdString(json);
}


FileReader::~FileReader() {}
#include "FileReader.h"



FileReader::FileReader() {}

std::string FileReader::readFromFileToString(std::string fileName) {
  std::string json = "";
  std::string word;

  std::ifstream file(fileName.c_str());
  if (file.is_open()) {
    while (file >> word) {
      json += word;
    }
  }
  return json;
}


FileReader::~FileReader() {}

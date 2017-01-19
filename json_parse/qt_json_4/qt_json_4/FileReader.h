#pragma once
#include <string>
#include <fstream>

class FileReader {
public:
  FileReader();
  std::string readFromFileToString(std::string fileName);
  ~FileReader();
};


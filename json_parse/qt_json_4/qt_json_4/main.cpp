#include <iostream>
#include "FileReader.h"
#include "JsonParser.h"

int main(int argc, char *argv[]) {
  FileReader fileReader;
  std::string content = fileReader.readFromFileToString("test.json");

  JsonParser jsonParser;
  QStringList titles = jsonParser.parseFromStringToQStringList(content);

  for (int i = 0; i < titles.size(); ++i) {
    std::cout << titles.at(i).toUtf8().constData() << std::endl;
  }
  return 0;
}
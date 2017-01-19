#include "qt_json_4.h"
#include "FileReader.h"
#include <QtWidgets/QApplication>
#include <string>
#include <fstream>
#include <iostream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[]) {
  FileReader fileReader;
  std::string content = fileReader.readFromFileToString("test.json");

  QStringList title;
  QJsonParseError *error = Q_NULLPTR;
  QByteArray byteArray(content.c_str(), content.length());
  QJsonDocument jsonResponse = QJsonDocument::fromJson(byteArray, error);
  QJsonObject jsonObject = jsonResponse.object();
  QJsonArray jsonArray = jsonObject["news"].toArray();
  foreach(const QJsonValue & value, jsonArray) {
    QJsonObject obj = value.toObject();
    title.append(obj["title"].toString());
  }

  for (int i = 0; i < title.size(); ++i) {
    std::cout << title.at(i).toUtf8().constData() << std::endl;
  }

 
  return 0;
}
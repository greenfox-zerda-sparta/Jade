#include "json_second_try.h"
#include <QtWidgets/QApplication>
#include <string>
#include <fstream>
#include <iostream>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //json_second_try w;
    //w.show();

      std::string word;

      std::string content = "";
      std::ifstream file("test.json");
      if (file.is_open()) {
        while (file >> word) {
          content += word;
        }
      }
      std::cout << content << std::endl;

      QJsonDocument qJsonDocument;
      QJsonParseError *error = Q_NULLPTR;
      QByteArray byteArray(content.c_str(), content.length());
      //std::cout << byteArray.toStdString() << std::endl;
      qJsonDocument = QJsonDocument::fromJson(byteArray, error);
      if (error != Q_NULLPTR) {
        QString qs = error->errorString();
        std::string utf8_text = qs.toUtf8().constData();
        std::cout << utf8_text << std::endl;
      } else {
        std::cout << qJsonDocument.isArray() << std::endl;
        std::cout << qJsonDocument.isObject() << std::endl;
        std::cout << qJsonDocument.isEmpty() << std::endl;
        QJsonObject jsonObject = qJsonDocument.object();
        std::cout << "length: " << jsonObject.length() << std::endl;
        std::cout << "key: " << jsonObject.begin().key().toUtf8().constData() << std::endl;
        QString key = jsonObject.begin().key();
        QJsonValue value = jsonObject.take(key);
        std::cout << "is null: " << value.isNull() << std::endl;
        std::cout << "is array: " << value.isArray() << std::endl;
        QJsonArray jsonArray = value.toArray();
        QJsonValue first;
        first = jsonArray.first();
        std::cout << "is array first element object: " << first.isObject() << std::endl;
        QJsonObject secondObject = first.toObject();
        std::cout << "secondObject key: " << secondObject.begin().key().toUtf8().constData() << std::endl;
      }

      /*QStringList propertyNames;
      QStringList propertyKeys;
      QString strReply = (QString)reply->readAll();
      QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
      QJsonObject jsonObject = jsonResponse.object();
      QJsonArray jsonArray = jsonObject["properties"].toArray();

      foreach(const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        propertyNames.append(obj["PropertyName"].toString());
        propertyKeys.append(obj["key"].toString());
      }*/


    //return a.exec();
      return 0;
}

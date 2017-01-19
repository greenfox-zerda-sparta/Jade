
//#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QString>

#include <QLabel>
#include <QMainWindow>
#include <QApplication>


#include <fstream>
#include <iostream>
#include <string>

QString sendRequest();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString to_write = sendRequest();
    qDebug() << to_write;
    
    QLabel *label = new QLabel();
    label->setText(to_write);
    label->show();

    return a.exec();
}

QString sendRequest() {
  // create custom temporary event loop on stack
  QEventLoop eventLoop;

  // "quit()" the event-loop, when the network request "finished()"
  QNetworkAccessManager mgr;
  QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

  // the HTTP request
  QNetworkRequest req(QUrl(QString("http://help.websiteos.com/websiteos/example_of_a_simple_html_page.htm")));
  QNetworkReply *reply = mgr.get(req);
  eventLoop.exec(); // blocks stack until "finished()" has been called

  if (reply->error() == QNetworkReply::NoError) {
    //success
    QString str = reply->readAll();
    std::string s = str.toUtf8().constData();
    //qDebug() << "Success" << str;
    std::ofstream file;
    file.open("google.html");
    file << s;
    file.close();

    delete reply;

    return str;
  }
  else {
    //failure
    qDebug() << "Failure" << reply->errorString();
    delete reply;
    return "hiba";
  }
}
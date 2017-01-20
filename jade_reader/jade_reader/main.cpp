#include "jade_reader.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jade_reader w;
    w.show();
    return a.exec();
}

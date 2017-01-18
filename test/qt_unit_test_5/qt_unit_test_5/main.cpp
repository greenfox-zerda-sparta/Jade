#ifndef _TEST

#include "qt_unit_test_5.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qt_unit_test_5 w;
    w.show();
    return a.exec();
}

#endif

#ifdef _TEST
#include <QtTest/QtTest>

class TestQString: public QObject {
  Q_OBJECT
    private slots:
  void toUpper();
};

void TestQString::toUpper() {
  QString str = "Hello";
  QCOMPARE(str.toUpper(), QString("HELLO"));
}

QTEST_MAIN(TestQString)
#include "main.moc"

#endif

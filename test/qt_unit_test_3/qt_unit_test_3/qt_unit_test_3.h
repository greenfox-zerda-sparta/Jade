#ifndef QT_UNIT_TEST_3_H
#define QT_UNIT_TEST_3_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_unit_test_3.h"

class qt_unit_test_3 : public QMainWindow
{
    Q_OBJECT

public:
    qt_unit_test_3(QWidget *parent = 0);
    ~qt_unit_test_3();

private:
    Ui::qt_unit_test_3Class ui;
};

#endif // QT_UNIT_TEST_3_H

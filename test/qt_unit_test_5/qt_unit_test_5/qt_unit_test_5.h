#ifndef QT_UNIT_TEST_5_H
#define QT_UNIT_TEST_5_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_unit_test_5.h"

class qt_unit_test_5 : public QMainWindow
{
    Q_OBJECT

public:
    qt_unit_test_5(QWidget *parent = 0);
    ~qt_unit_test_5();

private:
    Ui::qt_unit_test_5Class ui;
};

#endif // QT_UNIT_TEST_5_H

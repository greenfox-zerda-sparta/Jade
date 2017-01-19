#ifndef QT_JSON_4_H
#define QT_JSON_4_H

#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QVector>
#include "ui_qt_json_4.h"

class qt_json_4 : public QMainWindow
{
    Q_OBJECT

public:
    qt_json_4(QWidget *parent = 0);
    ~qt_json_4();
private:
    Ui::qt_json_4Class ui;
private:
  QVector <QPushButton*> buttons;
};

#endif // QT_JSON_4_H

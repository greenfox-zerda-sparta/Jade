#ifndef JSON_SECOND_TRY_H
#define JSON_SECOND_TRY_H

#include <QtWidgets/QMainWindow>
#include "ui_json_second_try.h"

class json_second_try : public QMainWindow
{
    Q_OBJECT

public:
    json_second_try(QWidget *parent = 0);
    ~json_second_try();

private:
    Ui::json_second_tryClass ui;
};

#endif // JSON_SECOND_TRY_H

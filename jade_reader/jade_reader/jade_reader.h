#ifndef JADE_READER_H
#define JADE_READER_H

#include <QtWidgets/QMainWindow>
#include "ui_jade_reader.h"

class jade_reader : public QMainWindow
{
  Q_OBJECT

public:
  jade_reader(QWidget *parent = 0);
  ~jade_reader();

private:
  Ui::jade_readerClass ui;
};

#endif
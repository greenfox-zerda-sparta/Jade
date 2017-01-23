#pragma once
#include <QLabel>

class LabelCreator {
public:
  LabelCreator();
  ~LabelCreator();
  QLabel * createLabelFromQString(QString input);
};


#include "DateParser.h"
#include <QDateTime>
#include <QLocale>

QString DateParser::parseDate(qint64 date) {
  QDateTime qdate;
  qdate.setMSecsSinceEpoch(date * 1000);
  QLocale us(QLocale::English, QLocale::UnitedStates);
  QString dateStringEnglish = us.toString(qdate, "MMMM d, yyyy");
  return dateStringEnglish;
}


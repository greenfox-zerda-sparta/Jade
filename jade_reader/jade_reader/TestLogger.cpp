#include "TestLogger.h"
#include "Logger.h"

void TestLogger::whenInfoMessageIsEmpty() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  Logger logger2("TestClass", mockCout, mockCerr);
  logger2.info("");
  QString resultCout = mockCout->readLine();
  QString resultCerr = mockCerr->readLine();
  QCOMPARE(resultCout, QString("INFO TestClass "));
  QCOMPARE(resultCerr, QString(""));
}

void TestLogger::whenInfoMessageIsReallyLong() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  Logger logger2("TestClass", mockCout, mockCerr);
  logger2.info("Thus it was not rare to find, on the Sunday, the tallboy on its feet by the fire, and the dressing table on its head by the bed, and the night-stool on its face by the door, and the washand-stand on its back by the window; and, on the Monday, the tallboy on its back by the bed, and the dressing table on its face by the door, and the night-stool on its back by the window and the washand-stand on its feet by the fire; and on the Tuesday…");
  QString result = mockCout->readLine();
  QCOMPARE(result, QString("INFO TestClass Thus it was not rare to find, on the Sunday, the tallboy on its feet by the fire, and the dressing table on its head by the bed, and the night-stool on its face by the door, and the washand-stand on its back by the window; and, on the Monday, the tallboy on its back by the bed, and the dressing table on its face by the door, and the night-stool on its back by the window and the washand-stand on its feet by the fire; and on the Tuesday…"));
}

void TestLogger::whenInfoMessageHasLineBreak() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  Logger logger2("TestClass", mockCout, mockCerr);
  logger2.info("Test \n Info \n Message");
  QString result = mockCout->readLine();
  QCOMPARE(result, QString("INFO TestClass Test "));
}

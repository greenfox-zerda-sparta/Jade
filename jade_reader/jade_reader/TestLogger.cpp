#include "TestLogger.h"
#include "Logger.h"

void TestLogger::whenInfoMessageIsEmpty() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  QString logLevel = "INFO";
  Logger logger2("TestClass", mockCout, mockCerr, logLevel);
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
  QString logLevel = "INFO";
  Logger logger2("TestClass", mockCout, mockCerr, logLevel);
  logger2.info("Thus it was not rare to find, on the Sunday, the tallboy on its feet by the fire, and the dressing table on its head by the bed, and the night-stool on its face by the door, and the washand-stand on its back by the window; and, on the Monday, the tallboy on its back by the bed, and the dressing table on its face by the door, and the night-stool on its back by the window and the washand-stand on its feet by the fire; and on the Tuesday…");
  QString result = mockCout->readLine();
  QCOMPARE(result, QString("INFO TestClass Thus it was not rare to find, on the Sunday, the tallboy on its feet by the fire, and the dressing table on its head by the bed, and the night-stool on its face by the door, and the washand-stand on its back by the window; and, on the Monday, the tallboy on its back by the bed, and the dressing table on its face by the door, and the night-stool on its back by the window and the washand-stand on its feet by the fire; and on the Tuesday…"));
}

void TestLogger::whenInfoMessageHasLineBreak() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  QString logLevel = "INFO";
  Logger logger2("TestClass", mockCout, mockCerr, logLevel);
  logger2.info("Test \n Info \n Message");
  QString result = mockCout->readAll();
  QCOMPARE(result, QString("INFO TestClass Test \n Info \n Message\n"));
}

void TestLogger::whenLogLevelIsDebug() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  QString logLevel = "DEBUG";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  logger.debug("Test Debug Message");
  logger.info("Test Info Message");
  logger.warn("Test Warn Message");
  logger.error("Test Error Message");
  QString resultCout = mockCout->readAll();
  QString resultCerr = mockCerr->readAll();
  QCOMPARE(resultCout, QString("DEBUG TestClass Test Debug Message\nINFO TestClass Test Info Message\nWARN TestClass Test Warn Message\nERROR TestClass Test Error Message\n"));
  QCOMPARE(resultCerr, QString(""));
}

void TestLogger::whenLogLevelIsInfo() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  QString logLevel = "INFO";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  logger.debug("Test Debug Message");
  logger.info("Test Info Message");
  logger.warn("Test Warn Message");
  logger.error("Test Error Message");
  QString resultCout = mockCout->readAll();
  QString resultCerr = mockCerr->readAll();
  QCOMPARE(resultCout, QString("INFO TestClass Test Info Message\nWARN TestClass Test Warn Message\nERROR TestClass Test Error Message\n"));
  QCOMPARE(resultCerr, QString(""));
}

void TestLogger::whenLogLevelIsWarn() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  QString logLevel = "WARN";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  logger.debug("Test Debug Message");
  logger.info("Test Info Message");
  logger.warn("Test Warn Message");
  logger.error("Test Error Message");
  QString resultCout = mockCout->readAll();
  QString resultCerr = mockCerr->readAll();
  QCOMPARE(resultCerr, QString("WARN TestClass Test Warn Message\nERROR TestClass Test Error Message\n"));
  QCOMPARE(resultCout, QString(""));
}

void TestLogger::whenLogLevelIsError() {
  QString buffer;
  QString buffer2;
  QTextStream* mockCout = new QTextStream(&buffer, QIODevice::ReadWrite);
  QTextStream* mockCerr = new QTextStream(&buffer2, QIODevice::ReadWrite);
  QString logLevel = "ERROR";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  logger.debug("Test Debug Message");
  logger.info("Test Info Message");
  logger.warn("Test Warn Message");
  logger.error("Test Error Message");
  QString resultCout = mockCout->readAll();
  QString resultCerr = mockCerr->readAll();
  QCOMPARE(resultCerr, QString("ERROR TestClass Test Error Message\n"));
  QCOMPARE(resultCout, QString(""));
}

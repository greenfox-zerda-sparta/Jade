#include "TestLogger.h"

void TestLogger::init() {
  buffer = new QString;
  buffer2 = new QString;
  mockCout = new QTextStream(buffer, QIODevice::ReadWrite);
  mockCerr = new QTextStream(buffer2, QIODevice::ReadWrite);
}

void TestLogger::writeMessages(Logger& logger) {
  logger.debug("Test Debug Message");
  logger.info("Test Info Message");
  logger.warn("Test Warn Message");
  logger.error("Test Error Message");
}

void TestLogger::whenInfoMessageIsEmpty() {
  QString logLevel = "INFO";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  logger.info("");
  QCOMPARE(mockCout->readLine(), QString("INFO TestClass "));
  QCOMPARE(mockCerr->readLine(), QString(""));
}

void TestLogger::whenInfoMessageIsReallyLong() {
  QString logLevel = "INFO";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  logger.info("Thus it was not rare to find, on the Sunday, the tallboy on its feet by the fire, and the dressing table on its head by the bed, and the night-stool on its face by the door, and the washand-stand on its back by the window; and, on the Monday, the tallboy on its back by the bed, and the dressing table on its face by the door, and the night-stool on its back by the window and the washand-stand on its feet by the fire; and on the Tuesday…");
  QCOMPARE(mockCout->readLine(), QString("INFO TestClass Thus it was not rare to find, on the Sunday, the tallboy on its feet by the fire, and the dressing table on its head by the bed, and the night-stool on its face by the door, and the washand-stand on its back by the window; and, on the Monday, the tallboy on its back by the bed, and the dressing table on its face by the door, and the night-stool on its back by the window and the washand-stand on its feet by the fire; and on the Tuesday…"));
}

void TestLogger::whenInfoMessageHasLineBreak() {
  QString logLevel = "INFO";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  logger.info("Test \n Info \n Message");
  QCOMPARE(mockCout->readAll(), QString("INFO TestClass Test \n Info \n Message\n"));
}

void TestLogger::whenLogLevelIsDebug() {
  QString logLevel = "DEBUG";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  writeMessages(logger);
  QCOMPARE(mockCout->readAll(), QString("DEBUG TestClass Test Debug Message\nINFO TestClass Test Info Message\n"));
  QCOMPARE(mockCerr->readAll(), QString("WARN TestClass Test Warn Message\nERROR TestClass Test Error Message\n"));
}

void TestLogger::whenLogLevelIsInfo() {
  QString logLevel = "INFO";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  writeMessages(logger);
  QCOMPARE(mockCout->readAll(), QString("INFO TestClass Test Info Message\n"));
  QCOMPARE(mockCerr->readAll(), QString("WARN TestClass Test Warn Message\nERROR TestClass Test Error Message\n"));
}

void TestLogger::whenLogLevelIsWarn() {
  QString logLevel = "WARN";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  writeMessages(logger);
  QCOMPARE(mockCout->readAll(), QString(""));
  QCOMPARE(mockCerr->readAll(), QString("WARN TestClass Test Warn Message\nERROR TestClass Test Error Message\n"));
}

void TestLogger::whenLogLevelIsError() {
  QString logLevel = "ERROR";
  Logger logger("TestClass", mockCout, mockCerr, logLevel);
  writeMessages(logger);
  QCOMPARE(mockCout->readAll(), QString(""));
  QCOMPARE(mockCerr->readAll(), QString("ERROR TestClass Test Error Message\n"));
}

void TestLogger::cleanup() {
  delete mockCout;
  delete mockCerr;
  delete buffer;
  delete buffer2;
}

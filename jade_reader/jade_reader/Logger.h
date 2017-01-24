#pragma once
#include <QProcessEnvironment>

class Logger {
private:
  QProcessEnvironment processEnvironment;
 // QLoggingCategory::CategoryFilter oldCategoryFilter;
public:
  QLoggingCategory* debug;
  Logger();
  ~Logger();
  void myCategoryFilter(QLoggingCategory *category);
};


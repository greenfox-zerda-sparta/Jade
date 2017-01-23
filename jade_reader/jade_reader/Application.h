#pragma once
#include "FileReader.h"
#include "JsonParser.h"
#include "LabelCreator.h"
#include <QLabel>
#include <QtWidgets>
#include <QVBoxLayout>
#include <QtGui>

class Application {
public:
	Application();
	~Application();
	void run();
};


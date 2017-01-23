#include "Application.h"

int main(int argc, char *argv[]) {
	Application application;
	QApplication app(argc, argv);
	application.run();
	return app.exec();
}


#include "mainGui.h"
#include <QApplication>
#include <QMainWindow>
#include <memory>
#include <qmainwindow.h>
#include <qpushbutton.h>

int main(int argc, char **argv) {
	QApplication QtApplication(argc, argv);

	MainGui mainWindow{};

	mainWindow.show();
	QtApplication.exec();
}



#include "mainGui.h"
#include <QApplication>
#include <QMainWindow>
#include <memory>
#include <qmainwindow.h>
#include <qpushbutton.h>

int main(int argc, char **argv) {
	QApplication QtApplication(argc, argv);

	std::unique_ptr<MainGui> mainWindow = std::make_unique<MainGui>();
	mainWindow->show();

	QtApplication.exec();
}

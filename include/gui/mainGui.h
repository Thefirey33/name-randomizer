
#ifndef DESIGNERBEPGDS_H
#define DESIGNERBEPGDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qmainwindow.h>
#include <qpushbutton.h>

class MainGui : public QMainWindow {
	Q_OBJECT
  public:
	explicit MainGui(QWidget *parent = nullptr);

	QWidget *centralwidget;
	QVBoxLayout *verticalLayout;
	QPushButton *randomSelectButton;
	QListWidget *personList;
	QHBoxLayout *addingLayout;
	QLineEdit *personNameEditor;
	QPushButton *addPersonButton;
	QPushButton *removePersonButton;
	QHBoxLayout *importingAndExportingLayout;
	QPushButton *importButton;
	QPushButton *exportButton;
	QMenuBar *menubar{};
	QStatusBar *statusbar{};

	void pickRandomAction();
	void deleteItem();
	void addItem();
	void exportList();
	void importList();
};

#endif // DESIGNERBEPGDS_H

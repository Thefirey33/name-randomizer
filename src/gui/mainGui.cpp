#include "mainGui.h"
#include <QMainWindow>
#include <iostream>
#include <qmainwindow.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qtconfigmacros.h>

QT_BEGIN_NAMESPACE

MainGui::MainGui(QWidget *parent) : QMainWindow(parent) {
	this->resize(545, 502);
	centralwidget = new QWidget(this);
	centralwidget->setObjectName("centralwidget");
	verticalLayout = new QVBoxLayout(centralwidget);
	verticalLayout->setObjectName("verticalLayout");
	randomSelectButton = new QPushButton(centralwidget);
	randomSelectButton->setObjectName("randomSelectButton");
	randomSelectButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

	verticalLayout->addWidget(randomSelectButton);

	selectedPersonName = new QLabel(centralwidget);
	selectedPersonName->setObjectName("selectedPersonName");
	selectedPersonName->setAlignment(Qt::AlignmentFlag::AlignCenter);

	verticalLayout->addWidget(selectedPersonName);

	personList = new QListWidget(centralwidget);
	personList->setObjectName("personList");

	verticalLayout->addWidget(personList);

	addingLayout = new QHBoxLayout();
	addingLayout->setObjectName("horizontalLayout");
	personNameEditor = new QLineEdit(centralwidget);
	personNameEditor->setObjectName("personNameEditor");

	addingLayout->addWidget(personNameEditor);

	addPersonButton = new QPushButton(centralwidget);
	addPersonButton->setObjectName("addPersonButton");
	addPersonButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

	addingLayout->addWidget(addPersonButton);

	verticalLayout->addLayout(addingLayout);

	importingAndExportingLayout = new QHBoxLayout();
	importingAndExportingLayout->setObjectName("horizontalLayout_2");
	importButton = new QPushButton(centralwidget);
	importButton->setObjectName("importButton");

	importingAndExportingLayout->addWidget(importButton);

	exportButton = new QPushButton(centralwidget);
	exportButton->setObjectName("exportButton");

	importingAndExportingLayout->addWidget(exportButton);

	verticalLayout->addLayout(importingAndExportingLayout);

	this->setCentralWidget(centralwidget);
	menubar = new QMenuBar(this);
	menubar->setObjectName("menubar");
	menubar->setGeometry(QRect(0, 0, 545, 30));
	this->setMenuBar(menubar);
	statusbar = new QStatusBar(this);
	statusbar->setObjectName("statusbar");
	this->setStatusBar(statusbar);
	retranslateUi();

	QMetaObject::connectSlotsByName(this);
}

void MainGui::retranslateUi() {
	this->setWindowTitle(
		QCoreApplication::translate("MainWindow", "Random Picker", nullptr));
	randomSelectButton->setText(QCoreApplication::translate(
		"MainWindow", "Rastgele Se\303\247", nullptr));
	selectedPersonName->setText(QCoreApplication::translate(
		"MainWindow", "Hi\303\247 kimse se\303\247ilmemi\305\237tir.",
		nullptr));
	addPersonButton->setText(
		QCoreApplication::translate("MainWindow", "+", nullptr));
	importButton->setText(QCoreApplication::translate(
		"MainWindow", "\304\260\303\247e Aktar...", nullptr));
	exportButton->setText(QCoreApplication::translate(
		"MainWindow", "D\304\261\305\237a Aktar...", nullptr));
}

void MainGui::pickRandomAction() { std::cout << "TEST" << std::endl; }

QT_END_NAMESPACE
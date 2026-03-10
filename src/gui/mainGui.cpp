#include "mainGui.h"
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QObject>
#include <QPushButton>
#include <cstdlib>
#include <iostream>
#include <qfiledialog.h>
#include <qfileinfo.h>
#include <qobjectdefs.h>
#include <qt/QtCore/qchar.h>
#include <qt/QtCore/qglobal.h>
#include <sstream>

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
	randomSelectButton->setText(tr("Rastgele Seç."));
	connect(randomSelectButton, &QPushButton::clicked, this,
			&MainGui::pickRandomAction);
	verticalLayout->addWidget(randomSelectButton);

	personList = new QListWidget(centralwidget);
	personList->setObjectName("personList");
	personList->setSelectionMode(
		QAbstractItemView::SelectionMode::MultiSelection);
	verticalLayout->addWidget(personList);

	addingLayout = new QHBoxLayout();
	addingLayout->setObjectName("horizontalLayout");

	personNameEditor = new QLineEdit(centralwidget);
	personNameEditor->setObjectName("personNameEditor");
	addingLayout->addWidget(personNameEditor);

	addPersonButton = new QPushButton(centralwidget);
	addPersonButton->setObjectName("addPersonButton");
	addPersonButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
	addPersonButton->setText(tr("Ekle"));
	connect(addPersonButton, &QPushButton::clicked, this, &MainGui::addItem);

	removePersonButton = new QPushButton(centralwidget);
	removePersonButton->setObjectName("removePersonButton");
	removePersonButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
	removePersonButton->setText(tr("Sil"));

	connect(removePersonButton, &QPushButton::clicked, this,
			&MainGui::deleteItem);

	addingLayout->addWidget(addPersonButton);
	addingLayout->addWidget(removePersonButton);

	verticalLayout->addLayout(addingLayout);

	importingAndExportingLayout = new QHBoxLayout();

	importingAndExportingLayout->setObjectName("horizontalLayout_2");
	importButton = new QPushButton(centralwidget);
	importButton->setObjectName("importButton");
	importButton->setText(tr("İçeri Aktar."));
	connect(importButton, &QPushButton::clicked, this, &MainGui::importList);
	importingAndExportingLayout->addWidget(importButton);

	exportButton = new QPushButton(centralwidget);
	exportButton->setObjectName("exportButton");
	exportButton->setText(tr("Dışarı Aktar."));
	connect(exportButton, &QPushButton::clicked, this, &MainGui::exportList);
	importingAndExportingLayout->addWidget(exportButton);

	verticalLayout->addLayout(importingAndExportingLayout);

	this->setCentralWidget(centralwidget);
	this->setWindowTitle("Rastgele Ad Seçici");
	QMetaObject::connectSlotsByName(this);
}

void MainGui::pickRandomAction() {
	if (personList->count() <= 0) {
		QMessageBox::critical(this, "Hata",
							  tr("Bir ya da daha fazla kişi olması lazım!"));
	} else {
		auto itemRecieved = personList->item(std::rand() % personList->count());
		QMessageBox::information(this, "Seçilen Kişi",
								 tr("Seçilen Kişi: ") + itemRecieved->text());
	}
}

void MainGui::deleteItem() {
	if (!personList->selectedItems().isEmpty()) {
		for (auto selectedItem : this->personList->selectedItems()) {
			delete this->personList->takeItem(personList->row(selectedItem));
		}
	} else {
		QMessageBox::critical(this, "Hata", tr("İlk önce birini seçiniz!"));
	}
}

void MainGui::addItem() { personList->addItem(personNameEditor->text()); }

void MainGui::exportList() {
	if (this->personList->count() <= 0) {
		QMessageBox::critical(this, "Hata",
							  tr("Bir ya da daha fazla kişi olması lazım!"));
		return;
	}

	std::stringstream ss;
	for (int i = 0; i < this->personList->count(); i++) {
		ss << this->personList->item(i)->text().toStdString() << "\n";
	}
	QFileDialog::saveFileContent(QByteArray::fromStdString(ss.str()),
								 tr("class.plist"));
}

void MainGui::importList() {
	QFileDialog::getOpenFileContent(
		tr("*.plist"), [&](const QString &dataString, const QByteArray &array) {
			auto list = array.split('\n');
			for (auto &data : list) {
				this->personList->addItem(data.toStdString().c_str());
			}
		});
}

QT_END_NAMESPACE
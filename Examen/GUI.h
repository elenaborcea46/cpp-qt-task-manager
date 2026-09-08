#pragma once
#include "Service.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTableView>
#include <QMessageBox>
#include "TableModel.h"

class GUI :public QWidget {
private:
	Service& srv;

	QHBoxLayout* mainLayout;
	QVBoxLayout* rightLayout;
	QPushButton* btnadauga;
	QLineEdit* txtid;
	QLineEdit* txtdescr;
	QLineEdit* txtprogramatori;
	QLineEdit* txtstare;

	QLineEdit* txtsearch;

	QTableView* tabeltasks;
	TableModel* model;

	void initGUI();
	void connectSignalsSlots();
	void reloadTable();
public:
	GUI(Service& srv) :srv{ srv } {
		initGUI();
		connectSignalsSlots();
		reloadTable();
	}
};
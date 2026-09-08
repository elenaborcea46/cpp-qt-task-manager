#include "GUI.h"

#include <sstream>

void GUI::initGUI()
{
	mainLayout = new QHBoxLayout;
	this->setLayout(mainLayout);

	tabeltasks = new QTableView;
	model = new TableModel{ srv.getAllSortat(),srv };
	tabeltasks->setModel(model);

	rightLayout = new QVBoxLayout;
	btnadauga =new QPushButton("Adauga");
	txtid = new QLineEdit;
	txtdescr = new QLineEdit;
	txtprogramatori = new QLineEdit;
	txtstare = new QLineEdit;

	txtsearch = new QLineEdit;
	txtsearch->setPlaceholderText("Cauta dupa programator");

	txtid->setPlaceholderText("Id:");
	txtdescr->setPlaceholderText("Descriere:");
	txtprogramatori->setPlaceholderText("Programatori:");
	txtstare->setPlaceholderText("Stare:");


	rightLayout->addWidget(btnadauga);
	rightLayout->addWidget(txtid);
	rightLayout->addWidget(txtdescr);
	rightLayout->addWidget(txtprogramatori);
	rightLayout->addWidget(txtstare);

	rightLayout->addWidget(txtsearch);

	mainLayout->addLayout(rightLayout);
	mainLayout->addWidget(tabeltasks);
}

void GUI::connectSignalsSlots(){
	
		QObject::connect(btnadauga, &QPushButton::clicked, this, [&]() {
			try {
				int id = txtid->text().toInt();
				string descriere = txtdescr->text().toStdString();
				string programatoriText = txtprogramatori->text().toStdString();
				string stare = txtstare->text().toStdString();

				vector<string> programatori;
				std::stringstream ss(programatoriText);
				string nume;

				while (getline(ss, nume, ';')) {
					programatori.push_back(nume);
				}

				srv.adaugareTask(id, descriere, programatori, stare);

				reloadTable();

				txtid->clear();
				txtdescr->clear();
				txtprogramatori->clear();
				txtstare->clear();
			}
			catch (std::exception& ex) {
				QMessageBox::warning(this, "Eroare", ex.what());
			}
			});

		QObject::connect(txtsearch, &QLineEdit::textChanged, this, [this]() {
			string text = txtsearch->text().toStdString();

			if (text.empty()) {
				model->setTasks(srv.getAllSortat());
			}
			else {
				model->setTasks(srv.filtrareProgramator(text));
			}
			});
	
}

void GUI::reloadTable() {
	model->setTasks(srv.getAllSortat());
}
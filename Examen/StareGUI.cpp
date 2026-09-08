#include "StareGUI.h"

#include <QString>

void StareGUI::initGUI() {
    this->setWindowTitle(QString::fromStdString(stare));

    auto mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);

    mainLayout->addWidget(lista);

    auto btnLayout = new QHBoxLayout;

    btnLayout->addWidget(btnOpen);
    btnLayout->addWidget(btnInProgress);
    btnLayout->addWidget(btnClosed);

    mainLayout->addLayout(btnLayout);
}

void StareGUI::reload() {
    lista->clear();

    for (const auto& t : srv.getAllSortat()) {
        if (t.getstare() == stare) {
            QString text =
                QString::number(t.getid()) + " | " +
                QString::fromStdString(t.getdescriere());

            lista->addItem(text);
        }
    }
}

void StareGUI::connectSignals() {
    QObject::connect(btnOpen, &QPushButton::clicked, this, [this]() {
        auto item = lista->currentItem();

        if (item == nullptr)
            return;

        int id = item->text().split("|")[0].trimmed().toInt();

        srv.modificaStare(id, "open");
        });

    QObject::connect(btnInProgress, &QPushButton::clicked, this, [this]() {
        auto item = lista->currentItem();

        if (item == nullptr)
            return;

        int id = item->text().split("|")[0].trimmed().toInt();

        srv.modificaStare(id, "inprogress");
        });

    QObject::connect(btnClosed, &QPushButton::clicked, this, [this]() {
        auto item = lista->currentItem();

        if (item == nullptr)
            return;

        int id = item->text().split("|")[0].trimmed().toInt();

        srv.modificaStare(id, "closed");
        });
}
#pragma once

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "Service.h"
#include "Observer.h"

class StareGUI : public QWidget, public Observer {
private:
    Service& srv;
    string stare;

    QListWidget* lista = new QListWidget;

    QPushButton* btnOpen = new QPushButton{ "open" };
    QPushButton* btnInProgress = new QPushButton{ "inprogress" };
    QPushButton* btnClosed = new QPushButton{ "closed" };

    void initGUI();
    void connectSignals();
    void reload();

public:
    StareGUI(Service& srv, string stare) : srv{ srv }, stare{ stare } {
        srv.addObserver(this);

        initGUI();
        connectSignals();
        reload();
    }

    ~StareGUI() {
        srv.removeObserver(this);
    }

    void update() override {
        reload();
    }
};
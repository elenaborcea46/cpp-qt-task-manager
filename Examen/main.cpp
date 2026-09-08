#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"
#include "TaskValidare.h"
#include "GUI.h"
#include "teste.h"
#include "StareGUI.h"

int main(int argc, char* argv[]) {

	ruleazaTeste();

	QApplication a(argc, argv);

	Repository repo{"tasks.txt"};
	ValidareTask validator;
	Service srv{ repo,validator };
	GUI gui{ srv };

	gui.show();

	StareGUI openWindow{ srv,"open" };
	StareGUI progressWindow{ srv,"inprogress" };
	StareGUI closedWindow{ srv,"closed" };

	openWindow.show();
	progressWindow.show();
	closedWindow.show();

	return a.exec();
}
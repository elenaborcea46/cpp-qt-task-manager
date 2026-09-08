#include "TaskValidare.h"

void ValidareTask::validate(const Task& t) {
	if (t.getdescriere().empty())
		throw std::exception("Descrierea nu poate fi vida.");

	if (t.getstare() != "open" && t.getstare() != "inprogress" && t.getstare() != "closed")
		throw std::exception("Starea nu corespunde.");

	if (t.getProgramatori().size() < 1 || t.getProgramatori().size() > 4)
		throw std::exception("Numar invalid de programtori.");
}
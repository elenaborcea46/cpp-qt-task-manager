#include "Task.h"

int Task::getid() const {
	return id;
}

string Task::getdescriere() const {
	return descriere;
}

const vector<string>& Task::getProgramatori() const {
	return programatori;
}

string Task::getstare() const {
	return stare;
}
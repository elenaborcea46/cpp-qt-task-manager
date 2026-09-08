#include "Service.h"
#include <algorithm>

using std::sort;

vector<Task> Service::getAllSortat() {
	auto taskuri = repo.getAll();

	sort(taskuri.begin(), taskuri.end(), [](const Task& t1, const Task& t2) {
		return t1.getstare() < t2.getstare();
		});

	return taskuri;
}

void Service::adaugareTask(int id, string descriere, vector<string> programatori, string stare) {
	Task t{ id,descriere,programatori,stare };

	validator.validate(t);
    
	repo.adaugare(t);
}

vector<Task> Service::filtrareProgramator(const string& text) const {
    vector<Task> rezultat;

    for (const auto& task : repo.getAll()) {
        for (const auto& programator : task.getProgramatori()) {
            if (programator.find(text) != string::npos) {
                rezultat.push_back(task);
                break;
            }
        }
    }

    return rezultat;
}

void Service::modificaStare(int id, const string& stareNoua) {
    repo.modificaStare(id, stareNoua);
    notify();
}
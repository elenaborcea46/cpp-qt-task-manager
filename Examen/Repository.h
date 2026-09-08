#pragma once
#include "Task.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Repository {
private:
	string filename;
	vector<Task> tasks;

	void loadFromFile();
	void writetoFile();
public:
	Repository(string filename) :filename{ filename } {
		loadFromFile();
	}

	//Returneaza lista de task-uri
	const vector<Task>& getAll() const;

	// Adauga un task in repository
    // @param task taskul care se adauga
	void adaugare(const Task& t);

	// Modifica starea unui task
	// @param id id-ul task
	// @param stareNoua noua stare a task-ului
	void modificaStare(int id, const string& stareNoua);
};
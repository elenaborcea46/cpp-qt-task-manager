#pragma once

#include "Observer.h"
#include "Repository.h"
#include "TaskValidare.h"


class Service:public Observable {
private:
	Repository& repo;
	ValidareTask& validator;
public:
	Service(Repository& repo,ValidareTask& validator):repo{repo},validator{validator}{}

	vector<Task> getAllSortat();

	// Adauga un task nou
    // @param id id-ul taskului
    // @param descriere descrierea taskului
    // @param programatori lista programatorilor
    // @param stare starea taskului
    // @throws exception daca taskul nu este valid
	void adaugareTask(int id,string descriere,vector<string> programatori,string stare);

	// Filtreaza taskurile dupa numele unui programator
    // @param text textul cautat
    // @return lista taskurilor care contin un programator
    //         al carui nume contine textul dat
	vector<Task> filtrareProgramator(const string& text) const;

	//Modifica starea unui task
	//@param id id-ul task-ului de modificat
	//@param stareNoua noua stare a task-ului
	void modificaStare(int id, const string& stareNoua);
};
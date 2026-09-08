#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Task {
private:
	int id;
	string descriere;
	vector<string>programatori;
	string stare;
public:
	Task() = default;

	// Constructor pentru Task
    // @param id id-ul taskului
    // @param descriere descrierea taskului
    // @param programatori lista programatorilor care lucreaza la task
    // @param stare starea taskului (open/inprogress/closed)
	Task(int id,string descriere,vector<string>programatori,string stare):id{id},descriere{descriere},programatori{programatori},stare{stare}{}

	// Returneaza id-ul taskului
    // @return id-ul taskului
	int getid() const;

	// Returneaza descrierea taskului
    // @return descrierea taskului
	string getdescriere() const;

	// Returneaza lista programatorilor
    // @return vector cu programatorii taskului
	const vector<string>& getProgramatori() const;

	// Returneaza starea taskului
    // @return starea taskului
	string getstare() const;

	// Seteaza starea task-ului la stareNoua
	// @param stareNoua noua stare a task-ului
	void setStare(const string& stareNoua) {
		stare = stareNoua;
	}
};
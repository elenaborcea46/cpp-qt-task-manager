#include "Repository.h"


#include <fstream>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::stringstream;

void Repository::loadFromFile() {
    ifstream fin(filename);

    if (!fin.is_open())
        return;

    tasks.clear();

    string line;

    while (getline(fin, line)) {
        stringstream linestream(line);

        string idStr;
        string descriere;
        string programatoriStr;
        string stare;

        getline(linestream, idStr, ',');
        getline(linestream, descriere, ',');
        getline(linestream, programatoriStr, ',');
        getline(linestream, stare, ',');

        vector<string> programatori;
        stringstream progStream(programatoriStr);
        string nume;

        while (getline(progStream, nume, ';')) {
            programatori.push_back(nume);
        }

        int id = stoi(idStr);

        Task t{ id, descriere, programatori, stare };

        tasks.push_back(t);
    }

    fin.close();
}

void Repository::writetoFile() {
    ofstream fout(filename);

    for (const auto& task : tasks) {
        fout << task.getid() << ","
            << task.getdescriere() << ",";

        const auto& programatori = task.getProgramatori();

        for (size_t i = 0; i < programatori.size(); i++) {
            fout << programatori[i];

            if (i < programatori.size() - 1) {
                fout << ";";
            }
        }

        fout << "," << task.getstare() << "\n";
    }

    fout.close();
}


const vector<Task>& Repository::getAll() const {
    return tasks;
}

void Repository::adaugare(const Task& t) {
    tasks.push_back(t);
    writetoFile();
}


void Repository::modificaStare(int id, const string& stareNoua) {
    for (auto& t : tasks) {
        if (t.getid() == id) {
            t.setStare(stareNoua);
            writetoFile();
            return;
        }
    }
}
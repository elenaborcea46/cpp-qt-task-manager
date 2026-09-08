#include "Teste.h"
#include "Task.h"
#include "TaskValidare.h"
#include "Repository.h"
#include "Service.h"

#include <cassert>
#include <fstream>
#include <cstdio>

using std::ofstream;
using std::vector;
using std::string;

void testTask() {
    Task t{ 1, "Implementare GUI", {"Ana", "Mihai"}, "open" };

    assert(t.getid() == 1);
    assert(t.getdescriere() == "Implementare GUI");
    assert(t.getProgramatori().size() == 2);
    assert(t.getProgramatori()[0] == "Ana");
    assert(t.getProgramatori()[1] == "Mihai");
    assert(t.getstare() == "open");
}

void testValidareTaskValid() {
    ValidareTask validator;

    Task t{ 1, "Descriere", {"Ana"}, "open" };

    validator.validate(t);

    assert(true);
}

void testValidareDescriereVida() {
    ValidareTask validator;

    Task t{ 1, "", {"Ana"}, "open" };

    try {
        validator.validate(t);
        assert(false);
    }
    catch (...) {
        assert(true);
    }
}

void testValidareStareInvalida() {
    ValidareTask validator;

    Task t{ 1, "Descriere", {"Ana"}, "gresit" };

    try {
        validator.validate(t);
        assert(false);
    }
    catch (...) {
        assert(true);
    }
}

void testValidareProgramatoriInvalid() {
    ValidareTask validator;

    Task t1{ 1, "Descriere", {}, "open" };

    try {
        validator.validate(t1);
        assert(false);
    }
    catch (...) {
        assert(true);
    }

    Task t2{ 2, "Descriere", {"A", "B", "C", "D", "E"}, "open" };

    try {
        validator.validate(t2);
        assert(false);
    }
    catch (...) {
        assert(true);
    }
}

void creeazaFisierTest(const string& filename) {
    ofstream fout(filename);

    fout << "1,Implementare GUI,Ana;Mihai,open\n";
    fout << "2,Testare aplicatie,George,closed\n";
    fout << "3,Validare date,Ana;Maria,inprogress\n";

    fout.close();
}

void testRepositoryLoad() {
    string filename = "test_tasks.txt";
    creeazaFisierTest(filename);

    Repository repo{ filename };

    assert(repo.getAll().size() == 3);

    assert(repo.getAll()[0].getid() == 1);
    assert(repo.getAll()[0].getdescriere() == "Implementare GUI");
    assert(repo.getAll()[0].getProgramatori().size() == 2);
    assert(repo.getAll()[0].getProgramatori()[0] == "Ana");
    assert(repo.getAll()[0].getProgramatori()[1] == "Mihai");
    assert(repo.getAll()[0].getstare() == "open");

    remove(filename.c_str());
}

void testRepositoryAdaugare() {
    string filename = "test_tasks.txt";
    creeazaFisierTest(filename);

    Repository repo{ filename };

    Task t{ 4, "Documentatie", {"Elena"}, "closed" };
    repo.adaugare(t);

    assert(repo.getAll().size() == 4);
    assert(repo.getAll()[3].getid() == 4);
    assert(repo.getAll()[3].getdescriere() == "Documentatie");

    remove(filename.c_str());
}

void testServiceAdaugare() {
    string filename = "test_tasks.txt";
    creeazaFisierTest(filename);

    Repository repo{ filename };
    ValidareTask validator;
    Service srv{ repo, validator };

    srv.adaugareTask(4, "Refactorizare", { "Ion" }, "open");

    assert(repo.getAll().size() == 4);
    assert(repo.getAll()[3].getid() == 4);
    assert(repo.getAll()[3].getdescriere() == "Refactorizare");

    remove(filename.c_str());
}

void testServiceAdaugareInvalida() {
    string filename = "test_tasks.txt";
    creeazaFisierTest(filename);

    Repository repo{ filename };
    ValidareTask validator;
    Service srv{ repo, validator };

    try {
        srv.adaugareTask(4, "", { "Ion" }, "open");
        assert(false);
    }
    catch (...) {
        assert(true);
    }

    try {
        srv.adaugareTask(5, "Task invalid", { "Ion" }, "gresit");
        assert(false);
    }
    catch (...) {
        assert(true);
    }

    remove(filename.c_str());
}

void testServiceSortareDupaStare() {
    string filename = "test_tasks.txt";
    creeazaFisierTest(filename);

    Repository repo{ filename };
    ValidareTask validator;
    Service srv{ repo, validator };

    auto taskuri = srv.getAllSortat();

    assert(taskuri.size() == 3);

    assert(taskuri[0].getstare() == "closed");
    assert(taskuri[1].getstare() == "inprogress");
    assert(taskuri[2].getstare() == "open");

    remove(filename.c_str());
}

void testServiceFiltrareProgramator() {
    string filename = "test_tasks.txt";
    creeazaFisierTest(filename);

    Repository repo{ filename };
    ValidareTask validator;
    Service srv{ repo, validator };

    auto rezultat1 = srv.filtrareProgramator("Ana");

    assert(rezultat1.size() == 2);
    assert(rezultat1[0].getid() == 1);
    assert(rezultat1[1].getid() == 3);

    auto rezultat2 = srv.filtrareProgramator("Mi");

    assert(rezultat2.size() == 1);
    assert(rezultat2[0].getid() == 1);

    auto rezultat3 = srv.filtrareProgramator("XYZ");

    assert(rezultat3.size() == 0);

    remove(filename.c_str());
}

void ruleazaTeste() {
    testTask();

    testValidareTaskValid();
    testValidareDescriereVida();
    testValidareStareInvalida();
    testValidareProgramatoriInvalid();

    testRepositoryLoad();
    testRepositoryAdaugare();

    testServiceAdaugare();
    testServiceAdaugareInvalida();
    testServiceSortareDupaStare();
    testServiceFiltrareProgramator();
}


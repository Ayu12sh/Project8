#ifndef PEOPLEDB_H
#define PEOPLEDB_H

#include <fstream>
#include "BST.h"
#include "People.h"

class PeopleDB {
private:
    BST<People> db;

public:
    PeopleDB(string filename) {
        ifstream in(filename);
        if (!in) {
            cout << "File not found.\n";
            return;
        }

        string name;
        Date d;
        while (in >> name >> d) {
            People p(name, d);
            db.insert(p);
        }
        in.close();
    }

    void add(People p) { db.insert(p); }

    bool remove(People p) {
        People temp;
        if (db.search(p, temp)) {
            db.remove(temp);
            return true;
        }
        return false;
    }

    bool modify(People oldP, People newP) {
        if (!remove(oldP)) return false;
        add(newP);
        return true;
    }

    bool searchPerson(People p) {
        People found;
        return db.search(p, found);
    }

    void displayPreorder() {
        db.preorder(toScreen);
    }

    void displaySorted() {
        db.inorder(toScreen);
    }

    static void toScreen(People& p) {
        cout << p << endl;
    }

    static void toFile(People& p) {
        extern ofstream fsOut;
        fsOut << p << endl;
    }

    void saveDatabase() {
        db.preorder(toFile);
    }
};

#endif

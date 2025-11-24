#include <iostream>
#include <fstream>
#include "PeopleDB.h"
using namespace std;

ofstream fsOut("studentDB2.txt", ios::app);

int main() {
    string file;
    cout << "Welcome to the People Database System.\n";
    cout << "Enter input file name: ";
    cin >> file;

    PeopleDB db(file);

    int option;

    do {
        cout << "\n1. Add a new person\n"
             << "2. Remove a person\n"
             << "3. Modify the database\n"
             << "4. Search for a person\n"
             << "5. Display database\n"
             << "6. Display database sorted\n"
             << "7. Quit and save\n--> ";

        cin >> option;

        if (option == 1) {
            char again = 'Y';
            while (again == 'Y' || again == 'y') {
                People p;
                cout << "Enter name and birthday (m d y): ";
                cin >> p;
                db.add(p);
                cout << "Add another? (Y/N): ";
                cin >> again;
            }
        }

        else if (option == 2) {
            char again = 'Y';
            while (again == 'Y' || again == 'y') {
                People p;
                cout << "Enter name and birthday to remove: ";
                cin >> p;

                if (db.remove(p))
                    cout << "Removed.\n";
                else
                    cout << "Not found.\n";

                cout << "Remove another? (Y/N): ";
                cin >> again;
            }
        }

        else if (option == 3) {
            People oldP, newP;
            cout << "Enter old name and birthday: ";
            cin >> oldP;

            if (db.searchPerson(oldP)) {
                cout << "Enter new name and birthday: ";
                cin >> newP;

                db.modify(oldP, newP);
                cout << "Modified.\n";
            }
            else
                cout << "Person not found.\n";
        }

        else if (option == 4) {
            People p;
            cout << "Enter name and birthday: ";
            cin >> p;

            if (db.searchPerson(p)) cout << "Found: " << p << endl;
            else cout << "Not found.\n";
        }

        else if (option == 5) {
            cout << "\nDatabase (preorder):\n";
            db.displayPreorder();
        }

        else if (option == 6) {
            cout << "\nDatabase (sorted):\n";
            db.displaySorted();
        }

    } while (option != 7);

    cout << "Saving database...\n";
    db.saveDatabase();
    cout << "Saved to studentDB2.txt\nBye!\n";

    return 0;
}

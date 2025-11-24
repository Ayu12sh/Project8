#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include "Date.h"
using namespace std;

class People {
private:
    string name;       // unique first name
    Date birthday;

public:
    People(string n = "", Date d = Date())
        : name(n), birthday(d) {}

    // getters / setters
    string getName() const { return name; }
    Date getBirthday() const { return birthday; }

    void setName(string n) { name = n; }
    void setBirthday(Date d) { birthday = d; }

    // comparison by name ONLY
    bool operator<(const People& rhs) const {
        return name < rhs.name;
    }

    bool operator>(const People& rhs) const {
        return name > rhs.name;
    }

    bool operator==(const People& rhs) const {
        return name == rhs.name && birthday == rhs.birthday;
    }

    // stream operators
    friend istream& operator>>(istream& in, People& p) {
        in >> p.name >> p.birthday;
        return in;
    }

    friend ostream& operator<<(ostream& out, const People& p) {
        out << p.name << " " << p.getBirthday();
        return out;
    }
};

#endif

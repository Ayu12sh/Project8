#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int m = 1, int d = 1, int y = 1900)
        : month(m), day(d), year(y) {}

    // getters
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }

    // setters
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    void setYear(int y) { year = y; }

    // input operator
    friend istream& operator>>(istream& in, Date& d) {
        in >> d.month >> d.day >> d.year;
        return in;
    }

    // output operator
    friend ostream& operator<<(ostream& out, const Date& d) {
        out << d.month << " " << d.day << " " << d.year;
        return out;
    }

    bool operator==(const Date& other) const {
        return month == other.month &&
               day == other.day &&
               year == other.year;
    }
};

#endif

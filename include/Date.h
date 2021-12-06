#ifndef Date_H
#define Date_H

#include "../Exceptions/InvalidDate.h"

#include <string>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>

class Date {
public:
    Date();
    Date(unsigned int year, unsigned int month, unsigned int day);
    Date(std::string yearMonthDay);
    bool operator ==(const Date& right) {
        return isEqualTo(right);
    }
    bool operator !=(const Date& right) {
        return isNotEqualTo(right);
    }
    bool operator <=(const Date& right) {
        return isEqualTo(right) || isBefore(right);
    }
    bool operator <(const Date& right) {
        return isBefore(right);
    }
    bool operator >=(const Date& right) {
        return isEqualTo(right) || isAfter(right);  // could use > and ==
    }
    bool operator > (const Date& right) {
        return isAfter(right);
    }
    Date& operator ++ () {
        day++;
        if (!isValid()) {
            month++;
            day = 1;
            if (!isValid()) {
                month = 1;
                year++;
            }
        }
        return *this;
    }
    Date operator ++ (int) {
        Date temp = *this;
        ++* this;
        return temp;
    }
    Date& operator -- () {
        day--;
        if (!isValid()) {
            month--;
            day = daysMonth(month + 1 , year);
            if (!isValid()) {
                month = 12;
                year--;
            }
        }
        return *this;
    }
    Date operator -- (int) {
        Date temp = *this;
        --* this;
        return temp;
    }

    Date& setYear(unsigned int year);
    Date& setMonth(unsigned int month);
    Date& setDay(unsigned int day);
    Date& setDate(unsigned int year, unsigned int month, unsigned int day);
    unsigned int getYear()const;
    unsigned int getMonth()const;
    unsigned int getDay()const;
    std::string getDate()const;  // returns the date in format "yyyy/mm/dd"
    bool isValid();
    void show()const;
    bool isEqualTo(const Date& date)const;
    bool isNotEqualTo(const Date& date)const;
    bool isAfter(const Date& date)const;
    bool isBefore(const Date& date) const;
private:
    int daysMonth(int month, int year)const;
    bool isLeapYear(int year)const;
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

inline std::ostream& operator <<(std::ostream& os,const Date& right) {
    os << right.getYear()<<'/';
    if(right.getMonth()<10)
        os<<'0'<<right.getMonth()<<'/';
    else
        os<<right.getMonth()<<'/';;
    if(right.getDay()<10)
        os<<'0'<<right.getDay();
    else
        os<<right.getDay();
    return os;
}
inline std::istream& operator >>(std::istream& is, Date& right) {
    int year, m, d;
    char s;
    is >> year >> s >> m >> s >> d;
    right.setDate(year, m, d);
    return is;
}

#endif //Date_H
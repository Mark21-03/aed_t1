#ifndef Date_H
#define Date_H

#include "../Exceptions/invalidDate.h"

#include <string>
#include <istream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <chrono>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS --- localtime warning

class Date {
public:
    /**
     * Default constructor that creates a date for the current name
     */
    Date();
    /**
     * Constructs a Date with year/month/day
     * @param year
     * @param month
     * @param day
     */
    Date(unsigned int year, unsigned int month, unsigned int day);
    /**
     * Constructs a date with a string of type year/month/day
     * @param yearMonthDay
     */
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
    bool isValid() const;
    void show()const;
    bool isEqualTo(const Date& date)const;
    bool isNotEqualTo(const Date& date)const;
    bool isAfter(const Date& date)const;
    bool isBefore(const Date& date) const;
private:
    static int daysMonth(unsigned int month,unsigned int year);
    static bool isLeapYear(unsigned int year);
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

inline std::ostream& operator <<(std::ostream& os,const Date& right) {
    os << right.getYear()<<'/' << setfill('0') <<setw(2) << right.getMonth() << '/' << setw(2) << right.getDay();

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
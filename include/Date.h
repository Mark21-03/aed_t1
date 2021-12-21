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

using namespace std;

#pragma warning(disable : 4996)

class Date {
public:

    /**
     * Default constructor that creates the current date
     */
    Date();

    /**
     * Constructs a Date in format YYYY/MM/DD
     *
     * @param year attribute to be set
     * @param month attribute to be set
     * @param day attribute to be set
     */
    Date(unsigned int year, unsigned int month, unsigned int day);

    /**
     * Constructs a date using a string in the correct format
     *
     * @param yearMonthDay string in format YYYY/MM/DD
     */
    explicit Date(std::string yearMonthDay);

    /**
     * Compares if two dates are the same
     *
     * @param right object compared
     * @return comparison result boolean
     */
    inline bool operator==(const Date &right) const {
        return isEqualTo(right);
    }

    /**
     * Compares if two dates are different
     *
     * @param right object compared
     * @return comparison result boolean
     */
    inline bool operator!=(const Date &right) const {
        return isNotEqualTo(right);
    }

    /**
     * Compares if left date is prior or equal to right date
     *
     * @param right object compared
     * @return comparison result boolean
     */
    inline bool operator<=(const Date &right) const {
        return isEqualTo(right) || isBefore(right);
    }

    /**
     * Compares if left date is prior to right date
     *
     * @param right object compared
     * @return comparison result boolean
     */
    inline bool operator<(const Date &right) const {
        return isBefore(right);
    }

    /**
     * Compares if left date is after or equal right date
     *
     * @param right object compared
     * @return comparison result boolean
     */
    inline bool operator>=(const Date &right) const {
        return isEqualTo(right) || isAfter(right);  // could use > and ==
    }

    /**
     * Compares if left date is after right date
     *
     * @param right object compared
     * @return comparison result boolean
     */
    inline bool operator>(const Date &right) const {
        return isAfter(right);
    }


    /**
     * Increments date by one day, changing month and year if necessary to be valid date
     * @return
     */
    inline Date &operator++() {
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

    /**
     * Increments date by one day, changing month and year if necessary to be valid date
     * @return
     */
    inline Date operator++(int) {
        Date temp = *this;
        ++*this;
        return temp;
    }

    /**
     * Gos back to previous day, changing month and year if necessary to be valid date
     * @return
     */
    inline Date &operator--() {
        day--;
        if (!isValid()) {
            month--;
            day = daysMonth(month + 1, year);
            if (!isValid()) {
                month = 12;
                year--;
            }
        }
        return *this;
    }

    /**
     * Gos back to previous day, changing month and year if necessary to be valid date
     * @return
     */
    inline Date operator--(int) {
        Date temp = *this;
        --*this;
        return temp;
    }


    /**
     * Sets object's attribute to new given value
     * @param newYear new value
     * @return changed Date object
     */
    Date &setYear(unsigned int newYear);

    /**
     * Sets object's attribute to new given value
     * @param newMonth new value
     * @return changed Date object
     */
    Date &setMonth(unsigned int newMonth);

    /**
     * Sets object's attribute to new given value
     * @param newDay new value
     * @return changed Date object
     */
    Date &setDay(unsigned int newDay);

    /**
     * Sets date attributes using the given arguments
     * @param newYear new attribute value
     * @param newMonth new attribute value
     * @param newDay new attribute value
     * @return changed Date object
     */
    Date &setDate(unsigned int newYear, unsigned int newMonth, unsigned int newDay);

    /**
     * Returns copy of year attribute
     * @return
     */
    unsigned int getYear() const;

    /**
     * Returns copy of month attribute
     * @return
     */
    unsigned int getMonth() const;

    /**
     * Returns copy of day attribute
     * @return
     */
    unsigned int getDay() const;

    /**
     * Returns the date in format YYYY/MM/DD
     * @return
     */
    std::string getDate() const;

    /**
     * Tests if date is actually correct/valid
     * @return boolean result of the validity testing
     */
    bool isValid() const;

    /**
     * Prints date in string format YYYY/MM/DD
     */
    void show() const;

    /**
     * Verifies if two dates are equal by comparing each one of
     * their attributes day, month, year
     * @param date object to be compared
     * @return boolean result of the comparison
     */
    bool isEqualTo(const Date &date) const;

    /**
     * Verifies if two dates are different by comparing each one of
     * their attributes day, month, year
     * @param date object to be compared
     * @return boolean result of the comparison
     */
    bool isNotEqualTo(const Date &date) const;

    /**
     * Verifies if date is chronologically after a given date
     * @param date object to be compared
     * @return boolean result of the comparison
     */
    bool isAfter(const Date &date) const;

    /**
     * Verifies if date is chronologically before a given date
     * @param date object to be compared
     * @return boolean result of the comparison
     */
    bool isBefore(const Date &date) const;

private:

    /**
     * Returns how many days a given month should have based on the year
     * (leap year taken into account)
     * @param month to be evaluated
     * @param year to verify if is leap year
     * @return integer with the number of days of that month in that year
     */
    static int daysMonth(unsigned int month, unsigned int year);

    /**
     * Tests if year is a leap year
     * @param year to be evaluated
     * @return boolean saying if its leap year
     */
    static bool isLeapYear(unsigned int year);


    unsigned int year;
    unsigned int month;
    unsigned int day;
};

/**
 * Ostream overload for Date class,
 * outputting date to ostream in format YYYY/MM/DD
 *
 * @param os ostream to be used
 * @param right Date object to be outputted
 * @return ostream used (altered)
 */
inline std::ostream &operator<<(std::ostream &os, const Date &right) {
    os << right.getYear() << '/' << setfill('0') << setw(2) << right.getMonth() << '/' << setw(2) << right.getDay();

    return os;
}

/**
 * Istream overload for Date Class, allowing an input
 * in format YYYY/MM/DD to be converted to given Date object
 * @param is istream that provides the values
 * @param right Date object that receives the values
 * @return istream used (altered)
 */
inline std::istream &operator>>(std::istream &is, Date &right) {
    int year, m, d;
    char s;
    is >> year >> s >> m >> s >> d;
    right.setDate(year, m, d);
    return is;
}

#endif //Date_H
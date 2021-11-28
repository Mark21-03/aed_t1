#include "../include/Date.h"

Date::Date(unsigned int year, unsigned int month, unsigned int day) {
    try {
        this->year = year;
        this->month = month;
        this->day = day;
        if (!isValid())
            throw InvalidDate("Not Valid Date");
    }
    catch (InvalidDate& e) {
        std::cerr <<"error in constructor -> " << e.what() << std::endl;
        // throw;
    }
}

Date::Date(std::string yearMonthDay) {

    char temp; //not that great

    try
    {
        std::istringstream ss(yearMonthDay);

        ss >> this->year >> temp >> this->month >> temp >> this->day;
        if (!isValid())
            throw InvalidDate("Not Valid Date");
    }
    catch (InvalidDate& e)
    {
        std::cerr << "error in constructor -> " << e.what() << std::endl;
        // throw;
    }
    catch (...) {
        std::cerr << "error in constructor -> " << std::endl;
        // throw;
    }
}

Date& Date::setYear(unsigned int year) {
    this->year = year;
    return *this;
}

Date& Date::setMonth(unsigned int month) {
    this->month = month;
    return *this;
}

Date& Date::setDay(unsigned int day) {
    this->day = day;

    return *this;
}

Date& Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
    this->year = year;
    this->month = month;
    this->month = month;

    return *this;
}

unsigned int Date::getYear() const {
    return this->year;
}

unsigned int Date::getMonth() const {
    return this->month;
}

unsigned int Date::getDay() const {
    return this->day;
}

std::string Date::getDate()const {
    std::ostringstream os;
    os << this->year << "/" << this->month << "/" << this->day; // better to use ignore('/')
    return os.str();
}

void Date::show() const {
    std::cout << Date::getDate();
}

bool Date::isValid() {
    if (this->day <= 0)
        return false;
    if (this->month <= 0 || this->month > 12)
        return false;
    else if (this->day <= 0 || this->day > Date::daysMonth(this->month, this->year)) // repetition of code -> not good
        return false;
    return true;
}

int Date::daysMonth(int month, int year) const {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 2 && isLeapYear(year))
        return 29;
    else if (month == 2) {
        return 28;
    }
    else
        return 30;
}

bool Date::isLeapYear(int year) const {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

bool Date::isEqualTo(const Date& date) const {
    return day == date.day && year == date.year && month == date.month;
}

bool Date::isNotEqualTo(const Date& date)const {
    return !(Date::isEqualTo(date));
}

bool Date::isAfter(const Date& date) const {
    if (year > date.year) {
        return true;
    }
    else if (year < date.year) {
        return false;
    }
    else {
        if (month > date.month) {
            return true;
        }
        else if (month < date.month)
            return false;
        else {
            if (day > date.day) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

bool Date::isBefore(const Date& date) const {
    if (isEqualTo(date))
        return false;
    return !isAfter(date);
}

Date::Date() {
    std::time_t t = std::time(0);   // get time now
    struct std::tm now;
    localtime_s(&now, &t);
    year = now.tm_year + 1900;
    month = now.tm_mon + 1;
    day = now.tm_mday + 1;

}
const std::string& InvalidDate::what()const {
    return reason;
};

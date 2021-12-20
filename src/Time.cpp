#include "../include/Time.h"


Time::Time(unsigned hour, unsigned minute, unsigned second) {
    if (hour > 23 || hour < 0) throw InvalidTimeException();
    if (minute > 59 || minute < 0) throw InvalidTimeException();
    if (second > 59 || second < 0) throw InvalidTimeException();

    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

Time &Time::setTime(unsigned newHour, unsigned newMinute, unsigned newSecond) {
    setHour(newHour).setMinute(newMinute).setSecond(newSecond);
    return *this;
}

#include <iostream>

Time &Time::setHour(unsigned newHour) {
    if (newHour > 23 || newHour < 0)
        this->hour = 0;
    else
        this->hour = newHour;

    return *this;

}

Time &Time::setMinute(unsigned newMinute) {
    if (newMinute > 59 || newMinute < 0)
        this->minute = 0;
    else
        this->minute = newMinute;

    return *this;
}

Time &Time::setSecond(unsigned newSecond) {
    if (newSecond > 59 || newSecond < 0)
        this->second = 0;
    else
        this->second = newSecond;

    return *this;
}

Time &Time::setRandomTime() {

    hour = rand() % 24;
    minute = rand() % 60;
    second = rand() % 60;

    return *this;
}

std::string Time::getTime() const {
    std::ostringstream ost;
    ost << *this;
    return ost.str();
}



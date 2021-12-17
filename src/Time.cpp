#include "../include/Time.h"


Time :: Time(unsigned hour, unsigned minute, unsigned second){
    if (hour > 23 || hour<0) throw InvalidTimeException();
    if(minute>59 || minute<0) throw InvalidTimeException();
    if(second>59 || second<0) throw InvalidTimeException();

    setHour(hour);setMinute(minute);setSecond(second);
}

Time& Time :: setTime(unsigned hour, unsigned minute, unsigned second){
    setHour(hour).setMinute(minute).setSecond(second);
    return *this;
}

Time& Time::setHour(unsigned hour){
    this->hour = hour;
    return *this;

}

Time& Time::setMinute(unsigned minute){
    if (minute>59 || minute<0)
        this->minute = 0;
    else
        this->minute = minute;

    return *this;
}
Time& Time::setSecond(unsigned second){
    if(second>59 || second<0)
        this->second = 0;
    else
        this->second = second;

    return *this;
}

Time& Time::setRandomTime() {

    hour = rand() % 24 ;
    minute = rand() % 60;
    second = rand() % 60;

    return *this;
}

std::string Time::getTime() const {
    std::ostringstream ost; ost << *this; return ost.str();
}



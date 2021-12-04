#include "../include/Time.h"
#include "../Exceptions/InvalidTimeException.h"

Time :: Time(unsigned hour, unsigned minute, unsigned second){
    setHour(hour);setMinute(minute);setSecond(second);
}

void Time :: setTime(unsigned hour, unsigned minute, unsigned second){
    setHour(hour);setMinute(minute);setSecond(second);
}

void Time::setHour(unsigned hour){

    if (hour > 23 || hour<0) throw InvalidTimeException();
    this->hour = hour;
}

void Time::setMinute(unsigned minute){

    if(minute>59 || minute<0) throw InvalidTimeException();
    this->minute = minute;
}
void Time::setSecond(unsigned second){
    if(second>59 || second<0) throw InvalidTimeException();
    this->second = second;
}



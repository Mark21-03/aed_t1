#include "../include/Time.h"


Time :: Time(unsigned hour, unsigned minute, unsigned second){
    if (hour > 23 || hour<0) throw InvalidTimeException();
    if(minute>59 || minute<0) throw InvalidTimeException();
    if(second>59 || second<0) throw InvalidTimeException();

    setHour(hour);setMinute(minute);setSecond(second);
}

void Time :: setTime(unsigned hour, unsigned minute, unsigned second){
    setHour(hour);setMinute(minute);setSecond(second);
}

void Time::setHour(unsigned hour){

    this->hour = hour;
}

void Time::setMinute(unsigned minute){

    this->minute = minute;
}
void Time::setSecond(unsigned second){
    this->second = second;
}

void Time::setRandomTime() {

    hour = rand() % 24 ;
    minute = rand() % 60;
    second = rand() % 60;

}



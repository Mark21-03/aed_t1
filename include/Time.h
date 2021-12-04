#ifndef AED_T1_TIME_H
#define AED_T1_TIME_H

#include <iostream>
#include <iomanip>
#include "../Exceptions/InvalidTimeException.h"

class Time{
    private :
        unsigned hour,minute,second;

    public :
        inline Time(){
            std::time_t t = std::time(nullptr);   // get time now
            struct std::tm now = *localtime(&t);

            hour = now.tm_hour;
            minute = now.tm_min;
            second = now.tm_sec;
        }
        Time(unsigned hour, unsigned minute, unsigned second);

        //Setters
        void setTime(unsigned hour, unsigned minute, unsigned second);
        void setHour(unsigned hour);
        void setMinute(unsigned minute);
        void setSecond(unsigned second);

        //Getters
        inline unsigned getHour() const{return this->hour;}
        inline unsigned getMinute() const{return this->minute;}
        inline unsigned getSecond() const{return this->second;}
};

inline bool operator==(const Time &t1,const Time &t2){
    return(t1.getMinute()==t2.getMinute() && t1.getSecond()==t2.getSecond() && t1.getHour()==t2.getHour());
}

inline bool operator!=(const Time &t1,const Time &t2){
    return !(t1.getMinute()==t2.getMinute() && t1.getSecond()==t2.getSecond() && t1.getHour()==t2.getHour());
}

inline bool operator<(const Time &t1,const Time &t2){
    if(t1.getHour()<t2.getHour())
        return true;
    else if(t1.getHour()==t2.getHour() && t1.getMinute()<t2.getMinute())
        return true;
    else if(t1.getHour()==t2.getHour() && t1.getMinute()==t2.getMinute() && t1.getSecond()<t2.getSecond())
        return true;
    else
        return false;
}

inline bool operator<=(const Time &t1,const Time &t2){
    if(t1.getHour()<t2.getHour())
        return true;
    else if(t1.getHour()==t2.getHour() && t1.getMinute()<t2.getMinute())
        return true;
    else if(t1.getHour()==t2.getHour() && t1.getMinute()==t2.getMinute() && t1.getSecond()<t2.getSecond())
        return true;
    else
        return t1==t2;
}


inline std::ostream & operator<<(std::ostream& os,const Time &t){
    os<<std::setfill('0')<<std::setw(2)<<t.getHour()<<":"<<std::setw(2)<<t.getMinute()<<":"<<std::setw(2)<<t.getSecond();
    return os;
}

inline std::istream & operator>>(std::istream& is,Time &t){
    unsigned hour, minute, second;
    char sep1,sep2;

    is>>hour>>sep1>>minute>>sep2>>second;
    if(sep1!=':' || sep2!=':') throw InvalidTimeException();
    t.setTime(hour,minute,second);

    return is;
}


#endif //AED_T1_TIME_H

#ifndef AED_T1_TIME_H
#define AED_T1_TIME_H

#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
#include "../Exceptions/InvalidTimeException.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS --- localtime warning


class Time{
private:
        unsigned hour,minute,second;

public:

        /**
         * Default constructor creates current Time
         */
        inline Time(){
            std::time_t t = std::time(nullptr);   // get time now
            struct std::tm now = *localtime(&t);

            hour = now.tm_hour;
            minute = now.tm_min;
            second = now.tm_sec;
        }

        /**
         * Constructs custom time HH:MM:SS
         *
         * @param hour  attribute to be set
         * @param minute attribute to be set
         * @param second attribute to be set
         */
        Time(unsigned hour, unsigned minute, unsigned second);

        /**
         * Sets all class time attributes at once
         * @param newHour attribute to be set
         * @param newMinute attribute to be set
         * @param newSecond attribute to be set
         * @return
         */
        Time& setTime(unsigned newHour, unsigned newMinute, unsigned newSecond);

        /**
         * Gets attribute hour
         * @return copy of attribute hour
         */
        inline unsigned getHour() const{return this->hour;}

        /**
        * Gets attribute minute
        * @return copy of attribute minute
        */
        inline unsigned getMinute() const{return this->minute;}

        /**
        * Gets attribute second
        * @return copy of attribute second
        */
        inline unsigned getSecond() const{return this->second;}

        /**
         * Changes attribute newHour and returns the changed object
         *
         * @param newHour changing attribute
         * @return changed object
         */
        Time& setHour(unsigned newHour);

        /**
         * Changes attribute newMinute and returns the changed object
         *
         * @param newMinute changing attribute
         * @return changed object
         */
        Time& setMinute(unsigned newMinute);

        /**
        * Changes attribute newSecond and returns the changed object
        *
        * @param newSecond changing attribute
        * @return changed object
        */
        Time& setSecond(unsigned newSecond);


        /**
         * Sets and returns a random time in format HH:MM:SS
         *
         * @return random time
         */
        Time& setRandomTime();



        std::string getTime() const;
};

/**
 * Compares if two Time objects are equal. They are the same if they have
 * the same if attributes hour, second, minute are the same.
 *
 * @param t1 left side Time object to be compared
 * @param t2 right side Time object to be compared
 * @return boolean with the result of the comparison
 */
inline bool operator==(const Time &t1,const Time &t2){
    return(t1.getMinute()==t2.getMinute() && t1.getSecond()==t2.getSecond() && t1.getHour()==t2.getHour());
}


/**
 * Compares if two Time objects are different. They are different if at least
 * one of their attributes hour, minute, second dont match.
 *
 * @param t1 left side Time object to be compared
 * @param t2 right side Time object to be compared
 * @return boolean with the result of the comparison
 */
inline bool operator!=(const Time &t1,const Time &t2){
    return !(t1.getMinute()==t2.getMinute() && t1.getSecond()==t2.getSecond() && t1.getHour()==t2.getHour());
}

/**
 * Tests if left Time object is lesser than right Time object.
 * The comparison is based on the represented time.
 *
 * @param t1 left side Time object to be compared
 * @param t2 right side Time object to be compared
 * @return boolean with the result of the comparison
 */
inline bool operator<(const Time &t1,const Time &t2){
    if(t1.getHour()!=t2.getHour())
        return t1.getHour()<t2.getHour();
    else if(t1.getMinute()!=t2.getMinute())
        return t1.getMinute()<t2.getMinute();
    return t1.getSecond()<t2.getSecond();

}

/**
 *
 * @param t1 left side Time object to be compared
 * @param t2 right side Time object to be compared
 * @return boolean with the result of the comparison
 */
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

/**
 * Ostream overload for Time class,
 * outputting time to ostream in format HH:MM:SS
 *
 * @param os ostream to be used
 * @param t Time object to be outputted
 * @return ostream used (altered)
 */
inline std::ostream & operator<<(std::ostream& os,const Time &t){
    os<<std::setfill('0')<<std::setw(2)<<t.getHour()<<":"<<std::setw(2)<<t.getMinute()<<":"<<std::setw(2)<<t.getSecond();
    return os;
}

/**
 * Istream overload for Time Class, allowing an input
 * in format HH:MM:SS to be converted to given Time object
 * @param is istream that provides the values
 * @param t Time object that receives the values
 * @return istream used (altered)
 */
inline std::istream & operator>>(std::istream& is,Time &t){
    unsigned hour, minute, second;
    char sep1,sep2;

    is>>hour>>sep1>>minute>>sep2>>second;
    t.setTime(hour,minute,second);

    return is;
}


#endif //AED_T1_TIME_H

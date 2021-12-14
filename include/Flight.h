#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <utility>

#include "Date.h"
#include "Time.h"

#define STRING_MAX_VALUE 50

typedef int flightNumber;

class Flight{
private:

    flightNumber number;
    Date departureDate; // TODO: THE DATE CLASS DOES NOT HAVE HOURS AND MINUTES, consider creating a time class to this and then a attribute should tell the time
    Time departureTime;
    // TODO: OCCUPATION OF THE FLIGHT
    float duration;
    char origin[STRING_MAX_VALUE]{},destiny[STRING_MAX_VALUE]{};
    // maybe add a mile counter

public:

    Flight() = default;
    Flight(flightNumber number,const Date& departureDate,const Time& departureTime, float duration,std::string origin,std::string destiny);

    //Setters
    Flight& setNumber(flightNumber number);
    Flight& setDepartureDate(const Date& departureDate);
    Flight& setDepartureTime(const Time& departureTime);
    Flight& setDuration(float duration);
    Flight& setOrigin(const std::string& origin);
    Flight& setDestiny(const std::string& destiny);

    //Getters
    flightNumber getNumber() const;
    Date getDepartureDate() const;
    Time getDepartureTime() const;
    float getDuration() const;
    std::string getOrigin() const;
    std::string getDestiny() const;
    char* getOriginC() ;
    char* getDestinyC();



    // TODO: DO A CHECK IN FUNCTION WHICH WILL TAKE A PASSENGER - NOT HERE THOUGH
};

inline bool operator == (const Flight&l, const Flight& r) {
    return l.getNumber() == r.getNumber();
}

inline bool operator != (const Flight&l, const Flight& r) {
    return !(l.getNumber() == r.getNumber());
}

inline bool operator < (const Flight&l, const Flight& r) {
    return l.getNumber() < r.getNumber();
}

inline std::ostream& operator<< (std::ostream& os, Flight& r) {
    os << r.getNumber()  << " " << r.getDepartureDate() << " " << r.getDepartureTime() << " ";

    os << r.getDuration();

    bool b = false;
    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        if(!b)
            os << (r.getOriginC()[i]);
        else
            os << '\0';
        if ( r.getOriginC()[i] == '\0') {
            b = true;
        }
    }

    b = false;
    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        if(!b)
            os << (r.getDestinyC()[i]);
        else
            os << '\0';
        if ( r.getDestinyC()[i] == '\0') {
            b = true;
        }
    }

    os << "\n";

    return os;
}

inline std::istream& operator>> (std::istream& is, Flight& r) {

    int n;
    float du;

    Date date;
    Time time;

    is >> n;

    is >> date;

    is >> time;
    is >> du;
    r.setNumber(n).setDuration(du).setDepartureDate(date).setDepartureTime(time);

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        r.getOriginC()[i] = is.get();
    }

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        r.getDestinyC()[i] = is.get();
    }


    return is;

}

#endif //FLIGHT_H
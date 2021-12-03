#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <utility>

#include "Date.h"

#define STRING_MAX_VALUE 30

class Flight{
private:
    int number;
    Date departureDate; // TODO: THE DATE CLASS DOES NOT HAVE HOURS AND MINUTES, consider creating a time class to this and then a attribute should tell the time
    // Time departureTime
    float duration; //hours
    char origin[STRING_MAX_VALUE]{},destiny[STRING_MAX_VALUE]{}; // MAYBE IT WOULD BE GOOD TO STORE THIS IN A ARRAY OF CHARS
    // maybe add a mile counter

public:

    Flight() = default;
    Flight(int number,const Date& departureDate,float duration,std::string origin,std::string destiny);

    //Setters
    Flight& setNumber(int number);
    Flight& setDepartureDate(Date departureDate);
    Flight& setDuration(float duration);
    Flight& setOrigin(std::string origin);
    Flight& setDestiny(std::string destiny);

    //Getters
    int getNumber() const;
    Date& getDepartureDate();
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
    os << r.getNumber()  << " " << r.getDepartureDate().getDate() << " ";

    os << r.getDuration() << " " ;

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        os << (r.getOriginC()[i]);
    }

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        os << (r.getDestiny()[i]);
    }

    os << std::endl;

    return os;
}

inline std::istream& operator>> (std::istream& is, Flight& r) {

    int n;
    float d;
    std::string o, dest;

    is >> n;
    r.setNumber(n);

    is >> r.getDepartureDate();

    is >> d;
    r.setDuration(d);

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        is >> (r.getOriginC()[i]);
    }

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        is >> (r.getDestinyC()[i]);
    }

    return is;

}

#endif //FLIGHT_H
#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <utility>
#include <queue>
#include "Baggage.h"

#include "Date.h"
#include "Time.h"


#define STRING_MAX_VALUE 50

typedef unsigned int flightNumber;

class Flight{
private:

    flightNumber number;
    Date departureDate;
    Time departureTime;
    int occupation;
    float duration;
    char origin[STRING_MAX_VALUE]{},destiny[STRING_MAX_VALUE]{};
    // planePlate plane; // TODO

    queue<Baggage> planeStoredBaggage;

public:
    friend class CompareFlightsByDepartureDate;
    friend class CompareFlightsByDepartureTime;
    friend class CompareFlightsByOccupation;

    Flight() = default;
    Flight(flightNumber number,const Date& departureDate,const Time& departureTime, float duration,std::string origin,std::string destiny);
    Flight(flightNumber number,const Date& departureDate,const Time& departureTime, int occupation, float duration,std::string origin,std::string destiny);

    //Setters
    Flight& setNumber(flightNumber newNumber);
    Flight& setDepartureDate(const Date& newDepartureDate);
    Flight& setDepartureTime(const Time& newDepartureTime);
    Flight& setDuration(float newDuration);
    Flight& setOrigin(const std::string& newOrigin);
    Flight& setDestiny(const std::string& newDestiny);
    Flight& setOccupation (int newOccupation);
    void addBaggage2Flight(const Baggage& baggage);
    Baggage takeBaggageFromFlight();

    //Getters
    flightNumber getNumber() const;
    Date getDepartureDate() const;
    Time getDepartureTime() const;
    float getDuration() const;
    std::string getOrigin() const;
    std::string getDestiny() const;
    char* getOriginC() ;
    char* getDestinyC();
    int getOccupation() const;
    queue<Baggage> getPlaneStoredBaggage() const;




};

inline bool operator == (const Flight&l, const Flight& r) {
    return l.getNumber() == r.getNumber();
}

inline bool operator != (const Flight&l, const Flight& r) {
    return l.getNumber() != r.getNumber();
}

inline bool operator < (const Flight&l, const Flight& r) {
    return l.getNumber() < r.getNumber();
}

inline std::ostream& operator<< (std::ostream& os, Flight& r) {
    os << r.getNumber()  << " " << r.getDepartureDate() << " " << r.getDepartureTime() << " ";

    os << r.getOccupation() << " " << r.getDuration();

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

    int n, oc;
    float du;

    Date date;
    Time time;

    is >> n >> date >> time >> oc >> du;

    r.setNumber(n).setDuration(du).setOccupation(oc).setDepartureDate(date).setDepartureTime(time);

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        r.getOriginC()[i] = is.get();
    }

    for (int i = 0; i < STRING_MAX_VALUE; ++i) {
        r.getDestinyC()[i] = is.get();
    }


    return is;

}

class CompareFlightsByDepartureDate {
public:
    bool operator()(Flight* l , Flight* r) {
        return l->departureDate.isBefore(r->departureDate);
    }
};

class CompareFlightsByDepartureTime {
public:
    bool operator()(Flight* l , Flight* r) {
        return l->departureTime < r->departureTime;
    }
};

class CompareFlightsByOccupation {
public:
    bool operator()(Flight* l , Flight* r) {
        return l->occupation < r->occupation;
    }
};

#endif //FLIGHT_H
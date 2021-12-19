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
    int maxCapacity;

    queue<Baggage> planeStoredBaggage;

public:
    friend class CompareFlightsByDepartureDate;
    friend class CompareFlightsByDepartureTime;
    friend class CompareFlightsByOccupation;
   /**
    * Default constructor
    */
    Flight() = default;
    /**
     * Constructs a Flight object with number, departure date,
     * departure time, duration, origin and destiny
     * @param number Number of the flight
     * @param departureDate Date (year/month/day) in which the flight takes place
     * @param departureTime Time (hours:minutes:seconds) in which the flight takes place
     * @param duration Duration of the flight in hours
     * @param origin Place from where the flight departs
     * @param destiny Place to where the flight arrives
     */
    Flight(flightNumber number,const Date& departureDate,const Time& departureTime, float duration,std::string origin,std::string destiny);
    /**
     * Constructs a Flight object with number, departure date,
     * departure time, occupation, duration, origin and destiny
     * @param number Number of the flight
     * @param departureDate Date (year/month/day) in which the flight takes place
     * @param departureTime Time (hours:minutes:seconds) in which the flight takes place
     * @param occupation Current occupation of the flight
     * @param duration Duration of the flight in hours
     * @param origin Place from where the flight departs
     * @param destiny Place to where the flight arrives
     * @param maxCapacity max Capacity of the plane responsible for this flight
     */

    Flight(flightNumber number,const Date& departureDate,const Time& departureTime, int occupation, float duration,std::string origin,std::string destiny, int maxCapacity);

    //Setters
    /**
     * Sets the number of the Flight
     * @param newNumber value to be set
     * @return reference to the flight
     */
    Flight& setNumber(flightNumber newNumber);

    /**
     * Sets the Date of the departure
     * @param newDepartureDate value to be set
     * @return reference to the flight
     */
    Flight& setDepartureDate(const Date& newDepartureDate);

    /**
     * Sets the Time of the departure
     * @param newDepartureTime value to be set
     * @return reference to the flight
     */
    Flight& setDepartureTime(const Time& newDepartureTime);

    /**
     * Sets the duration in hours of the flight
     * @param newDuration float value to be set
     * @return reference to the flight
     */
    Flight& setDuration(float newDuration);

    /**
     * Sets the origin of the Flight
     * @param newOrigin value to be set
     * @return reference to the flight
     */
    Flight& setOrigin(const std::string& newOrigin);

    /**
     * Sets the destiny of the Flight
     * @param newDestiny value to be set
     * @return reference to the flight
     */
    Flight& setDestiny(const std::string& newDestiny);

    /**
     * Sets the occupation of the Flight
     * @param newOccupation value to be set
     * @return reference to the flight
     */
    Flight& setOccupation (int newOccupation);

    /**
     *
     * @param maxCapacity
     * @return reference to the flight
     */
    Flight& setMaxCapacity(int maxCapacity);

    /**
     * Add an object Baggage to be transported to the same destiny of the Flight
     * @param baggage object Baggage
     */
    void addBaggage2Flight(const Baggage& baggage);

    /**
     * Doesn't transport the Baggage with the Flight and it's removed
     * @return object Baggage removed
     */
    Baggage takeBaggageFromFlight();

    //Getters
    /**
     * Gives the number of the flight
     * @return Flight's number
     */
    flightNumber getNumber() const;

    /**
     * Gives the Date in which the Flight departs
     * @return Departure Date (year/month/day)
     */
    Date getDepartureDate() const;

    /**
     * Gives the Time in which the Flight departs
     * @return Departure Time (hours:minutes:seconds)
     */
    Time getDepartureTime() const;

    /**
     * Gives the duration of the Flight
     * @return Flight's duration
     */
    float getDuration() const;

    /**
     * Gives the origin of the Flight (from where it departs)
     * @return Flight's origin
     */
    std::string getOrigin() const;

    /**
     * Gives the destiny of the Flight (to where it arrives)
     * @return Flight's destiny
     */
    std::string getDestiny() const;

    /**
     * Gives the max capacity of the plane that operates that flight
     * @return max capacity of the flight
     */
    int getMaxCapacity() const;

    /**
     *
     * @return
     */
    char* getOriginC() ;

    /**
     *
     * @return
     */
    char* getDestinyC();

    /**
     * Gives the current occupation of the Flight
     * @return Flight's current occupation
     */
    int getOccupation() const;

    /**
     * Gives the Baggages that are stored in the plane that takes the Flight
     * @return Baggages in the Plane that will do the Flight
     */
    queue<Baggage> getPlaneStoredBaggage() const;




};
/**
 * Compares if two flights are the same
 * @param l Flight to be compared
 * @param r Flight to be compared
 * @return comparison result boolean
 */
inline bool operator == (const Flight&l, const Flight& r) {
    return l.getNumber() == r.getNumber();
}

/**
 * Compares if two Flights are different
 * @param l Flight to be compared
 * @param r Flight to be compared
 * @return comparison result boolean
 */
inline bool operator != (const Flight&l, const Flight& r) {
    return l.getNumber() != r.getNumber();
}

/**
 * Compares if the left Flight is minor than the right one
 * @param l Flight to be compared
 * @param r Flight to be compared
 * @return comparison result boolean
 */
inline bool operator < (const Flight&l, const Flight& r) {
    return l.getNumber() < r.getNumber();
}

/**
 *Ostream overload for Flight Class,outputting flight in the format:
 * number departure_date departure_time occupation duration origin destiny
 * @param os ostream to be used
 * @param r Flight Object to be outputted
 * @return ostream used (altered)
 */
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

    os << r.getMaxCapacity();
    os << "\n";

    return os;
}

/**
 * Istream overload for Flight Class, allowing an input
 *  to be converted to given Flight object
 * @param is istream that provides the values
 * @param r FLight object that receives the values
 * @return istream used (altered)
 */
inline std::istream& operator>> (std::istream& is, Flight& r) {

    int n, oc, max;
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

    is >> max;

    r.setMaxCapacity(max);

    return is;

}


class CompareFlightsByDepartureDate {
public:
    /**
     * Compares the Flights using their Departure Date
     * @param l Flight to be compared
     * @param r Flight to be compared
     * @return comparison result boolean
     */
    bool operator()(Flight* l , Flight* r) {
        return l->departureDate.isBefore(r->departureDate);
    }
};


class CompareFlightsByDepartureTime {
public:
    /**
     * Compares the Flights using their Departure Time
     * @param l Flight to be compared
     * @param r Flight to be compared
     * @return comparison result boolean
     */
    bool operator()(Flight* l , Flight* r) {
        return l->departureTime < r->departureTime;
    }
};

class CompareFlightsByOccupation {
public:
    /**
     * Compares the Flights using their occupation
     * @param l Flight to be compared
     * @param r Flight to be compared
     * @return comparison result boolean
     */
    bool operator()(Flight* l , Flight* r) {
        return l->occupation < r->occupation;
    }
};

#endif //FLIGHT_H
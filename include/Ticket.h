#ifndef TICKET_H
#define TICKET_H

#include "Flight.h"
#include "Baggage.h"

enum ClassType {
    executive = 'x',
    economic = 'e'
};

class Ticket {
public:

    /**
     * Default constructor
     */
    Ticket() = default;

    /**
     * Constructs a ticket for a flight and a passenger with
     * it's baggage for a specific price for a plane seat class
     * @param flight ID of the flight the ticket refers to
     * @param passengerID ID of the passenger who owns the ticket
     * @param price ticket price
     * @param baggage baggage taken with the passenger in the flight
     * @param tClass plane seat class
     */
    Ticket(flightNumber flight, unsigned int passengerID, float price, Baggage baggage, ClassType tClass);

    /**
     * Gives ticket's passenger owner ID
     * @return passenger's ID who owns the ticket
     */
    unsigned int getPassengerID() const;

    /**
     * Gives plane seat class
     * @return plane seat class of the ticket
     */
    ClassType getTClass() const;

    /**
     * Gives ticket's price
     * @return ticket's price
     */
    float getPrice() const;

    /**
     * Gives ticket's flight number
     * @return ticket's flight number
     */
    flightNumber getFlightNumber() const;

    /**
     * Gives a copy of the baggage specified when ticket was created
     * @return  copy of the baggage in ticket
     */
    Baggage getBaggage() const;

    /**
     * Sets a new price for a ticket
     * @param newPrice
     * @return changed ticket reference
     */
    Ticket &setPrice(float newPrice);

    /**
     * Sets a new seat class for a ticket
     * @param newTClass
     * @return changed ticket reference
     */
    Ticket &setTclass(char newTClass);

    /**
     * Sets a new passenger owner ID for a ticket
     * @param passengerid
     * @return changed ticket reference
     */
    Ticket &setPassengerId(unsigned int passengerid);

    /**
     * Sets a new flight ID for a ticket
     * @param flightNumber
     * @return changed ticket reference
     */
    Ticket &setFlightNumber(flightNumber flightNumber);

    /**
     * Sets a new passenger's baggage for a ticket
     * @param baggage
     * @return changed ticket reference
     */
    Ticket &setBaggage(Baggage baggage);

private:
    flightNumber flightnumber;
    unsigned int passengerID;
    float price;
    Baggage basementBaggage;
    ClassType tClass;
};


/**
 * Tests if two tickets are the same by comparing their
 * passenger owner ID and the flight ID they refer to
 * @param l left-hand side ticket to be compared
 * @param r right-hand side ticket to be compared
 * @return boolean result from the comparison
 */
inline bool operator==(const Ticket &l, const Ticket &r) {
    return l.getFlightNumber() == r.getFlightNumber() && l.getPassengerID() == r.getPassengerID();
}

/**
 * Tests if a ticket is lesser than another by comparing their
 * passenger owner ID and the flight ID they refer to in ascending order
 * @param l left-hand side ticket to be compared
 * @param r right-hand side ticket to be compared
 * @return boolean result from the comparison
 */
inline bool operator<(const Ticket &t1, const Ticket &t2) {
    if (t1.getFlightNumber() != t2.getFlightNumber())
        return t1.getFlightNumber() < t2.getFlightNumber();
    return t1.getPassengerID() < t2.getPassengerID();
}

/**
 * Allows for outputting a ticket to a ostream
 * @param os ostream to be used
 * @param l ticket to be outputted
 * @return ostream used (changed)
 */
inline std::ostream &operator<<(std::ostream &os, const Ticket &l) {

    os << l.getFlightNumber() << " ";

    os << l.getPassengerID() << " " << l.getTClass()
       << " " << std::fixed << std::setprecision(2) << l.getPrice() << " " << l.getBaggage();

    os << endl;

    return os;
}

/**
 * Allows for inputting a ticket from a istream
 * @param is istream to be used
 * @param l ticket to be set
 * @return istream used (changed)
 */
inline std::istream &operator>>(std::istream &is, Ticket &l) {

    flightNumber flightNumber1;
    unsigned int pId;
    float price;
    int cType;
    Baggage baggage;

    is >> flightNumber1 >> pId >> cType >> price >> baggage;

    l.setPrice(price).setFlightNumber(flightNumber1).setPassengerId(pId).setTclass((char) cType).setBaggage(baggage);

    return is;
}

#endif //TICKET_H

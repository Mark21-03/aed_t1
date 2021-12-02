#ifndef PASSENGER_H
#define PASSENGER_H

#include "Flight.h"
#include "../Exceptions/NameToLongException.h"
#include "Ticket.h"

#include <list>
#include <string>
#include <queue>
#include <numeric>

#define LONGEST_ACCEPTED_NAME 150
// INFO: the longest name in the world as 950 chars


class Passenger {
public:
    Passenger(unsigned int ID, const std::string& name){
        setName(name);
        this->ID = ID;
    };

    // booking

    void addTicket(Ticket& ticket);

    // boarding

    // void checkIn(); -> this should not be here... maybe we should consider putting it in the service class

    // Passenger Information

    float moneySpent() const; // this is useful information for a company - A passenger can cancel a flight
    // float mileage() const;

    // getters

    std::string getName() const;
    char* getNameC() {
        return name;
    }
    unsigned int getID() const;
    std::list<Ticket>& getPastFlights();
    std::list<Ticket>& getNextFlights();

    // setters

    Passenger& setName(const std::string& name);
    Passenger& setID(unsigned int ID);
    Passenger& setPastFlights(const std::list<Ticket>& lFlights);
    Passenger& setNextFlights(const std::list<Ticket>& lFlights);


private:
    unsigned int ID;
    char name[LONGEST_ACCEPTED_NAME]{};

    std::list<Ticket> pastFlights; // it is useful to keep track of flights ---> WE COULD EVEN DO A MILEAGE CAMPAIGN TODO
    std::list<Ticket> nextFlights; // ticket should have the information about the flights

};

inline std::ostream & operator<<(std::ostream& os, Passenger& l) {

    os << l.getID() << " ";

    for (int i = 0; i < LONGEST_ACCEPTED_NAME; ++i) {
        os << (l.getNameC()[i]);
    }

    os << " " << l.getPastFlights().size() << " ";
    for (auto& t: l.getPastFlights()) {
        os << t.getFlightInfo().getNumber() << " "; // maybe the rest of the ticket information can go away( leaving only ticket with parameter flight and owner)
    }

    os << l.getNextFlights().size() << " ";

    for (auto& t: l.getNextFlights()) {
        os << t.getFlightInfo().getNumber() << " "; // maybe the rest of the ticket information can go away( leaving only ticket with parameter flight and owner)
    }
    os << std::endl;
    return os;
}


#endif //PASSENGER_H

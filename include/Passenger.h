//
// Created by ricar on 29/11/2021.
//

#ifndef PASSENGER_H
#define PASSENGER_H

#include "Flight.h"
#include "../Exceptions/NameToLongException.h"
#include "Ticket.h"

#include <list>
#include <string>
#include <queue>
#include <numeric>

#define LONGEST_ACCEPTED_NAME 1000
// INFO: the longest name in the world as 950 chars

class Passenger {
public:
    Passenger(unsigned int ID, const std::string& name){
        setName(name);
        this->ID = ID;
    };

    // booking

    void buyTicket(Ticket& ticket);

    // boarding

    // void checkIn(); -> this should not be here... maybe we should consider putting it in the service class

    // Passenger Information

    float moneySpent() const; // this is useful information for a company - A passenger can cancel a flight
    // float mileage() const;

    // getters

    std::string getName() const;
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


#endif //PASSENGER_H

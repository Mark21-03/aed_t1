//
// Created by ricar on 29/11/2021.
//

#include "../include/Passenger.h"

#include <utility>


std::string Passenger::getName() const{
    int i=0;
    string s;
    char c;
    while ((c = name[i++] )!= '\0') {
        s+=c;
    }
    return s;
}

unsigned int Passenger::getID() const {
    return ID;
}

Passenger& Passenger::setName(const string &name) {

    int i = 0;
    for (auto c: name) {
        if (i > LONGEST_ACCEPTED_NAME)
            throw NameToLongException();
        this->name[i++] = c;
    }
    this->name[i] = '\0';

    return *this;
}

Passenger& Passenger::setID(unsigned int ID) {
    this -> ID = ID;

    return *this;
}
/*
float Passenger::moneySpent() const {
    float sum = 0.0f;
    for (auto t: pastFlights) {
        sum += t.getPrice();
    }
    return sum;
}*/

void Passenger::addTicket(Ticket &ticket) { // this should be different when we make the flight has a time associated

    for (auto t = nextFlights.begin(); t != nextFlights.end(); t++) {
        if (t->getFlightInfo().getDepartureDate() > ticket.getFlightInfo().getDepartureDate()) {
            nextFlights.insert(t,ticket);
            return;
        }
    }
    nextFlights.insert(nextFlights.end(),ticket);
}

std::list<Ticket> &Passenger::getPastFlights() {
    return this->pastFlights;
}

std::list<Ticket> &Passenger::getNextFlights() {
    return this->nextFlights;
}

Passenger &Passenger::setPastFlights(const std::list<Ticket>& lFlights) {
    this->pastFlights = lFlights;
    return *this;
}

Passenger &Passenger::setNextFlights(const std::list<Ticket>& lFlights) {
    this->nextFlights = lFlights;
    return *this;
}

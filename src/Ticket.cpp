#include "../include/Ticket.h"

Flight Ticket::getFlightInfo() const{
    return this->flightInfo;
}

Ticket::Ticket(Flight & flight) {
    this->flightInfo = flight;
    passengerID = NO_OWNER;
}




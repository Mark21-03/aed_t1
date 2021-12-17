#include "../include/Ticket.h"

Flight Ticket::getFlightInfo() const{
    return this->flightInfo;
}

Ticket::Ticket(Flight & flight) {
    this->flightInfo = flight;
    passengerID = NO_OWNER;
}

float Ticket::getPrice() const {return this->price;}
//Baggage Ticket::getBaggage() const {return this->bag1;}
bool Ticket::getBaggage() const {return this->baggage;}
flightNumber Ticket::getFlightNUmber() const {return this->flightnumber;}
int Ticket::getPassengerID() {return this->passengerID;}
ClassType Ticket::getTClass() const {return this->tClass;}

Ticket &Ticket::setPrice(float price) {this->price=price; return *this;}
Ticket &Ticket::setBaggage(bool baggage) {this->baggage=baggage; return *this;}
//Ticket &Ticket::setBaggage(Baggage bag1) {this->bag1=bag1; return *this;}
Ticket &Ticket::setFlightNumber(flightNumber flightNumber) {this->flightnumber=flightNumber; return *this;}
Ticket &Ticket::setPassengerId(int passengerid) {this->passengerID=passengerid; return *this;}
Ticket &Ticket::setTclass(char tClass) {
    if (tClass=='x')
        this->tClass=executive;
    else if (tClass=='e')
        this->tClass=economic;

    return *this;
}

/*bool Ticket::validBuy(Ticket ticket) {
    if (buys[ticket.flightnumber]<fligths.)
}*/


#include "../include/Ticket.h"

/*Flight Ticket::getFlightInfo() const{
    return this->flightInfo;
}*/

/*Ticket::Ticket(Flight & flight) {
    this->flightInfo = flight;
    passengerID = NO_OWNER;
}*/

Ticket::Ticket(flightNumber flight, unsigned int passengerID, float price, Baggage baggage, ClassType tClass) {
    this->flightnumber=flight;
    this->passengerID=passengerID;
    this->price=price;
    this->basementBaggage=baggage;
    this->tClass=tClass;
}


float Ticket::getPrice() const {return this->price;}
//Baggage Ticket::hasBaggage() const {return this->bag1;}
Baggage Ticket::getBaggage() const {return this->basementBaggage;}
flightNumber Ticket::getFlightNumber() const {return this->flightnumber;}
unsigned int Ticket::getPassengerID() const{return this->passengerID;}
ClassType Ticket::getTClass() const {return this->tClass;}

//Flight Ticket::getFlight() const {return this->flight;}

Ticket &Ticket::setPrice(float price) {this->price=price; return *this;}
Ticket &Ticket::setBaggage(Baggage baggage) {this->basementBaggage=baggage; return *this;}
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




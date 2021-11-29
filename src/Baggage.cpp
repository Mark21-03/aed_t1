#include "../include/Baggage.h"

Baggage::Baggage(Passenger passenger) {
    this->passenger=passenger;
}

//getters
Passenger Baggage::getPassengerBaggage() {return this->passenger;}

//setters
void Baggage::setPassengersBaggage(Passenger passenger) {this->passenger=passenger;}



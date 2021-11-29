#include "../include/bagagem.h"

Baggage::Baggage(int passenger) {
    this->passenger=passenger;
}

//getters
Passenger Baggage::getPassengerBaggage() {return this->passenger;}

//setters
void Baggage::setPassengerABaggage(passenger passenger) {this->passenger=passenger;}



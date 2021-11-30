#include "../include/Ticket.h"

Flight& Ticket::getFlightInfo() {
    return this->flightInfo;
}

float Ticket::getPrice() const {
    return this->price;
}

Ticket::Ticket(Flight& flight, const char seat[SEAT_MAP_DIMENSION], char boardingZone, char tClass, float price) {

    flightInfo = flight;

    for (int i = 0; i < SEAT_MAP_DIMENSION; i++) {
        this->seat[i] = seat[i];
    }

    this->boardingZone = boardingZone;
    this->tClass = tClass;
    this->price = price;
}

char Ticket::getBoardingZone() const {
    return boardingZone;
}

char Ticket::getTClass() const {
    return tClass;
}

std::string Ticket::getSeat() const {
    std::string s;
    for (char i : seat) {
        s+=i;
    }
    return s;
}



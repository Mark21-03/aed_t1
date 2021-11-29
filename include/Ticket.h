//
// Created by ricar on 29/11/2021.
//

#ifndef TICKET_H
#define TICKET_H

#include "Flight.h"

#define SEAT_MAP_DIMENSION 2

class Ticket {
public:
    Ticket(Flight& flight, const char seat[SEAT_MAP_DIMENSION], char boardingZone, char tClass, float price);
    // getters
    Flight& getFlightInfo();
    char getBoardingZone() const;
    char getTClass() const;
    std::string getSeat() const;
    float getPrice() const;
private:
    Flight flightInfo;
    float price; // maybe it can be cool to make a price class or struct with price and taxes
    char seat[SEAT_MAP_DIMENSION]{};
    char boardingZone;
    char tClass;


};

inline bool operator==(const Ticket& l, const Ticket& r) {
    return l.getPrice()==r.getPrice() && l.getBoardingZone() == r.getBoardingZone() ;
}

#endif //TICKET_H

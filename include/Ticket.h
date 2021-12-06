#ifndef TICKET_H
#define TICKET_H

#include "Flight.h"

#define NO_OWNER -1

//#define SEAT_MAP_DIMENSION 2

class Ticket {
public:
    //Ticket(Flight& flight, const char seat[SEAT_MAP_DIMENSION], char boardingZone, char tClass, float price);
    // getters

    Ticket(Flight& flight);
    Flight getFlightInfo() const;
    int getPassengerID() {
        return passengerID;
    }
    //char getBoardingZone() const;
    //char getTClass() const;
    //std::string getSeat() const;
    //float getPrice() const;
private:
    Flight flightInfo;
    int passengerID;
    //float price;
    //char seat[SEAT_MAP_DIMENSION]{};
    //char boardingZone;
    //char tClass;

};

inline bool operator==(const Ticket& l, const Ticket& r) {
    return l.getFlightInfo() == r.getFlightInfo() ;
}

inline bool operator<(const Ticket& t1, const Ticket& t2){
    return 1; //TODO resolver problema do ID do ticket associado a um flight
}

inline std::ostream& operator <<(std::ostream & os, Ticket& l) {

    os << l.getFlightInfo().getNumber() << " ";

    os << l.getPassengerID();

    os << endl;

    return os;

}

#endif //TICKET_H

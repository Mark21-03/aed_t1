#ifndef TICKET_H
#define TICKET_H

#include "Flight.h"
#include "Baggage.h"

#define NO_OWNER -1

//#define SEAT_MAP_DIMENSION 2

enum ClassType{
    executive = 'x',
    economic ='e'
};

class Ticket {
public:
    // Ticket(Flight& flight);
    Ticket(flightNumber flight, unsigned int passengerID, float price, bool baggage, ClassType tClass);

    int getPassengerID() const;
    ClassType getTClass() const;
    float getPrice() const;

    flightNumber getFlightNumber() const;
    bool hasBaggage() const;

    Ticket& setPrice(float price);

    Ticket& setTclass(char tClass);
    Ticket& setPassengerId(int passengerid);
    Ticket& setFlightNumber(flightNumber flightNumber);
    Ticket& setBaggage(bool baggage);

private:
    flightNumber flightnumber;
    unsigned int passengerID;
    float price;
    bool baggage;
    //Baggage bag1;
    ClassType tClass;
    //'X'= exclusiva e 'E'= económica

};

inline bool operator==(const Ticket& l, const Ticket& r) {
    return l.getFlightNumber() == r.getFlightNumber() && l.getPassengerID() == r.getPassengerID();
}

inline bool operator<(const Ticket& t1, const Ticket& t2){
    return 1; //TODO resolver problema do ID do ticket associado a um flight
}

inline std::ostream& operator <<(std::ostream & os, const Ticket& l) {

    os << l.getFlightNumber() << " ";

    os << l.getPassengerID() << " " << l.getTClass()
    << " " << std::fixed << std::setprecision(2) << l.getPrice() << " " << l.hasBaggage();

    os << endl;

    return os;

}

inline std::istream& operator >>(std::istream& is, Ticket& l) {

    flightNumber flightNumber1;
    unsigned int pId;
    float price;
    char cType;
    bool baggage;

    is >> flightNumber1 >> pId >> cType >> price >> baggage;


    return is;
}

#endif //TICKET_H

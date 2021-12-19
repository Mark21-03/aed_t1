#ifndef TICKET_H
#define TICKET_H

#include "Flight.h"
#include "Baggage.h"

enum ClassType{
    executive = 'x',
    economic ='e'
};

class Ticket {
public:
    Ticket() = default;
    Ticket(flightNumber flight, unsigned int passengerID, float price, Baggage baggage, ClassType tClass);

    unsigned int getPassengerID() const;
    ClassType getTClass() const;
    float getPrice() const;

    flightNumber getFlightNumber() const;
    Baggage getBaggage() const;

    Ticket& setPrice(float newPrice);

    Ticket& setTclass(char newTClass);
    Ticket& setPassengerId(int passengerid);
    Ticket& setFlightNumber(flightNumber flightNumber);
    Ticket& setBaggage(Baggage baggage);

private:
    flightNumber flightnumber;
    unsigned int passengerID;
    float price;
    Baggage basementBaggage;
    ClassType tClass;
};

inline bool operator==(const Ticket& l, const Ticket& r) {
    return l.getFlightNumber() == r.getFlightNumber() && l.getPassengerID() == r.getPassengerID();
}

inline bool operator<(const Ticket& t1, const Ticket& t2){
    if (t1.getFlightNumber() != t2.getFlightNumber())
        return t1.getFlightNumber() < t2.getFlightNumber();
    return t1.getPassengerID() < t2.getPassengerID();
}

inline std::ostream& operator <<(std::ostream & os, const Ticket& l) {

    os << l.getFlightNumber() << " ";

    os << l.getPassengerID() << " " << l.getTClass()
    << " " << std::fixed << std::setprecision(2) << l.getPrice() << " " << l.getBaggage();

    os << endl;

    return os;

}

inline std::istream& operator >>(std::istream& is, Ticket& l) {

    flightNumber flightNumber1;
    unsigned int pId;
    float price;
    int cType;
    Baggage baggage;

    is >> flightNumber1 >> pId >> cType >> price>> baggage;

    l.setPrice(price).setFlightNumber(flightNumber1).setPassengerId(pId).setTclass((char)cType).setBaggage(baggage);

    return is;
}

#endif //TICKET_H

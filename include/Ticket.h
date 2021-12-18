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
    //Ticket(Flight& flight, const char seat[SEAT_MAP_DIMENSION], char boardingZone, char tClass, float price);
    // getters

    Ticket(Flight& flight);
    Ticket(flightNumber flightnumber, int passengerID, float price, Baggage bag1, char tClass);

    Flight getFlightInfo() const;
    int getPassengerID() const;
    ClassType getTClass() const;
    float getPrice() const;
    //Baggage getBaggage() const;
    flightNumber getFlightNUmber() const;
    bool getBaggage() const;

    Ticket& setPrice(float price);
    //Ticket& setBaggage(Baggage bag1);
    Ticket& setTclass(char tClass);
    Ticket& setPassengerId(int passengerid);
    Ticket& setFlightNumber(flightNumber flightNumber);
    Ticket& setBaggage(bool baggage);

    bool validBuy(Ticket ticket);

    //char getBoardingZone() const;
    //std::string getSeat() const;


private:
    flightNumber flightnumber;
    Flight flightInfo;
    int passengerID;
    float price;
    bool baggage;
    //Baggage bag1;
    ClassType tClass;
    //int remainingTickets;
    //'X'= exclusiva e 'E'= económica
    //string seat --- eventually, a seat number (ex:A3 or B1)
    //char boardingZone;

};

inline bool operator==(const Ticket& l, const Ticket& r) {
    return l.getFlightInfo() == r.getFlightInfo() && l.getPassengerID() == r.getPassengerID();
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

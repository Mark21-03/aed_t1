#ifndef BAGGAGE_H
#define BAGGAGE_H

#include <queue>
#include <Passenger> //classe PASSAGEIRO q falta criar

class Baggage{
private:
    Passenger passenger;
public:
    Baggage();
    Baggage(Passenger passenger);

    Passenger getPassengerBaggage();

    void setPassengerABaggage();
};

#endif //BAGGAGE_H

#ifndef BAGGAGE_H
#define BAGGAGE_H

#include <queue>
#include "../include/Passenger.h"


class Baggage{
private:
    Passenger passenger;
public:
    Baggage() = default;
    Baggage(Passenger passenger);

    Passenger getPassengerBaggage();


    void setPassengersBaggage(Passenger passenger);
};

#endif //BAGGAGE_H

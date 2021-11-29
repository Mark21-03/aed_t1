//
// Created by ricar on 29/11/2021.
//

#ifndef PASSENGER_H
#define PASSENGER_H

#include "Flight.h"

#include <list>
#include <string>

#define LONGEST_ACCEPTED_NAME 1000
// INFO: the longest name in the world as 950 chars

class Passenger {
public:
    Passenger(unsigned int ssn,const std::string& name){
        int i = 0;
        for (auto c: name) {
            this->name[i++] = c;
        }
        this->name[i] = '\0';
        ID = ssn;
    };

    //getters

    std::string getName();

    //setters

private:
    unsigned int ID;
    char name[LONGEST_ACCEPTED_NAME]{};

    std::list<Flight> pastFlights; // it is useful to keep track of flights ---> WE COULD EVEN DO A MILEAGE CAMPAIGN
    std::list<Flight> nextFlights; // it is useful to keep track of flights ---> WE COULD EVEN DO A MILEAGE CAMPAIGN

};


#endif //PASSENGER_H

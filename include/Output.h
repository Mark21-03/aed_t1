//
// Created by ricar on 14/12/2021.
//

#ifndef AED_T1_OUTPUT_H
#define AED_T1_OUTPUT_H
#include "vector"
#include "../include/Flight.h"
#include "../include/Passenger.h"
#include "Plane.h"

namespace out {
    #define SEPARATION "--------------------------------------------------------"

    void headerFlights(ostream &ostream1);
    void flights(ostream &ostream1, std::vector<Flight>::iterator it);


    inline void askID(ostream &ostream1, istream & istream1, int & min , int& max) {
        ostream1 << "FlightID from x to y: " << std::endl;
        ostream1 << "x: ";  istream1 >> min;
        ostream1 << "\ny: "; istream1 >> max; // TODO: CHECK ERRORS
    }
    inline void askID(ostream &ostream1, istream & istream1, unsigned int & min , unsigned int& max) {
        ostream1 << "FlightID from x to y: " << std::endl;
        ostream1 << "x: ";  istream1 >> min;
        ostream1 << "\ny: "; istream1 >> max; // TODO: CHECK ERRORS
    }


    void headerPassengers(ostream& ostream1);
    void passenger(ostream& ostream1, std::vector<Passenger>::iterator it);

    void headerPlanes(ostream& ostream1);
    void planes(ostream& ostream1, std::vector<Plane>::iterator it);


}


#endif //AED_T1_OUTPUT_H

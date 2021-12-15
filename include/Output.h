//
// Created by ricar on 14/12/2021.
//

#ifndef AED_T1_OUTPUT_H
#define AED_T1_OUTPUT_H
#include "vector"
#include "../include/Flight.h"
#include "../include/Passenger.h"
#include "Plane.h"
#include "Service.h"


namespace out {
    #define SEPARATION "--------------------------------------------------------"

    void headerFlights(ostream &ostream1);
    template<typename FlightsPointer>
    inline void flights(ostream &ostream1, FlightsPointer it) {
        ostream1 << setw(15) << it->getNumber() << setw(15) << it->getDepartureDate().getDate() << setw(15)
                 << it->getDepartureTime().getTime()
                 << setw(50) << it->getOrigin() << setw(45) << " ⟶ " + it->getDestiny() << "\n";
    }

    template<typename writeable>
    inline void askInterval(ostream &ostream1, istream & istream1, writeable & min , writeable & max, const std::string& asked) {
        ostream1 << asked << " from x to y: " << std::endl;
        ostream1 << "x: ";  istream1 >> min;
        ostream1 << "\ny: "; istream1 >> max; // TODO: CHECK ERRORS
    }

    template<typename writeable>
    inline void askOnce(ostream &ostream1, istream & istream1, writeable & min, const std::string& asked) {
        ostream1 << "Provide a valid " << asked << std::endl;
        ostream1 << asked << ": ";  istream1 >> min;
    }

    void headerPassengers(ostream& ostream1);
    template<typename PassengerPointer>
    inline void passenger(ostream& ostream1, PassengerPointer it) {
        ostream1 << SEPARATION << std::endl;
        ostream1 << it->getID()<<"\t"<<it->getName()<< '\n';
    }

    void headerPlanes(ostream& ostream1);
    template<typename PlanePointer>
    inline void planes(ostream& ostream1, PlanePointer it) {
        ostream1 << it->getNumberPlate() << '\t' << it->getType() << '\t' << it->getCapacity() << "\t\t"<<it->getFlightPlan().size()<<'\n';
    }

    void headerServices(ostream& ostream1);
    template<typename ServicePointer>
    inline void services(ostream& ostream1, ServicePointer it){
        ostream1 << it->getInfo() << std::endl;
    }
}

#endif //AED_T1_OUTPUT_H

//
// Created by ricar on 14/12/2021.
//

#include "../include/Output.h"

namespace out {

    void headerFlights(ostream &ostream1) {
        ostream1 << right;
        ostream1 << setfill(' ') << "Number\t\t" << setw(15) << "Departure Date " << setw(15) << "Departure Time"
                 << setw(30) << "Origin " << setw(40) << "Destiny" << "\n";
        ostream1 << SEPARATION << SEPARATION << SEPARATION << "\n" << left
                 << setfill(' '); // MAYBE PUT THIS STUFF in a Macro
    }

    void flights(ostream &ostream1, std::vector<Flight>::iterator it) {
        ostream1 << setw(15) << it->getNumber() << setw(15) << it->getDepartureDate().getDate() << setw(15)
                 << it->getDepartureTime().getTime()
                 << setw(50) << it->getOrigin() << setw(45) << " ⟶ " + it->getDestiny() << "\n";
    }

    void headerPassengers(ostream& ostream1) {
        ostream1<<"ID\t"<<"Name"<<endl;
    }

    void passenger(ostream& ostream1, std::vector<Passenger>::iterator it) {
        ostream1 << SEPARATION << std::endl;
        ostream1 << it->getID()<<"\t"<<it->getName()<< '\n';
    }


    void headerPlanes(ostream &ostream1) {
        ostream1 << "Plate\t" << "Type\t" << "Capacity\t" << "Number of Flights\r" << '\n';
        ostream1 << SEPARATION << std::endl;
    }

    void planes(ostream& ostream1, std::vector<Plane>::iterator it) {
        ostream1 << it->getNumberPlate() << '\t' << it->getType() << '\t' << it->getCapacity() << "\t\t"<<it->getFlightPlan().size()<<'\n';
    }
}
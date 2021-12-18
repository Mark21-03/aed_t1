#include "../include/Output.h"

namespace out {

    void headerFlights(ostream &ostream1) {
        ostream1 << right;
        ostream1 << setfill(' ') << "Number\t\t" << setw(15) << "Departure Date " << setw(15) << "Departure Time"
                 << setw(15)<< "Occupation"
                 << setw(30) << "Origin " << setw(40) << "Destiny" << "\n";
        ostream1 << SEPARATION << SEPARATION << SEPARATION << "\n" << left
                 << setfill(' ');
    }

    void headerPassengers(ostream& ostream1) {
        ostream1<<"ID\t"<<"Name"<<endl;
    }


    void headerPlanes(ostream &ostream1) {
        ostream1 << "Plate\t" << "Type\t" << "Capacity\t" << "Number of Flights\r" << '\n';
        ostream1 << SEPARATION << std::endl;
    }

    void headerServices(ostream& ostream1) {
        ostream1 << "Type\t" << "Date\t" << "Employer\t" << "Plane Plate\r" << '\n';
        ostream1 << SEPARATION << std::endl;
    }

    void headerTransports(ostream& ostream1) {
        ostream1<<"Type\t\t"<<"Distance\t\t\t"<<"Schedule"<<endl;
        ostream1<<SEPARATION<<SEPARATION<<SEPARATION<<endl;
    }

}
#include "../include/Output.h"

namespace out {

    void headerFlights(ostream &ostream1) {
        ostream1 << right;
        ostream1 << setfill(' ') << "Number\t" << setw(15) << "   Departure Date " << setw(15) << "  Departure Time"
                 << setw(12) << "Occup." << setw(15) << "  Max Cap."
                 << setw(35) << "Origin" << setw(40) << "Destiny" << "\n";
        ostream1 << SEPARATION << SEPARATION << SEPARATION << "-------------\n" << left
                 << setfill(' ');
    }

    void headerPassengers(ostream &ostream1) {
        ostream1 << right << setfill(' ') << "ID  " << setw(15) << "Name" << setw(45) << "\t\tBirth Date" << endl;
        ostream1 << SEPARATION << "------------------------------------" << std::endl;
    }


    void headerPlanes(ostream &ostream1) {
        ostream1 << "Plate\t" << "Type\t" << "Capacity\t" << "Number of Flights\r" << '\n';
        ostream1 << SEPARATION << std::endl;
    }

    void headerServices(ostream &ostream1) {
        ostream1 << "Type\t" << "Date\t  " << "  Plane Plate\t" << "  Employee\r" << '\n';
        ostream1 << SEPARATION << "------------" << std::endl;
    }

    void headerTransports(ostream &ostream1) {
        ostream1 << "Type\t " << "  Distance\t\t\t" << "Schedule" << endl;
        ostream1 << SEPARATION << SEPARATION << "---------------------" << endl;
    }

}
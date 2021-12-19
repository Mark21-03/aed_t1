#ifndef AED_T1_OUTPUT_H
#define AED_T1_OUTPUT_H

#include <regex>
#include "vector"
#include "../include/Flight.h"
#include "../include/Passenger.h"
#include "Plane.h"
#include "Service.h"


namespace out {
    #define SEPARATION "--------------------------------------------------------"

    /**
     * Outputs flights table (header)
     * @param ostream1 ostream where to output the table
     */
    void headerFlights(ostream &ostream1);

    /**
     * Outputs flights table
     * @tparam FlightsPointer pointer to a flight object
     * @param ostream1  ostream where to output the table
     * @param it flight pointer to be outputted
     */
    template<typename FlightsPointer>
    inline void flights(ostream &ostream1, FlightsPointer it) {
        ostream1 << setw(15) << it->getNumber() << setw(15) << it->getDepartureDate().getDate() << setw(15)
                 << it->getDepartureTime().getTime() << setw(20) << it->getOccupation()
                 << setw(50) << it->getOrigin() << setw(45) << " ⟶ " + it->getDestiny() << "\n";
    }

    /**
     *
     * @tparam writeable object that has overload <<
     * @param ostream1 ostream to ask the user
     * @param istream1 istream to get the user's input
     * @param min minimum of the desired interval
     * @param max maximum of the desired interval
     * @param asked the kind of value being asked
     */
    template<typename writeable>
    inline void askInterval(ostream &ostream1, istream & istream1, writeable & min , writeable & max, const std::string& asked) {
        ostream1 << asked << " from x to y: " << std::endl;
        ostream1 << "x: ";  istream1 >> min;
        ostream1 << "\ny: "; istream1 >> max;
    }

    inline regex askParts(std::ostream &ostream1, istream & istream1, const std::string& askText) {
        std::string searchName;
        ostream1 << askText;
        istream1.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(istream1, searchName);
        regex search(".*" + searchName + ".*");
        ostream1 << endl;

        return search;
    }

    //TODO Acabar documentação
    template<typename writeable>
    inline void askOnce(ostream &ostream1, istream & istream1, writeable & min, const std::string& asked) {
        ostream1 << "Provide a valid " << asked << std::endl;
        ostream1 << asked << ": ";  istream1 >> min;
    }

    void headerPassengers(ostream& ostream1);
    template<typename PassengerPointer>
    inline void passenger(ostream& ostream1, PassengerPointer it) {
        ostream1 << SEPARATION << std::endl;
        ostream1 << it->getID()<<"\t"<<it->getName()<<"\t\t\t"<<it->getBirthDate()<< '\n';
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

    void headerTransports(ostream& ostream1);
    template<typename TransportPointer>
    inline void transports(ostream& ostream1, TransportPointer it){
        using namespace std;

        auto nameSetter = [](char c){
            if(c == 'S') return "Subway";
            else if(c == 'T') return "Train";
            else return "Bus";
        };
        ostream1<< left << setw(10) <<setfill(' ') << setw(10) <<nameSetter(it->getType())<< setw(10)
        << to_string(it->getDistance()) + " km\t " <<it->getTimeTable()<<endl;
    }


}

#endif //AED_T1_OUTPUT_H

#ifndef AED_T1_OUTPUT_H
#define AED_T1_OUTPUT_H

#include <regex>
#include "vector"
#include "../include/Flight.h"
#include "../include/Passenger.h"
#include "Plane.h"
#include "Service.h"
#include<cstdlib>

namespace out {
    #define SEPARATION "--------------------------------------------------------"

    /// ANSI CODES
    enum Code {
        FG_BLACK    = 30, /**< ForeGround Black Color  */
        FG_RED      , /**< ForeGround Red Color */
        FG_GREEN    , /**< ForeGround Green Color */
        FG_YELLOW   , /**< ForeGround Yellow Color */
        FG_BLUE     , /**< ForeGround Blue Color */
        FG_MAGENTA  , /**< ForeGround Magenta Color */
        FG_CYAN     , /**< ForeGround Cyan Color */
        FG_WHITE    , /**< ForeGround White Color */
        FG_DEFAULT  = 39, /**< ForeGround default Color */
        BG_BLACK    = 40, /**< BlackGround Black Color */
        BG_RED      , /**< BlackGround Red Color */
        BG_GREEN    , /**< BlackGround Green Color */
        BG_YELLOW   , /**< BlackGround Yellow Color */
        BG_BLUE     , /**< BlackGround Blue Color */
        BG_MAGENTA  , /**< BlackGround Magenta Color */
        BG_CYAN     , /**< BlackGround Cyan Color */
        BG_WHITE    , /**< BlackGround White Color */
        BG_DEFAULT  = 49 /**< BlackGround Default Color */
    };

    /**
     * A class that functions as a bridge to fastly use Ansi Codes
     * The class receives a Ansi Code defined in the enum Code and overloads the out operator
     * so that it can perform the code with an ease and rapidly change between colors, text types, etc..
     */
    class Modifier {
        Code code;
    public:
        /**
         * Modifier Constructor
         *it creates a instance of the class that performs the change indicated by Code
         */
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        /**
         * activates the Code in the ostream provided
         */
        operator<<(std::ostream& os, const Modifier& mod) {
            #ifdef _WIN32
            system("color");
            #endif
            return os << "\x1b[" << mod.code << "m";
        }
    };

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
                 << it->getDepartureTime().getTime() << setw(20) << it->getOccupation() << setw(20) << it->getMaxCapacity()
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
        ostream1 <<std::endl<< asked << " from x to y: " << std::endl;
        ostream1 << "x: ";  istream1 >> min;
        ostream1 << "y: "; istream1 >> max;
        ostream1<<std::endl;
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
        //ostream1 << "Provide a valid " << asked << std::endl;
        ostream1 <<std::endl<< asked << ": ";  istream1 >> min;
    }

    void headerPassengers(ostream& ostream1);
    template<typename PassengerPointer>
    inline void passenger(ostream& ostream1, PassengerPointer it) {
        ostream1 << SEPARATION << SEPARATION << std::endl;
        ostream1  <<left << setfill(' ') << setw(15) << it->getID()<< setw(45)<<it->getName() << setw(15) <<it->getBirthDate().getDate()<< '\n';
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
        ostream1<<left << setw(10) <<setfill(' ') << setw(10) <<nameSetter(it->getType())<< setw(15)
        <<to_string(it->getDistance()) + " km\t  " <<it->getTimeTable()<<endl;
    }
}

#endif //AED_T1_OUTPUT_H

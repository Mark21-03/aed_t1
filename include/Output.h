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
    /**
     * An Enum of Ansi Codes.
     */
    enum Code {
        RESET = 0,/**< All attributes off*/
        BOLD ,/**< Bold text off*/
        FAINT,/**< light font weight*/
        ITALIC,/**< Italic text*/
        UNDERLINE,/**< underlined text*/
        S_BLINK,/**< Slowly blink*/
        R_BLINK,/**< Rapid Blink*/
        FG_BLACK = 30, /**< ForeGround Black Color  */
        FG_RED, /**< ForeGround Red Color */
        FG_GREEN, /**< ForeGround Green Color */
        FG_YELLOW, /**< ForeGround Yellow Color */
        FG_BLUE, /**< ForeGround Blue Color */
        FG_MAGENTA, /**< ForeGround Magenta Color */
        FG_CYAN, /**< ForeGround Cyan Color */
        FG_WHITE, /**< ForeGround White Color */
        FG_DEFAULT = 39, /**< ForeGround default Color */
        BG_BLACK = 40, /**< BlackGround Black Color */
        BG_RED, /**< BlackGround Red Color */
        BG_GREEN, /**< BlackGround Green Color */
        BG_YELLOW, /**< BlackGround Yellow Color */
        BG_BLUE, /**< BlackGround Blue Color */
        BG_MAGENTA, /**< BlackGround Magenta Color */
        BG_CYAN, /**< BlackGround Cyan Color */
        BG_WHITE, /**< BlackGround White Color */
        BG_DEFAULT = 49, /**< BlackGround Default Color */
        BG_BRIGHT_BLACK = 100
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
        explicit Modifier(Code pCode) : code(pCode) {}

        friend std::ostream &
        /**
         * activates the Code in the ostream provided
         */
        operator<<(std::ostream &os, const Modifier &mod) {
#ifdef _WIN32
            system("color");
#endif
            return os << "\x1b[" << mod.code << "m";
        }
    };


    /**
     * Prints a table header for flights objet data into a given ostream
     * @param ostream1 ostream where to print table header
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
        ostream1 << setw(15) << it->getNumber() << setw(15) << it->getDepartureDate().getDate() << setw(20)
                 << it->getDepartureTime().getTime() << setw(15) << it->getOccupation() << setw(20)
                 << it->getMaxCapacity()
                 << setw(50) << it->getOrigin() << "\t-> " << setw(45) << it->getDestiny() << "\n";
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
    inline void
    askInterval(ostream &ostream1, istream &istream1, writeable &min, writeable &max, const std::string &asked) {
        ostream1 << std::endl << asked << " from x to y: " << std::endl;
        ostream1 << "x: ";
        istream1 >> min;
        ostream1 << "y: ";
        istream1 >> max;
        ostream1 << std::endl;
    }

    /**
     * Asks user using given ostream and string to be outputted for a regex
     * to be inputted into a given istream
     * @param ostream1 ostream to print the asking message
     * @param istream1 istream to receive the user's regex
     * @param askText string message with the text asking message
     * @return regex provided by user
     */
    inline regex askParts(std::ostream &ostream1, istream &istream1, const std::string &askText) {
        std::string searchName;
        ostream1 << askText;
        istream1.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(istream1, searchName);
        regex search(searchName);
        ostream1 << endl;

        return search;
    }

    /**
     * Asks user a question using a given istream and ostream and saving the
     * answer into a given template writable variable passed by reference
     * @tparam writeable any kind of value that can use operator >>
     * @param ostream1 ostream used to ask user for input
     * @param istream1 istream to receive user's input
     * @param min value inputted by the user to be stored
     * @param asked string text message to be asked in the ostream
     */
    template<typename writeable>
    inline void askOnce(ostream &ostream1, istream &istream1, writeable &min, const std::string &asked) {
        ostream1 << std::endl << asked << ": ";
        istream1 >> min;
    }

    /**
     * Prints a table header for passenger objet data into a given ostream
     * @param ostream1 ostream where to print table header
     */
    void headerPassengers(ostream &ostream1);


    /**
     * Prints passenger object information in a single line
     * @tparam PassengerPointer reference to a passenger object
     * @param ostream1 ostream to be used for output
     * @param it passenger to be outputted
     */
    template<typename PassengerPointer>
    inline void passenger(ostream &ostream1, PassengerPointer it) {
        ostream1 << left << setfill(' ') << setw(15) << it->getID() << setw(45) << it->getName() << "\t"
                 << it->getBirthDate().getDate() << '\n';
    }

    /**
     * Prints a table header for planes objet data into a given ostream
     * @param ostream1 ostream where to print table header
     */
    void headerPlanes(ostream &ostream1);

    /**
     * Prints plane object information in a single line
     * @tparam PlanePointer reference to a plane object
     * @param ostream1 ostream to output plane
     * @param it plane to be outputted
     */
    template<typename PlanePointer>
    inline void planes(ostream &ostream1, PlanePointer it) {
        ostream1 << it->getNumberPlate() << '\t' << it->getType() << '\t' << it->getCapacity() << "\t\t"
                 << it->getFlightPlan().size() << '\n';
    }

    /**
     * Prints a table header for services objet data into a given ostream
     * @param ostream1 ostream where to print table header
     */
    void headerServices(ostream &ostream1);

    /**
     * Prints service object information in a single line
     * @tparam ServicePointer reference to a service object
     * @param ostream1 ostream to output service
     * @param it service to be outputted
     */
    template<typename ServicePointer>
    inline void services(ostream &ostream1, ServicePointer it) {
        ostream1 << it->getInfo() << std::endl;
    }

    /**
     * Prints a table header for transporst objet data into a given ostream
     * @param ostream1 ostream where to print table header
     */
    void headerTransports(ostream &ostream1);

    /**
     * Prints transport object information in a single line
     * @tparam TransportPointer reference to a transport object
     * @param ostream1  ostream to output transport
     * @param it  transport to be outputted
     */
    template<typename TransportPointer>
    inline void transports(ostream &ostream1, TransportPointer it) {
        using namespace std;

        auto roundDist = [](float f) {
            f = f * 100.0;
            f += 0.5;
            int n = (int) f;
            return (float) n / 100.0;

        };

        auto nameSetter = [](char c) {
            if (c == 'S') return "Subway";
            else if (c == 'T') return "Train";
            else return "Bus";
        };
        ostream1 << left << setw(10) << setfill(' ') << setw(10) << nameSetter(it->getType()) << " "
                 << (roundDist(it->getDistance())) << " km\t  " << it->getTimeTable() << endl;
    }
}

#endif //AED_T1_OUTPUT_H

#ifndef PASSENGER_H
#define PASSENGER_H

#include "Flight.h"
#include "../Exceptions/NameToLongException.h"
#include "Ticket.h"
#include "Baggage.h"

#include <list>
#include <string>
#include <queue>
#include <numeric>

#define LONGEST_ACCEPTED_NAME 60


class Passenger {
private:
    unsigned int ID;
    Date birthDate;
    char name[LONGEST_ACCEPTED_NAME]{};

public:
    friend class ComparePassengersByName;

    friend class ComparePassengersByBirthDate;

    /**
     * Default constructor of Passenger
     */
    Passenger() = default;

    /**
     * Constructs a Passenger object with ID and name
     * @param ID Passenger's ID
     * @param name Name of the Passenger
     */
    Passenger(unsigned int ID, const std::string &name) {
        setName(name);
        this->ID = ID;
        this->birthDate = Date(1970, 1, 1);
    };

    /**
     * Constructs a Passenger object with ID, name and Birth Date
     * @param ID Passenger's ID
     * @param name Name of the Passenger
     * @param BirthDate Birth Date of the Passenger
     */
    Passenger(unsigned int ID, const std::string &name, const Date &BirthDate) {
        setName(name);
        this->ID = ID;
        this->birthDate = BirthDate;
    };

    /**
     * Gives the name of the Passenger
     * @return Passenger's name
     */
    std::string getName() const;

    char *getNameC() {
        return name;
    }

    /**
     * Gives the ID of the Passenger
     * @return Passenger's ID
     */
    unsigned int getID() const;

    /**
     * Gives the Birth Date of the Passenger
     * @return Passenger's Birth Date
     */
    Date getBirthDate() const { return this->birthDate; };


    /**
     * Sets the name of the Passenger
     * @param newName value to be set
     * @return pointer to Passenger
     */
    Passenger &setName(const std::string &newName);

    /**
     * Sets the ID of the Passenger
     * @param newID value to be set
     * @return pointer to Passenger
     */
    Passenger &setID(unsigned int newID);

    /**
     * Sets the Birth Date of the Passenger
     * @param newDate value to be set
     */
    inline void setBirth(const Date &newDate) { this->birthDate = newDate; }


};

/**
 * Ostream overload for Passenger Class, outputting a passenger in the format:
 * ID name BirthDate
 * @param os ostream to be used
 * @param l Passenger Object to be outputted
 * @return ostream used (altered)
 */
inline std::ostream &operator<<(std::ostream &os, Passenger &l) {

    os << l.getID();

    bool ended = false;
    for (int i = 0; i < LONGEST_ACCEPTED_NAME; ++i) {
        if (ended) {
            os << '\0';
            continue;
        }
        char c = l.getNameC()[i];
        os << c;
        if (c == '\0')
            ended = true;

    }

    os << " " << l.getBirthDate();
    os << "\n";

    return os;
}

/**
 * Istream overload for Passenger Class, allowing an input to
 * be converted to given Passenger object
 * @param is istream that provides the values
 * @param l Passenger object that receives the values
 * @return istream used (altered)
 */
inline std::istream &operator>>(std::istream &is, Passenger &l) {
    unsigned int temp_ID;
    is >> temp_ID;
    l.setID(temp_ID);

    for (int i = 0; i < LONGEST_ACCEPTED_NAME; ++i) {
        l.getNameC()[i] = is.get();
    }


    Date birth;
    is >> birth;
    l.setBirth(birth);


    return is;
}

/**
 * Compares if the left Passenger is minor than the right one
 * @param l1 Passenger to be compared
 * @param l2 Passenger to be compared
 * @return comparison result boolean
 */
inline bool operator<(const Passenger &l1, const Passenger &l2) {
    return l1.getID() < l2.getID();
}

/**
 * Compares if two Passengers are the same
 * @param l1 Passenger to be compared
 * @param l2 Passenger to be compared
 * @return comparison result boolean
 */
inline bool operator==(const Passenger &l1, const Passenger &l2) {
    return l1.getID() == l2.getID();
}

/**
 * Compares if two Passengers are different
 * @param l1 Passenger to be compared
 * @param l2 Passenger to be compared
 * @return comparison result boolean
 */
inline bool operator!=(const Passenger &l1, const Passenger &l2) {
    return l1.getID() != l2.getID();
}


class ComparePassengersByName {
public:
    /**
     * Compares two Passengers using their Name
     * @param l Passenger to be compared
     * @param r Passenger to be compared
     * @return comparison result boolean
     */
    bool operator()(Passenger *l, Passenger *r) {
        return l->getName() < r->getName();
    }
};

class ComparePassengersByBirthDate {
public:
    /**
     * Compares two Passengers using their Birth Date
     * @param l Passenger to be compared
     * @param r Passenger to be compared
     * @return comparison result boolean
     */
    bool operator()(Passenger *l, Passenger *r) {
        return l->birthDate.isBefore(r->birthDate);
    }
};


#endif //PASSENGER_H

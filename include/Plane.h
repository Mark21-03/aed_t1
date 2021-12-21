#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <list>
#include <vector>
#include "Flight.h"


typedef std::string planePlate;

/**
 * A class that represents a company airplane.
 */
class Plane {
private:
    /**
     * The number plate of the airplane.
     */
    planePlate numberPlate;
    /**
     * The type of the airplane.
     */
    std::string pType;
    /**
     * the max. capacity of the airplane
     */
    int capacity;
    /**
     * The list of flights this plane is responsible for.
     */
    std::list<flightNumber> flightPlan;
public:
    friend class ComparePlaneByType;

    friend class ComparePlaneByCapacity;

    friend class ComparePlaneByNumberOfFlights;

    /**
     * Default constructor of Plane
     */
    Plane() = default;

    /**
     * Constructs a Plane object with Plate number, Plane type and capacity
     * @param numberPlate Plane's plate number
     * @param pType Plane's type
     * @param capacity Plane's capacity
     */
    Plane(const planePlate &numberPlate, const std::string &pType, int capacity);

    /**
     * Constructs a Plane object with Plate number, Plane type, capacity and a flight plan
     * @param numberPlate Plane's plate number
     * @param pType Plane's type
     * @param capacity Plane's capacity
     * @param flightPlan Plane's flight plan (with the flihgt's number)
     */
    Plane(const planePlate &numberPlate, const std::string &pType, int capacity,
          const std::list<flightNumber> &flightPlan);

    /**
     * Sets the plate number of the Plane
     * @param newNumberPlate value to be set
     * @return pointer to Plane
     */
    Plane &setNumberPlate(const planePlate &newNumberPlate);

    /**
     * Sets the type of the Plane
     * @param newPlaneType value to be set
     * @return pointer to plane
     */
    Plane &setType(const std::string &newPlaneType);

    /**
     * Sets the capacity of the Plane
     * @param newCapacity value to be set
     * @return pointer to Plane
     */
    Plane &setCapacity(int newCapacity);

    /**
     * Sets the flight plane of the Plane
     * @param newFlightPlan value to be set
     * @return pointe to Plane
     */
    Plane &setFlightPlan(const std::list<flightNumber> &newFlightPlan);

    /**
     * Gives the plate's number of the Plane
     * @return Plane's plate number
     */
    planePlate getNumberPlate() const;

    /**
     * Gives the type of the Plane
     * @return Plane's type
     */
    std::string getType() const;

    /**
     * Gives the capacity of the Plane
     * @return Plane's capacity
     */
    int getCapacity() const;

    /**
     * Gives the flight plan of the Plane
     * @return Plane's flight plan
     */
    std::list<flightNumber> getFlightPlan() const;

    friend inline std::ostream &operator<<(std::ostream &os, Plane &p);
};

/**
     * Ostream overload for Plane Class, outputting a Plane in the format:
     * plate_number type capacity flight_plan
     * @param os ostream to be used
     * @param p Plane Object to be outputted
     * @return ostream used (altered)
     */
inline std::ostream &operator<<(std::ostream &os, Plane &p) {
    os << p.getNumberPlate() << " " << p.getType() << " " << p.getCapacity() << " ";

    os << p.flightPlan.size() << " ";
    for (auto f: p.flightPlan) {
        os << f << " ";
    }

    os << '\n';
    return os;
}

/**
 * Istream overload for Plane Class, allowing an input to
 * be converted to given Plane object
 * @param is istream that provides the values
 * @param p Plane object that receives the values
 * @return istream used (altered)
 */
inline std::istream &operator>>(std::istream &is, Plane &p) {

    std::string pType;
    std::string nPlate;
    int c;

    is >> nPlate;
    is >> pType;
    is >> c;

    p.setNumberPlate(nPlate).setType(pType).setCapacity(c);
    int n;
    is >> n;
    std::list<flightNumber> fp;
    for (int i = 0; i < n; i++) {
        int k;
        is >> k;
        fp.push_back(k);
    }

    p.setFlightPlan(fp);

    return is;
}

/**
 * Compares if the left Plane is minor than the right one
 * @param p1 Plane to be compared
 * @param p2 Plane to be compared
 * @return comparison result boolean
 */
inline bool operator<(const Plane &p1, const Plane &p2) {
    return p1.getNumberPlate() < p2.getNumberPlate();
}

/**
 * Compares if two Planes are the same
 * @param p1 Plane to be compared
 * @param p2 Plane to be compared
 * @return comparison result boolean
 */
inline bool operator==(const Plane &p1, const Plane &p2) {
    return p1.getNumberPlate() == p2.getNumberPlate();
}

/**
 * Compares if two Planes are different
 * @param p1 Plane to be compared
 * @param p2 Plane to be compared
 * @return comparison result boolean
 */
inline bool operator!=(const Plane &p1, const Plane &p2) {
    return p1.getNumberPlate() != p2.getNumberPlate();
}

class ComparePlaneByType {
public:
    /**
     * Compares two Planes using their type
     * @param l Plane to be compared
     * @param r Plane to be compared
     * @return comparison result boolean
     */
    bool operator()(Plane *l, Plane *r) {
        return l->pType < r->pType;
    }
};

class ComparePlaneByCapacity {
public:
    /**
     * Compares two Planes using their capacity
     * @param l Plane to be compared
     * @param r Plane to be compared
     * @return comparison result boolean
     */
    bool operator()(Plane *l, Plane *r) {
        return l->capacity < r->capacity;
    }
};

class ComparePlaneByNumberOfFlights {
public:
    /**
     * Compares two Planes using the number of flights
     * in the flight plane of each one
     * @param l Plane to be compared
     * @param r Plane to be compared
     * @return comparison result boolean
     */
    bool operator()(Plane *l, Plane *r) {
        return l->flightPlan.size() < r->flightPlan.size();
    }
};


#endif //PLANE_H
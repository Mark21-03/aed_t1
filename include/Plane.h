#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <list>
#include <vector>
#include "Flight.h"

// a PLANE FILE COULD HAVE THIS INTERESTING DESIGN
//     3 2
//  OOOO FFF
//  FOFO OOO
//  FOOO FFO
//
// In which the O -> occupied seat and F -> Free seat. the struct of the plane should be defined either before or it can
// either be not defined and we arrange in that way the plane as we want (using getlines)

typedef std::string planePlate;

class Plane{
private:
    planePlate numberPlate;
    std::string pType;
    int capacity;
    std::list<flightNumber> flightPlan;
public:
    friend class ComparePlaneByType;

    Plane() = default ;
    Plane(const planePlate& numberPlate ,const std::string& pType, int capacity);
    Plane(const planePlate& numberPlate ,const std::string& pType, int capacity,const std::list<flightNumber>& flightPlan);

    Plane& setNumberPlate(const planePlate& numberPlate);
    Plane& setType(const std::string& pType);
    Plane& setCapacity(int capacity);
    Plane& setFlightPlan(const std::list<flightNumber>& flightPlan);

    planePlate getNumberPlate() const;
    std::string getType() const;
    int getCapacity() const;
    std::list<flightNumber> getFlightPlan() const; // const std::list<Flight>&

    friend inline std::ostream & operator<<(std::ostream& os, Plane& p);
};

inline std::ostream & operator<<(std::ostream& os, Plane& p) {
    os << p.getNumberPlate() << " " << p.getType() << " " << p.getCapacity() << " ";

    os << p.flightPlan.size() << " ";
    for (auto f: p.flightPlan) {
        os << f << " ";
    }

    os << '\n';
    return os;
}

inline std::istream & operator>>(std::istream& is, Plane& p) {

    std::string pType ; // only a string always
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

inline bool operator<(const Plane &p1, const Plane &p2){
    return p1.getNumberPlate() < p2.getNumberPlate();
}

inline bool operator==(const Plane &p1, const Plane &p2){ // IS THIS NEEDED
    return p1.getNumberPlate() == p2.getNumberPlate();
}

inline bool operator!=(const Plane &p1, const Plane &p2){
    return p1.getNumberPlate() != p2.getNumberPlate();
}

class ComparePlaneByType {
public:
    bool operator()(const Plane& l , const Plane & r) {
        return l.pType < r.pType;
    }
};

#endif //PLANE_H
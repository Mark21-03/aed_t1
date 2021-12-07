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

class Plane{
private:
    std::string numberPlate;
    std::string pType;
    int capacity;
    std::list<flightNumber> flightPlan;
public:

    Plane() = default ;
    Plane(const std::string& numberPlate ,const std::string& pType, int capacity);
    Plane(const std::string& numberPlate ,const std::string& pType, int capacity,const std::list<flightNumber>& flightPlan);

    Plane& setNumberPlate(const std::string& numberPlate);
    Plane& setType(const std::string& pType);
    Plane& setCapacity(int capacity);
    Plane& setFlightPlan(const std::list<flightNumber>& flightPlan);

    std::string getNumberPlate() const;
    std::string getType() const;
    int getCapacity() const;
    std::list<int> getFlightPlan() const; // const std::list<Flight>&

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

    is >> nPlate; // TODO : an exception might be thrown if the plate is not valid
    is >> pType;
    is >> c;

    p.setNumberPlate(nPlate).setType(pType).setCapacity(c);
    int n;
    is >> n;
    std::list<int> fp;
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


#endif //PLANE_H
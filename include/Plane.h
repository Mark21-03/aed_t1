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

struct flightNumber{int n;};

class Plane{
private:
    std::string numberPlate; //possivelmente trocar por char[4] ?
    int capacity;
    std::list<int> flightPlan;
public:

    Plane() = default ;
    Plane(std::string numberPlate, int capacity);
    Plane(std::string numberPlate, int capacity,std::list<int> flightPlan);

    void setNumberPlate(std::string numberPlate);
    void setCapacity(int capacity);
    void setFlightPlan(const std::list<int>& flightPlan);

    std::string getNumberPlate() const;
    int getCapacity() const;
    std::list<int> getFlightPlan() const; // const std::list<Flight>&

    friend inline std::ostream & operator<<(std::ostream& os, Plane& p);
};

inline std::ostream & operator<<(std::ostream& os, Plane& p) {
    os << p.getNumberPlate() << " " <<p.getCapacity() << " ";

    os << p.flightPlan.size() << " ";
    for (auto f: p.flightPlan) {
        os << f << " ";
    }

    os << '\n';
    return os;
}

inline std::istream & operator>>(std::istream& is, Plane& p) {

    string nPlate ; // only a string always
    is >> nPlate; p.setNumberPlate(nPlate);

    int c;
    is >> c;p.setCapacity(c);

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
    return p1.getNumberPlate()<p2.getNumberPlate();
}

inline bool operator==(const Plane &p1, const Plane &p2){
    return p1.getNumberPlate()==p2.getNumberPlate();
}

inline bool operator!=(const Plane &p1, const Plane &p2){
    return p1.getNumberPlate()!=p2.getNumberPlate();
}


#endif //PLANE_H
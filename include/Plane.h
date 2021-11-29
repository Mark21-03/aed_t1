#ifndef PLANE_H
#define PLANE_H

#include <iostream>
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
    int capacity;
    std::vector<Flight> flightPlan; // secalhar uma queue com sequencia de voos consoante o horario de partida

public:

    Plane(){};
    Plane(std::string numberPlate, int capacity);
    Plane(std::string numberPlate, int capacity,std::vector<Flight> flightPlan);

    void setNumberPlate(std::string numberPlate);
    void setCapacity(int capacity);
    void setFlightPlan(const std::vector<Flight>& flightPlan);

    std::string getNumberPlate() const;
    int getCapacity() const;
    std::vector<Flight> getFlightPlan() const;
};

#endif //PLANE_H
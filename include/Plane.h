#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <vector>
#include "Flight.h"

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
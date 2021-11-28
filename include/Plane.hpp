#pragma once

#include <iostream>
#include <vector>
#include "Flight.hpp"

using namespace std;

class Plane{
    private:
        string numberPlate;
        int capacity;
        vector<Flight> flightPlan;
    
    public:

    Plane(){};
    Plane(string numberPlate, int capacity);
    Plane(string numberPlate, int capacity,vector<Flight> flightPlan);

    void setNumberPlate(string numberPlate);
    void setCapacity(int capacity);
    void setflightPlan(const vector<Flight>& flightPlan);

    string getNumberPlate() const;
    int getCapacity() const;
    vector<Flight> getFlightPlan() const;
};
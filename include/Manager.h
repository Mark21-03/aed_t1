#ifndef AED_T1_MANAGER_H
#define AED_T1_MANAGER_H

#include <list>
#include "Plane.h"
#include "Passenger.h"
#include <vector>
#include <fstream>

class Manager {

    std::vector<Plane> planes;
    std::vector<Passenger> passengers; // higher frequency of insertion/deletions, but does it have so many ?

    std::vector<Flight> flights; // this probably does not have to be here (in planes we have this information)
public:

    Manager();

    bool addFlightToPlanePlan(Flight& flight); // success or not

    void showSortedPassengers();
    void showSortedFlights();


};


#endif //AED_T1_MANAGER_H

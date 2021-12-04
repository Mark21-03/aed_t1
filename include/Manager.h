#ifndef AED_T1_MANAGER_H
#define AED_T1_MANAGER_H

#include <list>
#include "Plane.h"
#include "Passenger.h"
#include <vector>
#include <ostream>
#include <fstream>

class Manager {

    std::vector<Plane> planes;
    std::vector<Passenger> passengers; // higher frequency of insertion/deletions, but does it have so many ?

    std::vector<Flight> flights; // this probably does not have to be here (in planes we have this information)
public:
    Manager(const std::string& flights_path);

    bool addFlightToPlanePlan(Flight& flight); // success or not

    void showSortedPassengers(ostream& ostream1);
    void showSortedFlights(ostream& ostream1);


};


#endif //AED_T1_MANAGER_H

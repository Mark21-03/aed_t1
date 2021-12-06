#ifndef AED_T1_MANAGER_H
#define AED_T1_MANAGER_H

#include <list>
#include "Plane.h"
#include "Passenger.h"
#include <vector>
#include <ostream>
#include <fstream>
#include <iomanip>

class Manager {
private:
    string filesDir = "../include/filesPaths.txt";

    string flights_path, planes_path,passengers_path;
    void setPaths();



    std::vector<Plane> planes;
    std::vector<Passenger> passengers; // higher frequency of insertion/deletions, but does it have that many ? or more search?
    std::vector<Flight> flights; // this probably does not have to be here (in planes we have this information)

public:
    Manager();
    explicit Manager(const std::string&dirs){
        this->filesDir = dirs;
    }

    bool addFlightToPlanePlan(Flight& flight); // success or not

    void showSortedPassengers(ostream& ostream1);
    void showSortedFlights(ostream& ostream1);
    void showSortedPlanes(ostream& ostream1);



};


#endif //AED_T1_MANAGER_H

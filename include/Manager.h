#ifndef AED_T1_MANAGER_H
#define AED_T1_MANAGER_H

#include <list>
#include "Plane.h"
#include "Passenger.h"
#include <vector>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <climits>
#include "Output.h"
#include "ServiceManagement.h"


class Manager {
private:
    string filesDir = "../include/filesPaths.txt";

    string flights_path, planes_path,passengers_path, service_path;
    void setPaths();

    void readFlights();
    void readPlanes();
    void readPassengers();
    void readServices();




    ServiceManagement serviceManager;



    std::vector<Plane> planes;
    std::vector<Passenger> passengers; // higher frequency of insertion/deletions, but does it have that many ? or more search?
    std::vector<Flight> flights; // this probably does not have to be here (in planes we have this information)

public:
    Manager();
    ~Manager();
    explicit Manager(const std::string&dirs){
        this->filesDir = dirs;
    }

    bool addFlightToPlanePlan(Flight& flight); // success or not

    void showSortedPassengersByID(ostream& ostream1, unsigned int min = 0, unsigned int max = INT_MAX);
    void showSortedFlightsByID(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX);
    void showSortedFlightsByOrigin(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX); // TODO LATER
    void showSortedFlightsByDestiny(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX);// TODO LATER



    void showSortedPlanes(ostream& ostream1, const planePlate& min,const planePlate& max);

    void showDoneServices(ostream& ostream1, const Date& min, const Date& max);

    void searchPassengers(int id);
    void searchFlights(int id);
    void searchPlanes(string id);
    void searchServices(ServiceType type, Date date, employerName employer, planePlate plane);




    void createPassenger(const string &Pname);
    void createPlane(const planePlate& numberPlate ,const std::string& pType, int capacity);
    void createFlight(const Date& departureDate,const Time& departureTime, const float &duration,std::string origin, std::string destiny);

    bool deletePassenger(const unsigned &idD);
    bool deletePlane(const string &idD);
    bool deleteFlight(const unsigned &idD);

};


#endif //AED_T1_MANAGER_H

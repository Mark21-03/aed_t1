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
#include "BST.h"
#include "Transports.h"


class Manager {
private:

    string filesDir = "../include/filesPaths.txt";
    string flights_path, planes_path,passengers_path, service_path, transports_path;

    ServiceManagement serviceManager;
    std::vector<Plane> planes;
    std::vector<Passenger> passengers;
    std::vector<Flight> flights;

    void setPaths();
    void readFlights();
    void readPlanes();
    void readPassengers();
    void readServices();
    void readTransports();


public:
    BST<Transport> transportsTree; //TODO temporarly made public for testing
    Manager();
    ~Manager();
    explicit Manager(const std::string&dirs){
        this->filesDir = dirs;
    }

    inline ServiceManagement& getServiceManager(){return serviceManager;}

    bool addFlightToPlanePlan(Flight& flight); // success or not // TODO LATER

    void showSortedPassengersByID(ostream& ostream1, unsigned int min = 0, unsigned int max = INT_MAX);
    void showSortedFlightsByID(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX);
    void showSortedFlightsByOrigin(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX); // TODO LATER
    void showSortedFlightsByDestiny(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX);// TODO LATER



    void showSortedPlanes(ostream& ostream1, const planePlate& min,const planePlate& max);

    void showDoneServices(ostream& ostream1, const Date& min, const Date& max);
    void showToDoServices(ostream& ostream1, const Date& min, const Date& max);

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

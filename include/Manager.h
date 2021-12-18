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
#include <map>
#include <regex>
#include "Output.h"
#include "Service.h"
#include "ServiceManagement.h"
#include "BST.h"
#include "Transports.h"

class Manager {
private:

    string filesDir = "../include/filesPaths.txt";
    string flightsPath, planesPath,passengersPath, servicePath, transportsPath, tickets_path;

    ServiceManagement serviceManager;
    std::vector<Plane> planes;
    std::vector<Passenger> passengers;
    std::vector<Flight> flights;
    multiset<Ticket> tickets;

    BST<Transport> transportsTree;
    // map<std::string, BST<Transport>> airportTransports;

    void setPaths();
    void readFlights();
    void readPlanes();
    void readPassengers();
    void readServices();
    void readTransports();
    void readTickets();


public:
    Manager();
    ~Manager();
    explicit Manager(const std::string&dirs){
        this->filesDir = dirs;
    }


    inline ServiceManagement* getServiceManager(){return &serviceManager;}

    inline BST<Transport> *getTransportTree(){return &transportsTree;}

    void showSortedPassengersById(ostream& ostream1, unsigned int min = 0, unsigned int max = INT_MAX);
    void showSortedFlightsById(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX);
    void showSortedFlightsByOrigin(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX); // TODO LATER
    void showSortedFlightsByDestiny(ostream& ostream1, flightNumber min = 0, flightNumber max = INT_MAX);// TODO LATER
    bool addFlightToPlanePlan(Flight& flight); // success or not // TODO LATER


    void showSortedPlanesById(ostream &ostream1, const planePlate& min, const planePlate& max);
    void showSortedPlanesOfType(ostream &ostream1, const std::string & min);

    void showDoneServices(ostream& ostream1, const Date& min, const Date& max);
    void showToDoServices(ostream& ostream1, const Date& min, const Date& max);

    void searchUpdatePassengers(int id);
    bool searchPassengerId(ostream &ostream1, const regex& exp);
    bool searchFlightsOrigins(ostream &ostream1, const regex& exp);
    bool searchFlightsDestiny(ostream &ostream1, const regex& exp);


    void searchUpdateFlights(int id);
    void searchUpdatePlanes(const string& id);
    void searchUpdateServices(char type, Date date, string employer, planePlate plane);

    bool confirmationPrompt();


    void createPassenger(const string &Pname);
    void createPlane(const planePlate& numberPlate ,const std::string& pType, int capacity);
    void createFlight(const Date& departureDate,const Time& departureTime, const float &duration,std::string origin, std::string destiny);
    void createTicket(int flight, int passengerID, float price, ClassType tClass);
    Flight* getFlightbyNumber(flightNumber number);

    inline multiset<Ticket>* getTickets(){return &tickets;}

    bool deletePassenger(const unsigned &idD);
    bool deletePlane(const string &idD);
    bool deleteFlight(const unsigned &idD);

    bool validBuy(Ticket ticket);
};


#endif //AED_T1_MANAGER_H

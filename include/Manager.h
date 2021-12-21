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
#include "BagaggeCheckIn.h"

class Manager {
private:

    string filesDir = "../include/filesPaths.txt";
    string flightsPath, planesPath, passengersPath, servicePath, transportsPath, tickets_path;

    ServiceManagement serviceManager;
    std::vector<Plane> planes;
    std::vector<Passenger> passengers;
    std::vector<Flight> flights;
    multiset<Ticket> tickets;

    BST<Transport> transportsTree;
    map<std::string, BST<Transport>> airportTransports;

    /**
     * Sets the path to all the files
     */
    void setPaths();

    /**
     * Reads the Flights from the file and push them into a vector
     */
    void readFlights();

    /**
     * Reads the Planes from the file and push them into a vector
     */
    void readPlanes();

    /**
     * Reads the Passengers from the file and push them into a vector
     */
    void readPassengers();

    /**
     * Reads the Services from the file and push them into a vector
     */
    void readServices();

    /**
     * Reads the Transports from the file and push them into a vector
     */
    void readTransports();

    /**
     * Reads the Tickets from the file and push them into a vector
     */
    void readTickets();


public:
    /**
     * Default constructor
     */
    Manager();

    /**
     * Destructor
     */
    ~Manager() = default;

    /**
     * TODO
     * @param dirs TODO
     */
    explicit Manager(const std::string &dirs) {
        this->filesDir = dirs;
    }

    /**
     * TODO
     * @return TODO
     */
    inline ServiceManagement *getServiceManager() { return &serviceManager; }

    /**
     * Gives the BST with the transports
     * @return BST with transports
     */
    inline BST<Transport> *getTransportTree() { return &transportsTree; }

    /**
     * TODo
     * @return TODO
     */
    inline map<string, BST<Transport>> *getTransportmap() { return &airportTransports; }

    /**
     * Shows the passengers sorted by a order that the user chooses
     * @param ostream1 ostream to be used
     * @param sortOption Sort option (n - name and d - birth date)
     * @param min lowest id to show
     * @param max highest id to show
     */
    void showSortedPassengersBySortOption(ostream &ostream1, const std::string &sortOption, unsigned int min = 0,
                                          unsigned int max = INT_MAX);

    /**
     * Shows the passengers sorted by their id
     * @param ostream1 ostream to be used
     * @param min lowest id to show
     * @param max highest id to show
     */
    void showSortedPassengersById(ostream &ostream1, unsigned int min = 0, unsigned int max = INT_MAX);

    /**
     * Shows the flights sorted by their id
     * @param ostream1 ostream to be used
     * @param min lowest id to show
     * @param max highest id to show
     */
    void showSortedFlightsById(ostream &ostream1, flightNumber min = 0, flightNumber max = INT_MAX);

    /**
     * Shows the flights sorted by a order that the user chooses
     * @param ostream1 ostream to be used
     * @param sortOption sort option (o - occupation, d - departur date, t - departure time)
     * @param min lowest id to show
     * @param max highest id to show
     */
    void showSortedFlightsBySortOption(ostream &ostream1, const std::string &sortOption, flightNumber min = 0,
                                       flightNumber max = INT_MAX);

    /**
     * Shows the trasnports available to the airport
     * @param os ostream to be used
     * @param airport airport that we want to see the tranports to
     * @return bool value that represents if the airport has at least one transport to it
     */
    bool showAirportTransports(ostream &os, const string &airport);

    /**
     * Adds a transport available to an airport
     * @param os ostream to be used
     * @param airport airport that will be added the transport
     * @param transport transport to be added
     * @return bool value that represents if the transport was added with success or not
     */
    bool addTransportToAirport(ostream &os, const string &airport, Transport &transport);

    /**
     * Removes a transport from an airport
     * @param os ostream to be used
     * @param airport airport from where will be removed the transport
     * @param transport transport to be removed
     * @returnbool value that represents if the transport was removed with success or not
     */
    bool removeTransportInAirport(ostream &os, const string &airport, Transport &transport);

    /**
     * Updates a transport from an airport
     * @param os ostream to be used
     * @param airport airport where the transport will be updated
     * @param transport transport to be updated
     * @return value that represents if the transport was updated with success or not
     */
    bool updateTransportInAirport(ostream &os, const string &airport, Transport &transport);

    /**
     * Shows the planes sorted by id
     * @param ostream1 ostream to be used
     * @param min lowest id to show
     * @param max highest id to show
     */
    void showSortedPlanesById(ostream &ostream1, const planePlate &min, const planePlate &max);

    /**
     * Shows the planes sorted by a order that the user chooses
     * @param ostream1 ostream to be used
     * @param sortOption sort option (t - type, c - capacity, n - number of flights)
     * @param min lowest id to show
     * @param maxhighest id to show
     */
    void showSortedPlanesBySortedOption(ostream &ostream1, const std::string &sortOption, const planePlate &min,
                                        const planePlate &max);

    /**
     * Shows the planes from a certain type sorted by id
     * @param ostream1 ostream to be used
     * @param min type wanted
     */
    void showSortedPlanesOfType(ostream &ostream1, const std::string &min);

    /**
     * Shows the services that were already done
     * @param ostream1 ostream to be used
     * @param min lowest date to show
     * @param max highest date to show
     */
    void showDoneServices(ostream &ostream1, const Date &min, const Date &max);

    /**
     * Shows the services to do
     * @param ostream1 ostream to be used
     * @param min lowest date to show
     * @param max highest date to show
     */
    void showToDoServices(ostream &ostream1, const Date &min, const Date &max);

    /**
     * Searches a passenger with a certain id and update it
     * @param id id of the passenger
     */
    void searchUpdatePassengers(int id);

    /**
     * Searches a passenger with a certain id
     * @param ostream1 ostream to be used
     * @param exp id wanted
     * @return bool result representing the success or not in finding the passenger
     */
    bool searchPassengerId(ostream &ostream1, const regex &exp);

    /**
     * Searches flights by their origin
     * @param ostream1 ostream to be used
     * @param exp origin wanted
     * @param sortOption sort option wanted (o - occupation, d - departur date, t - departure time)
     * @return bool result representing  the success or not in finding the flight
     */
    bool searchFlightsOrigins(ostream &ostream1, const regex &exp, const std::string &sortOption = "");

    /**
     * Searches flights by their destiny
     * @param ostream1 ostream to be used
     * @param exp destiny wanted
     * @param sortOption sort option wanted (o - occupation, d - departur date, t - departure time)
     * @return bool result representing  the success or not in finding the flight
     */
    bool searchFlightsDestiny(ostream &ostream1, const regex &exp, const std::string &sortOption = "");

    /**
     * Searches flights by their id
     * @param id id wanted
     */
    void searchUpdateFlights(int id);

    /**
     * Searches planes by their id
     * @param id id wanted
     */
    void searchUpdatePlanes(const string &id);

    /**
     * Searches services by their type, date, employee and plane
     * @param type type wanted
     * @param date date wanted
     * @param employee employee wanted
     * @param plane plane wanted
     */
    void searchUpdateServices(char type, Date date, string employee, planePlate plane);

    /**
     * Confirmation prompt before saving the changes
     * @return bool result
     */
    bool confirmationPrompt();

    /**
     * The passenger makes the check in (the baggage go to the plane)
     * @param flightID flight's id that the passenger will take
     */
    void makeCheckIn(flightNumber flightID);

    /**
     * Increments the flight occupation when a ticket is bought
     * @param ID id of the flight
     */
    void incrementFlightOccupation(flightNumber ID);

    /**
     * Moves the baggage to the plane (during the check-in)
     * @param flightID id of the flight
     */
    void moveBaggageToPlane(flightNumber flightID);

    /**
     * Creates a new passenger
     * @param Pname passenger's name
     * @param birth passenger's birth date
     */
    void createPassenger(const string &Pname, Date birth);

    /**
     * Creates a new plane
     * @param numberPlate Plane's plate number
     * @param pType Plane's type
     * @param capacity Plane's capacity
     */
    void createPlane(const planePlate &numberPlate, const std::string &pType, int capacity);

    /**
     * Creates a new flight
     * @param departureDate Flight's departure date
     * @param departureTime Flight's departure Time
     * @param duration Flight's duration
     * @param origin Flight's origin
     * @param destiny Flight's destiny
     */
    void createFlight(const Date &departureDate, const Time &departureTime, const float &duration, std::string origin,
                      std::string destiny);

    /**
     * Creates a new ticket
     * @param flight Ticket's flight
     * @param passengerID Id of the passenger owner of the Ticket
     * @param price Ticket's price
     * @param tClass Ticket's class
     */
    void createTicket(flightNumber flight, int passengerID, float price, ClassType tClass);

    /**
     * Gets a flight object by his number
     * @param number flight's number
     * @return Flight wanted
     */
    Flight *getFlightByNumber(flightNumber number);

    /**
     *TODO i think its never used but i need confirmation form who has done it
     * @return
     */
    inline multiset<Ticket> *getTickets() { return &tickets; }

    /**
     * Deletes a passenger with a certain id
     * @param idD Passenger's id
     * @return bool result representing the success or not deleting the passenger
     */
    bool deletePassenger(const unsigned &idD);

    /**
     * Deletes a plane with a certain id
     * @param idD Plane's id
     * @return bool result representing the success or not deleting the plane
     */
    bool deletePlane(const string &idD);

    /**
     * Deletes a flight with a certain id
     * @param idD Flight's id
     * @return bool result representing the success or not deleting the flight
     */
    bool deleteFlight(const unsigned &idD);

    /**
     * Saves all the alterations done in the objects in the files
     */
    void saveToFile();

};


#endif //AED_T1_MANAGER_H

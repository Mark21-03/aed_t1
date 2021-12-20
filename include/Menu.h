#ifndef T
#define T

#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "Menu.h"
#include "Manager.h"
#include "Input.h"


//Sets CLEAR variable for cleaning terminal GUI for linux and window
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

/**
 *  The Menu of the application. It provides a Main Menu with a few sub-Menus responsible for the flow of the program
 */
class Menu {
    /**
     * A private manager instance.
     * Responsible for the manipulation of data.
     */
    Manager manager;
    /**
     * A private service manager pointer.
     * A pointer to the manager Service manager, helpful to obtain direct access to data.
     */
    ServiceManagement  *serviceManager = manager.getServiceManager();

    /**
     * Ask user if they really want to do the operation asked
     * @return bool confirmation of the operation
     */
    bool menuOperationConfirm();

    /**
     * A pointer to a member function. It serves as an anchor to connect with an object of the class method.
     */
    void (Menu::*x)(){};
    /**
     * A vector of pointers to class members. The vector represents the creates methods in the class.
     */
    const vector<void (Menu::*)()> createFuncs = {&Menu::funcCreatePassenger, &Menu::funcCreatePlane,&Menu::funcCreateFlight, &Menu::funcCreateService,&Menu::addNewTransport};
    /**
     * A vector of pointers to class members. The vector represents the reads methods in the class.
     */
    const vector<void (Menu::*)()> readFuncs   = {&Menu::funcReadPassenger,   &Menu::funcReadPlane,  &Menu::funcReadFlight,   &Menu::funcReadService, &Menu::showNearbyTransports };
    /**
     * A vector of pointers to class members. The vector represents the updates methods in the class.
     */
    const vector<void (Menu::*)()> updateFuncs = {&Menu::funcUpdatePassenger, &Menu::funcUpdatePlane, &Menu::funcUpdateFlight, &Menu::funcUpdateService, &Menu::updateTransports};
    /**
     * A vector of pointers to class members. The vector represents the deletes methods in the class.
     */
    const vector<void (Menu::*)()> deleteFuncs = {&Menu::funcDeletePassenger, &Menu::funcDeletePlane,&Menu::funcDeleteFlight, &Menu::funcDeleteService,&Menu::removeNearbyTransport};

    /**
     * Responsible for the create option of the passengers. It adds the new Passenger to the manager data.
     */
    void funcCreatePassenger();
    /**
     * Responsible for the create option of the planes. It adds the new Plane to the manager data.
     */
    void funcCreatePlane();
    /**
     * Responsible for the read option of the flights. It adds the new Flight to the manager data.
     */
    void funcCreateFlight();
    /**
     * Responsible for the read option of the services. It adds the new Service to the service manager data.
     */
    void funcCreateService();
    /**
     * Buying tickets option. It guarantees the validity of the purchase, checking the maximum capacity of the flight.
     */
    void BuyTicket();

    /**
     * Responsible for the delete option of the passengers. It deletes the Passenger from the manager data.
     */
    void funcDeletePassenger();
    /**
    * Responsible for the delete option of the planes. It deletes the Plane from the manager data.
    */
    void funcDeletePlane();
    /**
     * Responsible for the delete option of the flights. It deletes the flight from the manager data.
     */
    void funcDeleteFlight();
    /**
     * Responsible for the delete option of the services. It deletes the Service from the service manager data.
     */
    void funcDeleteService();

    /**
     * Responsible for providing the user with sort, search and complete/partial displaying of the passenger data.
     */
    void funcReadPassenger();
    /**
     * Responsible for providing the user with sort, search and complete/partial displaying of the planes data.
     */
    void funcReadPlane();
    /**
     * Responsible for providing the user with sort, search and complete/partial displaying of the flights data.
     */
    void funcReadFlight();
    /**
     * Responsible for providing the user with sort, search and complete/partial displaying of the services data.
     */
    void funcReadService();

    /**
     * Responsible for the update option of the passengers. It updates the passenger information from the manager data. New information is get from cin.
     */
    void funcUpdatePassenger();
    /**
     * Responsible for the update option of the planes. It updates the plane information from the manager data. New information is get from cin.
     */
    void funcUpdatePlane();
    /**
     * Responsible for the update option of the passengers. It updates the passenger information from the manager data. New information is get from cin.
     */
    void funcUpdateFlight();
    /**
     * Responsible for the update option of the services. It updates the service information from the service manager data. New information is get from cin.
     */
    void funcUpdateService();


    int askChangeId();
    char askTypeService();
    Date askDateService();
    string askEmployeeService();
    string askPlateService();

    /**
     * Show airport near transports. The airport name is get from in cin and most correspond to an airport to which we have information about.
     */
    void showNearbyTransports();
    /**
     * Adds transport to an airport. In order to make this more user-friendly, the transports timetable is generated automatically. You can change the timetable with an update.
     */
    void addNewTransport();
    /**
     * Removes transport from an airport. The airport name is get from cin, the transport information must be one already in the airport B.S.T.
     */
    void removeNearbyTransport();
    /**
     * Updates transport timetable from an airport. It asks the frequency of the transport in a day and the times in which the service is done.
     */
    void updateTransports();
    /**
     * A function that simulates the check in of a Flight. A number of the flight to do the check in is provided ... the baggage is move from the the conveyor belt to the plane.
     */
    void doCheckIn();

    /**
     * Asks the user if it wants partial or complete listing. Returning the validity of the first statement
     * @return bool indicating if the user wants or not the partial listing.
     */
    bool partialListingType();

    /**
     *A sub-Menu for the CRUD operations.
     * @param menuTitle the name of the new sub menu
     * @param funcs the member functions that correspond to the menu options
     */
    void subMenu(const string &menuTitle, vector<void (Menu::*)()> funcs);
    /**
     * A sub-Menu with other important functions.
     */
    void othersSubMenu();
    /*
     * Calls the manager method tha saves the data files. It also outputs the status of the program.
     */
    void saveDataFiles();


public:
    /**
     * Constructor of a menu;
     * @param manager1 the menu manager, responsible for managing the data information
     */
    explicit Menu(Manager& manager1) : manager(manager1){}
    /**
     * The main Menu. Responsible for the flow of the program and the only public method of the class.
     */
    void mainMenu();
};
#endif
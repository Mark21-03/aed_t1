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


class Menu {
    Manager manager;
    ServiceManagement  *serviceManager = manager.getServiceManager();

    bool menuOperationConfirm();

    void (Menu::*x)();
    const vector<void (Menu::*)()> createFuncs = {&Menu::funcCreatePassenger, &Menu::funcCreatePlane,&Menu::funcCreateFlight, &Menu::funcCreateService,&Menu::funcCreateTicket};
    const vector<void (Menu::*)()> readFuncs   = {&Menu::funcReadPassenger,   &Menu::funcReadPlane,  &Menu::funcReadFlight,   &Menu::funcReadService,  &Menu::funcReadTicket};
    const vector<void (Menu::*)()> updateFuncs = {&Menu::funcUpdatePassenger, &Menu::funcUpdatePlane, &Menu::funcUpdateFlight, &Menu::funcUpdateService, &Menu::funcUpdateTicket};
    const vector<void (Menu::*)()> deleteFuncs = {&Menu::funcDeletePassenger, &Menu::funcDeletePlane,&Menu::funcDeleteFlight, &Menu::funcDeleteService,&Menu::funcDeleteTicket};

    void funcCreatePassenger();
    void funcCreatePlane();
    void funcCreateFlight();
    void funcCreateService();
    void funcCreateTicket();

    void funcDeletePassenger();
    void funcDeletePlane();
    void funcDeleteFlight();
    void funcDeleteService();
    void funcDeleteTicket();

    void funcReadPassenger();
    void funcReadPlane();
    void funcReadFlight();
    void funcReadService();
    void funcReadTicket();

    void funcUpdatePassenger();
    void funcUpdatePlane();
    void funcUpdateFlight();
    void funcUpdateService();
    void funcUpdateTicket();
    int askChangeId();


    void subMenu(const string &menuTitle, vector<void (Menu::*)()> funcs);

    //TODO all read funcs must call this menu first to choose which values to be displayed and if sorted etc.
    //TODO Read Funcs must give this menu their on display functions because each class must be displayed differently
    void readSubMenu(string menuTitle,vector<void (Menu::*)()> funcs);


public:
    Menu(Manager& manager1) : manager(manager1){}
    void mainMenu();
};
#endif
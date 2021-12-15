
#ifndef T
#define T

#include <iostream>
#include <vector>
#include <string>
#include "Menu.h"
#include "Manager.h"
#include "Input.h"

//WORK IN PROGRESS MENU EXAMPLE

//Sets CLEAR variable for cleaning terminal GUI for linux and window
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif


class Menu {
    Manager manager;

    bool MenuOperationConfirm(){
        char confirm;

        cout<<"\nConfirm? (Y/N): ";cin>>confirm;

        if(confirm == 'Y' || confirm == 'y')
            return true;
        else
            cout<<"Canceled. Press any key to continue... ";

        return false;
    }

    const vector<void (Menu::*)()> createFuncs = {&Menu::funcCreatePassenger, &Menu::funcCreatePlane,&Menu::funcCreateFlight, &Menu::funcCreateService,&Menu::funcCreateTicket};
    const vector<void (Menu::*)()> readFuncs   = {&Menu::funcReadPassenger,   &Menu::funcReadPlane,  &Menu::funcReadFlight,   &Menu::funcReadService,  &Menu::funcReadTicket};
    const vector<void (Menu::*)()> updateFuncs = {&Menu::funcUpdatePassenger, &Menu::funcUpdatePlane, &Menu::funcUpdateFlight, &Menu::funcUpdateService, &Menu::funcUpdateTicket};
    const vector<void (Menu::*)()> deleteFuncs = {&Menu::funcDeletePassenger, &Menu::funcDeletePlane,&Menu::funcDeleteFlight, &Menu::funcDeleteService,&Menu::funcDeleteTicket};




//__________________________________________________

    void funcCreatePassenger() {
        string pName;
        cout<<"\nNew Passenger Name (string): ";getline(cin,pName);

        if (MenuOperationConfirm()) {
                manager.createPassenger(pName);
                cout << "Passenger added!\n";
        }
        getchar();getchar();
    }

    void funcCreatePlane() {
        string numberPlate;
        string pType;
        string capacity;

        cout << "\nNew Plane's Plate (string): ";
        getline(cin, numberPlate);
        cout << "New Plane's Type (string): ";
        getline(cin, pType);
        cout << "New Plane's Capacity (int): ";
        getline(cin, capacity);


        if (MenuOperationConfirm()) {
            manager.createPlane(numberPlate, pType, stoi(capacity));
            cout << "Plane added!\n";
        }
        getchar();getchar();
    }

    void funcCreateFlight() {

         Date departureD;
         Time departureT;
         float duration;
         string origin, destiny;

         cout<<"New Flight's departure date (YYYY/MM/DD): ";cin>>departureD;
         cout<<"New Flight's time (HH:MM:SS): ";cin>>departureT;
         cout<<"New Flight's duration (float): ";cin>>duration;
         cout<<"New Flight's origin (string): "; cin.ignore();getline(cin,origin);
         cout<<"New Flight's destiny (string): "; getline(cin,destiny);

        if (MenuOperationConfirm()) {
            manager.createFlight(departureD,departureT,duration,origin,destiny);
            cout<<"\nFlight added!\n";
        }

        getchar();getchar();
    }

    void funcCreateService() {
        //TODO
        cout << "\n!funcCreateService!\n";
        getchar();
    }

    void funcCreateTicket() {
        //TODO
        cout << "\n!funcCreateTicket!\n";
        getchar();
    }

    void funcDeletePassenger() {

        int id2Delete;
        cout<<"\nID to be deleted: ";cin>>id2Delete;

        cout<<endl;
        manager.showSortedPassengersByID(cout, id2Delete, id2Delete);

        if(MenuOperationConfirm()){
            bool deleted = manager.deletePassenger(id2Delete);
            if(deleted)
                cout<<"Deleted!\n";
            else
                cout<<"Value not found!\n";
        }
        getchar();getchar();
    }

    void funcDeletePlane() {

        string id2Delete;
        cout<<"\nNumberPlate to be deleted: ";getline(cin,id2Delete);

        cout<<endl;
        manager.showSortedPlanes(cout, id2Delete, id2Delete);

        if(MenuOperationConfirm()){
            bool deleted = manager.deletePlane(id2Delete);
            if(deleted)
                cout<<"Deleted!\n";
            else
                cout<<"Value not found!\n";
        }
        getchar();getchar();
    }

    void funcDeleteFlight() {

        int id2Delete;
        cout<<"\nID to be deleted: ";cin>>id2Delete;

        cout<<endl;
        manager.showSortedFlightsByID(cout, id2Delete, id2Delete);

        if(MenuOperationConfirm()){
            bool deleted = manager.deleteFlight(id2Delete);
            if(deleted)
                cout<<"Deleted!\n";
            else
                cout<<"Value not found!\n";
        }
        getchar();getchar();
    }

    void funcDeleteService() {
        //TODO
        int id2Delete;
        cout<<"\nID to be deleted: ";cin>>id2Delete;

        if(MenuOperationConfirm()){

        }
        getchar();getchar();
    }

    void funcDeleteTicket() {
        //TODO
        int id2Delete;
        cout<<"\nID to be deleted: ";cin>>id2Delete;

        if(MenuOperationConfirm()){
            cout<<"Deleted!\n";
        }
        getchar();getchar();
    }

//__________________________________________________



    void funcReadPassenger() {
        unsigned int minID, maxID;
        out::askInterval<unsigned int>(cout, cin, minID, maxID, "Passenger ID");
        manager.showSortedPassengersByID(cout, minID, maxID);
        getchar();getchar();

    }

    void funcReadPlane() {
        planePlate min, max;
        out::askInterval<planePlate>(cout, cin, min, max, "Plate Number");
        manager.showSortedPlanes(cout, min, max);
        getchar();getchar();
    }

    void funcReadFlight() {
        flightNumber min, max;
        out::askInterval<flightNumber>(cout, cin, min, max, "Flight number");
        manager.showSortedFlightsByID(cout, min, max);
        getchar();getchar();

    }


    void funcReadService() {
        Date min, max;

        out::askInterval<Date>(cout, cin, min, max, "Date");

        manager.showDoneServices(cout, min, max);

        getchar();getchar();
    }

    void funcReadTicket() {
        cout << "\n!funcReadTicket!\n";
        getchar();
    }


    void funcUpdatePassenger(){}
    void funcUpdatePlane(){}
    void funcUpdateFlight(){}
    void funcUpdateService(){}
    void funcUpdateTicket(){}

    int funcUpdateAll(){
        int id;
        cout<<"ID of object to change?";
        cin>>id;
        return id;
    }


    void subMenu(const string &menuTitle, vector<void (Menu::*)()> funcs) {
        char userInput;
        string inputError;


        while (true) {
            system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            //Start of MENU

            cout << "================="<< endl;
            cout << menuTitle << endl;
            cout << "=================" << endl;
            cout << "  1)  Passenger" << endl;
            cout << "  2)  Plane" << endl;
            cout << "  3)  Flight" << endl;
            cout << "  4)  Service" << endl;
            cout << "  5)  Ticket" << endl;
            cout << "  6)  Go Back" << endl;
            cout << "  0)  Exit" << endl;
            cout << "================" << endl;
            cout << " > ";
            //End of MENU

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!in::emptyStream(std::cin)) {
                    in::giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '0'://EXIT
                        cout << "End of program.\n";
                        manager.~Manager();
                        getchar();
                        exit(1);

                    case '1'://Passenger
                            this -> x = funcs[0];
                            ((*this).*(this->x))();
                        break;
                    case '2'://Plane
                            this -> x = funcs[1];
                            ((*this).*(this->x))();
                        break;
                    case '3'://Flight
                            this -> x = funcs[2];
                            ((*this).*(this->x))();
                        break;
                    case '4'://Service
                            this -> x = funcs[3];
                            ((*this).*(this->x))();
                        break;
                    case '5'://Ticket
                            this -> x = funcs[4];
                            ((*this).*(this->x))();
                        break;
                    case '6'://Go Back
                        goto END_MENU;
                    default:
                        in::giveMenuInputError(inputError);
                        break;
                }
                //END OF MENU SELECTION
                continue;
            } else {
                in::dealError(inputError);
                continue;
            }

            END_MENU:
            break;
        }
    }


    //TODO all read funcs must call this menu first to choose which values to be displayed and if sorted etc.
    //TODO Read Funcs must give this menu their on display functions because each class must be displayed differently
    void readSubMenu(string menuTitle,vector<void (Menu::*)()> funcs){

        char userInput;
        string inputError;


        while (true) {
            system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            //Start of MENU

            cout << "================="<< endl;
            cout << menuTitle << endl;
            cout << "=================" << endl;
            cout << "  1)  All" << endl;
            cout << "  2)  Single" << endl;
            cout << "  3)  Interval" << endl;
            cout << "  4)  Sorted" << endl;
            cout << "  6)  Go Back" << endl;
            cout << "  0)  Exit" << endl;
            cout << "================" << endl;
            cout << " > ";
            //End of MENU

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!in::emptyStream(std::cin)) {
                    in::giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '0'://EXIT
                        cout << "End of program.\n";
                        manager.~Manager();
                        getchar();
                        exit(1);

                    case '1'://Passenger
                        // this -> x = funcs[0];
                        this -> x = funcs[0];
                        ((*this).*(this->x))();
                        break;
                    case '2'://Plane
                        this -> x = funcs[1];
                        ((*this).*(this->x))();
                        break;
                    case '3'://Flight
                        this -> x = funcs[2];
                        ((*this).*(this->x))();
                        break;
                    case '4'://Service
                        this -> x = funcs[3];
                        ((*this).*(this->x))();
                        break;
                    case '5'://Ticket
                        this -> x = funcs[4];
                        ((*this).*(this->x))();
                        break;
                    case '6'://Go Back
                        goto END_MENU;
                    default:
                        in::giveMenuInputError(inputError);
                        break;
                }
                //END OF MENU SELECTION
                continue;
            } else {
                in::dealError(inputError);
                continue;
            }

            END_MENU:
            break;
        }

    }



public:
    Menu(Manager& manager1) : manager(manager1){}

    void mainMenu() {
        char userInput;
        string inputError;

        while (true) {
           system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            //Start of MENU
            cout << "=================" << endl;
            cout << "       Menu      " << endl;
            cout << "=================" << endl;
            cout << "  1)  Create" << endl;
            cout << "  2)  Read" << endl;
            cout << "  3)  Update" << endl;
            cout << "  4)  Delete" << endl;
            cout << "  0)  Exit" << endl;
            cout << "================" << endl;
            cout << " > ";
            //End of MENU

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!in::emptyStream(cin)) {
                    in::giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '0'://EXIT
                        cout << "End of program.\n";
                        manager.~Manager();
                        getchar();
                        exit(1);

                    case '1'://CREATE
                        subMenu("   CREATE MENU",   createFuncs);
                        break;
                    case '2'://READ
                        subMenu("    READ MENU",  readFuncs);
                        break;
                    case '3'://UPDATE
                        subMenu("   UPDATE MENU",   updateFuncs);
                        break;
                    case '4'://DELETE
                        subMenu("   DELETE MENU",   deleteFuncs);
                        break;
                    default:
                        in::giveMenuInputError(inputError);
                        break;
                }
                //END OF MENU SELECTION

                continue;

            } else {
                in::dealError(inputError);
                continue;
            }
        }
    }

    void (Menu::*x)();
};
#endif

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

    const vector<void (Menu::*)()> createFuncs = {&Menu::funcCreatePassanger, &Menu::funcCreatePlane,&Menu::funcCreateFlight, &Menu::funcCreateService,&Menu::funcCreateTicket};
    const vector<void (Menu::*)()> readFuncs   = {&Menu::funcReadPassenger,   &Menu::funcReadPlane,  &Menu::funcReadFlight,   &Menu::funcReadService,  &Menu::funcReadTicket};
    const vector<void (Menu::*)()> updateFuncs = {&Menu::funcUpdatePassenger, &Menu::funcUpdatePlane, &Menu::funcUpdateFlight, &Menu::funcUpdateService, &Menu::funcUpdateTicket};
    const vector<void (Menu::*)()> deleteFuncs = {&Menu::funcDeletePassanger, &Menu::funcDeletePlane,&Menu::funcDeleteFlight, &Menu::funcDeleteService,&Menu::funcDeleteTicket};

//___________________________TEMPORARY_TESTING_______________________________

    void funcCreatePassanger() {
        cout << "\n!funcCreatePassanger!\n";
        getchar();
    }

    void funcCreatePlane() {
        cout << "\n!funcCreatePlane!\n";
        getchar();
    }

    void funcCreateFlight() {
        cout << "\n!funcCreateFlight!\n";
        getchar();
    }

    void funcCreateService() {
        cout << "\n!funcCreateService!\n";
        getchar();
    }

    void funcCreateTicket() {
        cout << "\n!funcCreateTicket!\n";
        getchar();
    }


    void funcReadPassenger() {
        unsigned int minID, maxID;
        out::askID(cout, cin, minID, maxID);
        manager.showSortedPassengersByID(cout, minID, maxID); // TODO: VERIFY THE UINT
        getchar();

    }

    void funcReadPlane() {
        manager.showSortedPlanes(cout);
        getchar();
    }

    void funcReadFlight() {
        flightNumber min, max;
        out::askID(cout, cin, min, max);
        manager.showSortedFlightsByID(cout, min, max); // TODO: in here we will have to ask in what order to sort
        // TODO: tb temos de ver a questão das listagens várias
        getchar();

    }


    void funcReadService() {
        cout << "\n!funcReadService!\n";
        getchar();
    }

    void funcReadTicket() {
        cout << "\n!funcReadTicket!\n";
        getchar();
    }


    void funcUpdatePassenger() {
        /*
        //cout << "\n!funcUpdatePassenger!\n";
        //getchar();
        char userInput;
        string inputError;
        while (true) {
            system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            cout << "=================" << endl;
            cout << " UPDATE PASSENGER      " << endl;
            cout << "=================" << endl;
            cout << "  1)  Name" << endl;
            cout << "  2)  ID" << endl;
            cout << "  3)  Go Back" << endl;
            cout << "================" << endl;
            cout << " > ";

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!emptyCin()) {
                    giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '1'://UPDATE NAME
                        cout << "nameUpdate";//reminder - fazer cena q pergunt eo nome, verificar se esta no vetor, perguntar qual o novo, alterar e guardar
                        break;
                    case '2'://UPDATE ID
                        cout << "idUpdate";//msm q em cima mas com id
                        break;
                    case '3'://GO BACK
                        //cout<<"Back!";
                        goto END_MENU;
                        //break;
                    default:
                        giveMenuInputError(inputError);
                        break;
                }
            }
            END_MENU:
            break;
        }*/
    }

    void funcUpdatePlane() {
        /*
        //cout << "\n!funcUpdatePlane!\n";
        //getchar();
        char userInput;
        string inputError;
        while (true) {
            system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            cout << "=================" << endl;
            cout << "   UPDATE PLANE          " << endl;
            cout << "=================" << endl;
            cout << "  1)  Plate Number" << endl;
            cout << "  2)  Plane Type" << endl;
            cout << "  3)  Capacity" << endl;
            cout << "  4)  Flight Plan" << endl;
            cout << "  5)  Go Back" << endl;
            cout << "================" << endl;
            cout << " > ";

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!emptyCin()) {
                    giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '1'://UPDATE PLATE NUMBER
                        cout << "PlateNUmber";//reminder - fazer cena q pergunt eo nome, verificar se esta no vetor, perguntar qual o novo, alterar e guardar
                        break;
                    case '2'://UPDATE PLANE TYPE
                        cout << "PlaneType";//msm q em cima mas com id
                        break;
                    case '3'://UPDATE CAPACITY
                        cout << "Capacity";//msm q em cima mas com id
                        break;
                    case '4'://UPDATE FLIGHT PLAN
                        cout<<"Flight Plan";
                        break;
                    case '5'://GO BACK
                        //cout<<"Back!";
                        goto END_MENU;
                        //break;
                    default:
                        giveMenuInputError(inputError);
                        break;
                }
            }
            END_MENU:
            break;
        }
         */
    }

    void funcUpdateFlight() {/*
        //cout << "\n!funcUpdatePlane!\n";
        //getchar();
        char userInput;
        string inputError;
        while (true) {
            system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            cout << "=================" << endl;
            cout << "  UPDATE FLIGHT         " << endl;
            cout << "=================" << endl;
            cout << "  1)  Flight Number" << endl;
            cout << "  2)  Departure Date" << endl;
            cout << "  3)  Departure Time" << endl;
            cout << "  4)  Go Back" << endl;
            cout << "================" << endl;
            cout << " > ";

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!emptyCin()) {
                    giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '1'://UPDATE FLIGHT NUMBER
                        cout << "FlightNumber";//reminder - fazer cena q pergunt eo nome, verificar se esta no vetor, perguntar qual o novo, alterar e guardar
                        break;
                    case '2'://UPDATE DEPARTURE DATE
                        cout << "Departure Date";//msm q em cima mas com id
                        break;
                    case '3'://UPDATE DEPARTURE TIME
                        cout << "Departure Time";//msm q em cima mas com id
                        break;
                    case '4'://GO BACK
                        //cout<<"Back!";
                        goto END_MENU;
                        //break;
                    default:
                        giveMenuInputError(inputError);
                        break;
                }
            }
            END_MENU:
            break;
        }*/
    }

    void funcUpdateService() {/*
        //cout << "\n!funcUpdatePlane!\n";
        //getchar();
        char userInput;
        string inputError;
        while (true) {
            system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            cout << "=================" << endl;
            cout << " UPDATE SERVICE       " << endl;
            cout << "=================" << endl;
            cout << "  1)  Type" << endl;
            cout << "  2)  Date" << endl;
            cout << "  3)  Employer" << endl;
            cout << "  4)  Go Back" << endl;
            cout << "================" << endl;
            cout << " > ";

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!emptyCin()) {
                    giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '1'://UPDATE TYPE
                        cout << "Type";//reminder - fazer cena q pergunt eo nome, verificar se esta no vetor, perguntar qual o novo, alterar e guardar
                        break;
                    case '2'://UPDATE DATE
                        cout << "Date";//msm q em cima mas com id
                        break;
                    case '3'://UPDATE EMPLOYER
                        cout << "Employer";//msm q em cima mas com id
                        break;
                    case '4'://GO BACK
                        //cout<<"Back!";
                        goto END_MENU;
                        //break;
                    default:
                        giveMenuInputError(inputError);
                        break;
                }
            }
            END_MENU:
            break;
        }*/
    }

    void funcUpdateTicket() { /*
        //why would a passenger change a ticket and what to change?? i think it doesn't make much sense
        //cout << "\n!funcUpdatePlane!\n";
        //getchar();
        char userInput;
        string inputError;
        while (true) {
            system(CLEAR);

            if (!inputError.empty())
                cout << inputError;
            inputError = "";

            cout << "=================" << endl;
            cout << "  UPDATE TICKET         " << endl;
            cout << "=================" << endl;
            cout << "  1)  Flight Info" << endl;
            cout << "  2)  Passenger ID" << endl;
            cout << "  3)  Go Back" << endl;
            cout << "================" << endl;
            cout << " > ";

            if ((cin >> userInput)) {
                //raises error if more than 1 char is written by user
                if (!emptyCin()) {
                    giveMenuInputError(inputError);
                    continue;
                }

                //START OF MENU SELECTION
                switch (userInput) {
                    case '1'://UPDATE FLIGHT INFO
                        cout << "FlightInfo";//reminder - fazer cena q pergunt eo nome, verificar se esta no vetor, perguntar qual o novo, alterar e guardar
                        break;
                    case '2'://UPDATE PASSENGER ID
                        cout << "PassengerId";//msm q em cima mas com id
                        break;
                    case '3'://GO BACK
                        //cout<<"Back!";
                        goto END_MENU;
                        //break;
                    default:
                        giveMenuInputError(inputError);
                        break;
                }
            }
            END_MENU:
            break;
        }*/
    }


    void funcDeletePassanger() {
        cout << "\n!funcDeletePassanger!\n";
        getchar();
    }

    void funcDeletePlane() {
        cout << "\n!funcDeletePlane!\n";
        getchar();
    }

    void funcDeleteFlight() {
        cout << "\n!funcDeleteFlight!\n";
        getchar();
    }

    void funcDeleteService() {
        cout << "\n!funcDeleteService!\n";
        getchar();
    }

    void funcDeleteTicket() {
        cout << "\n!funcDeleteTicket!\n";
        getchar();
    }



//___________________________TEMPORARY_TESTING_______________________________


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
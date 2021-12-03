
#ifndef T
#define T

#include <iostream>
#include <vector>
#include <string>
#include "Manager.h"

//WORK IN PROGRESS MENU EXAMPLE

using namespace std;

//Sets CLEAR variable for cleaning terminal GUI for linux and window
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif


Manager manager("../Files/Flights/flights.txt"); // TODO: IT's a global ...

//___________________________TEMPORARY_TESTING_______________________________

void funcCreatePassanger(){
    cout<<"\n!funcCreatePassanger!\n";getchar();
}
void funcCreatePlane(){
    cout<<"\n!funcCreatePlane!\n";getchar();
}
void funcCreateFlight(){
    cout<<"\n!funcCreateFlight!\n";getchar();
}
void funcCreateService(){
    cout<<"\n!funcCreateService!\n";getchar();
}
void funcCreateTicket(){
    cout<<"\n!funcCreateTicket!\n";getchar();
}


void funcReadPassenger(){
    manager.showSortedPassengers();
}
void funcReadPlane(){
    cout<<"\n!funcReadPlane!\n";getchar();
}
void funcReadFlight(){
    manager.showSortedFlights(); // TODO: in here we will have to ask in what order to sort
                                    // TODO: tb temos de ver a questão das listagens várias

}
void funcReadService(){
    cout<<"\n!funcReadService!\n";getchar();
}
void funcReadTicket(){
    cout<<"\n!funcReadTicket!\n";getchar();
}


void funcUpdatePassanger(){
    cout<<"\n!funcUpdatePassanger!\n";getchar();
}
void funcUpdatePlane(){
    cout<<"\n!funcUpdatePlane!\n";getchar();
}
void funcUpdateFlight(){
    cout<<"\n!funcUpdateFlight!\n";getchar();
}
void funcUpdateService(){
    cout<<"\n!funcUpdateService!\n";getchar();
}
void funcUpdateTicket(){
    cout<<"\n!funcUpdateTicket!\n";getchar();
}


void funcDeletePassanger(){
    cout<<"\n!funcDeletePassanger!\n";getchar();
}
void funcDeletePlane(){
    cout<<"\n!funcDeletePlane!\n";getchar();
}
void funcDeleteFlight(){
    cout<<"\n!funcDeleteFlight!\n";getchar();
}
void funcDeleteService(){
    cout<<"\n!funcDeleteService!\n";getchar();
}
void funcDeleteTicket(){
    cout<<"\n!funcDeleteTicket!\n";getchar();
}

vector<void (*)()>  createFuncs = {funcCreatePassanger,funcCreatePlane,funcCreateFlight,funcCreateService,funcCreateTicket};
vector<void (*)()>  readFuncs = {funcReadPassenger, funcReadPlane, funcReadFlight, funcReadService, funcReadTicket};
vector<void (*)()>  updateFuncs = {funcUpdatePassanger,funcUpdatePlane,funcUpdateFlight,funcUpdateService,funcUpdateTicket};
vector<void (*)()>  deleteFuncs = {funcDeletePassanger,funcDeletePlane,funcDeleteFlight,funcDeleteService,funcDeleteTicket};


//___________________________TEMPORARY_TESTING_______________________________






string trimStr(string str){
    str.erase(0, str.find_first_not_of(' '));
    str.erase(str.find_last_not_of(' ')+1);
    return str;
}

bool emptyCin() {
    string bufferContent;
    getline(cin, bufferContent);
    trimStr(bufferContent);
    if (bufferContent.empty())
        return true;
    return false;
}

void giveMenuInputError(string &s){
    s =  "\nInvalid input was given.\nPlease provide a number from the menu.\n\n";
}


void subMenu(const string& menuTitle,vector<void (*)()> funcs) {
    char userInput;
    string inputError;

    while (true) {
        system(CLEAR);

        if(!inputError.empty())
            cout<<inputError;
        inputError = "";

        //Start of MENU
        cout << "=================" << endl;
        cout << menuTitle<< endl;
        cout << "=================" << endl;
        cout << "  1)  Passanger" << endl;
        cout << "  2)  Plane" << endl;
        cout << "  3)  Flight" << endl;
        cout << "  4)  Service" << endl;
        cout << "  5)  Ticket" << endl;
        cout << "  6)  Go Back" << endl;
        cout << "  0)  Exit" << endl;
        cout << "================" << endl;
        cout << " > ";
        //End of MENU

        if ((cin >> userInput))
        {
            //raises error if more than 1 char is written by user
            if (!emptyCin()) {
                giveMenuInputError(inputError);
                continue;
            }

            //START OF MENU SELECTION
            switch (userInput)
            {
                case '0'://EXIT
                    cout<<"End of program.\n";
                    exit(1);

                case '1'://Passanger
                    funcs[0]();
                    break;
                case '2'://Plane
                    funcs[1]();
                    break;
                case '3'://Flight
                    funcs[2]();
                    break;
                case '4'://Service
                    funcs[3]();
                    break;
                case '5'://Ticket
                    funcs[4]();
                    break;
                case '6'://Go Back
                    goto END_MENU;
                default:
                    giveMenuInputError(inputError);
                    break;
            }
            //END OF MENU SELECTION
            continue;
        }else
        {
            //deals with errors when trying to get the char
            if (cin.eof()){
                cout<<"\nEnd of program.\n";
                exit(1); //detects CTRL+Z
            }

            cin.clear();cin.ignore(1000, '\n');
            giveMenuInputError(inputError);
            continue;
        }

        END_MENU:break;
    }
}


void mainMenu() {
    char userInput;
    string inputError;

    while (true) {
        system(CLEAR);

        if(!inputError.empty())
            cout<<inputError;
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

        if ((cin >> userInput))
        {
            //raises error if more than 1 char is written by user
            if (!emptyCin()) {
                giveMenuInputError(inputError);
                continue;
            }

            //START OF MENU SELECTION
            switch (userInput)
            {
                case '0'://EXIT
                    cout<<"End of program.\n";
                    exit(1);
                case '1'://CREATE
                    subMenu("   CREATE MENU",createFuncs);
                    break;
                case '2'://READ
                    subMenu("    READ MENU",readFuncs);
                    break;
                case '3'://UPDATE
                    subMenu("   UPDATE MENU",updateFuncs);
                    break;
                case '4'://DELETE
                    subMenu("   DELETE MENU",deleteFuncs);
                    break;
                default:
                    giveMenuInputError(inputError);
                    break;
            }
            //END OF MENU SELECTION

            continue;

        }else
        {
            //deals with errors when trying to get the char
            if (cin.eof()){
                cout<<"\nEnd of program.\n";
                exit(1); //detects CTRL+Z
            }

            cin.clear();cin.ignore(1000, '\n');
            giveMenuInputError(inputError);
            continue;
        }
    }
}
#endif
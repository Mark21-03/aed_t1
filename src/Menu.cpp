#include "../include/Menu.h"





bool Menu::MenuOperationConfirm(){
    char confirm;

    cout<<"\nConfirm? (Y/N): ";cin>>confirm;

    if(confirm == 'Y' || confirm == 'y')
        return true;
    else
        cout<<"Canceled. Press any key to continue... ";

    return false;
}


//_________________________________________________________________________________


void Menu::funcCreatePassenger() {
    string pName;
    cout<<"\nNew Passenger Name (string): ";getline(cin,pName);

    if (MenuOperationConfirm()) {
        manager.createPassenger(pName);
        cout << "Passenger added!\n";
    }
    getchar();getchar();
}

void Menu::funcCreatePlane() {
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


void Menu::funcCreateFlight() {

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


void Menu::funcCreateService() {
    //TODO
    cout << "\n!funcCreateService!\n";
    getchar();
}

void Menu::funcCreateTicket() {
    /*
    //TODO temporarly made this a transport tester
    cout << "\n!funcCreateTicket!\n";
    getchar();
     */
    cout<<endl<<"This function is temporarly holding a Transport add/viewer to BST"<<endl;
    Transport t;
    cout<<"\nTRANSPORT = ";cin>>t; // char float
    manager.transportsTree.insert(t);

    cout<<endl;
    manager.transportsTree.printTree();
    cout<<endl;

    getchar();getchar();
}



//_________________________________________________________________________________


void Menu::funcUpdatePassenger() {
    int n=funcUpdateAll();
    manager.searchPassengers(n);
}



void Menu::funcUpdatePlane() {
    string id;
    cout<<"Plate number of the plane to change: ";
    cin>>id;
    manager.searchPlanes(id);

}

void Menu::funcUpdateFlight() {
    int n=funcUpdateAll();
    manager.searchFlights(n);
}

void Menu::funcUpdateService(){}
void Menu::funcUpdateTicket(){}

int Menu::funcUpdateAll(){
    int id;
    cout<<"ID of object to change?";
    cin>>id;
    return id;
}

//_________________________________________________________________________________


void Menu::funcDeletePassenger() {

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

void Menu::funcDeletePlane() {

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



void Menu::funcDeleteFlight() {

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

void Menu::funcDeleteService() {
    //TODO
    int id2Delete;
    cout<<"\nID to be deleted: ";cin>>id2Delete;

    if(MenuOperationConfirm()){

    }
    getchar();getchar();
}


void Menu::funcDeleteTicket() {
    //TODO
    int id2Delete;
    cout<<"\nID to be deleted: ";cin>>id2Delete;

    if(MenuOperationConfirm()){
        cout<<"Deleted!\n";
    }
    getchar();getchar();
}

//_________________________________________________________________________________



void Menu::funcReadPassenger() {
    unsigned int minID, maxID;
    out::askInterval<unsigned int>(cout, cin, minID, maxID, "Passenger ID");
    manager.showSortedPassengersByID(cout, minID, maxID);
    getchar();getchar();

}

void Menu::funcReadPlane() {
    planePlate min, max;
    out::askInterval<planePlate>(cout, cin, min, max, "Plate Number");
    manager.showSortedPlanes(cout, min, max);
    getchar();getchar();
}

void Menu::funcReadFlight() {
    flightNumber min, max;
    out::askInterval<flightNumber>(cout, cin, min, max, "Flight number");
    manager.showSortedFlightsByID(cout, min, max);
    getchar();getchar();

}

void Menu::funcReadService() {
    Date min, max;
    std::string option;
    out::askOnce<std::string>(cout,cin, option, "Option(d->Done, t->toDo)");

    if (option == "d") {
        out::askInterval<Date>(cout, cin, min, max, "Date");

        manager.showDoneServices(cout, min, max);
    } else if(option == "t") {
        out::askInterval<Date>(cout, cin, min, max, "Date");
        manager.showToDoServices(cout, min, max);
    } else {
        std::cout << "Not a valid Option";
    }
    getchar();getchar();

}

void Menu::funcReadTicket() {
    //TODO
    cout << "\n!funcReadTicket!\n";
    getchar();
}

//_________________________________________________________________________________


void Menu::subMenu(const string &menuTitle, vector<void (Menu::*)()> funcs) {
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


//_________________________________________________________________________________

void Menu::readSubMenu(string menuTitle,vector<void (Menu::*)()> funcs){

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


//_________________________________________________________________________________

void Menu::mainMenu() {
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
















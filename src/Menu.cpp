#include "../include/Menu.h"





bool Menu::menuOperationConfirm(){
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

    if (menuOperationConfirm()) {
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


    if (menuOperationConfirm()) {
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

    cout<<"\nNew Flight's departure date (YYYY/MM/DD): ";cin>>departureD;
    cout<<"New Flight's time (HH:MM:SS): ";cin>>departureT;
    cout<<"New Flight's duration (float): ";cin>>duration;
    cout<<"New Flight's origin (string): "; cin.ignore();getline(cin,origin);
    cout<<"New Flight's destiny (string): "; getline(cin,destiny);

    if (menuOperationConfirm()) {
        manager.createFlight(departureD,departureT,duration,origin,destiny);
        cout<<"\nFlight added!\n";
    }

    getchar();getchar();
}


void Menu::funcCreateService() {
    char newType;
    Date newDate;
    string newEmployeeName,newPlate;

    cout<<"\nNew Service's Type (M / C / O): ";cin>>newType;
    cout<<"New Service's Date (YYYY/MM/DD): ";cin>>newDate;
    cout<<"New Service's Employee Name (string): "; cin.ignore();getline(cin,newEmployeeName);
    cout<<"New Service's Plane Plate (string): ";getline(cin,newPlate);


    if (menuOperationConfirm()) {
        serviceManager->addToDoService(Service(newType,newDate, newEmployeeName, newPlate));

        cout << "\nService added!\n";
    }
    getchar();getchar();
}

void Menu::funcCreateTicket() {
    //TODO
    cout << "\n!funcCreateTicket!\n";
    getchar();

}



//_________________________________________________________________________________


void Menu::funcUpdatePassenger() {
    int n = askChangeId();
    cout<<endl;
    manager.searchUpdatePassengers(n);
    getchar();getchar();
}


void Menu::funcUpdatePlane() {
    string id;
    cout<<"\nPlate number of the plane to change: ";
    cin>>id;
    cout<<endl;
    manager.searchUpdatePlanes(id);
    getchar();getchar();

}

void Menu::funcUpdateFlight() {
    int n = askChangeId();
    cout<<endl;
    manager.searchUpdateFlights(n);
    getchar();getchar();
}

void Menu::funcUpdateService(){}
void Menu::funcUpdateTicket(){}

int Menu::askChangeId(){
    unsigned id;
    cout<<"\nWhich id do you want to change: ";
    cin>>id;
    return id;
}

//_________________________________________________________________________________


void Menu::funcDeletePassenger() {

    int id2Delete;
    cout<<"\nID to be deleted: ";cin>>id2Delete;

    cout<<endl;
    manager.showSortedPassengersById(cout, id2Delete, id2Delete);

    if(menuOperationConfirm()){
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
    manager.showSortedPlanesById(cout, id2Delete, id2Delete);

    if(menuOperationConfirm()){
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
    manager.showSortedFlightsById(cout, id2Delete, id2Delete);

    if(menuOperationConfirm()){
        bool deleted = manager.deleteFlight(id2Delete);
        if(deleted)
            cout<<"Deleted!\n";
        else
            cout<<"Value not found!\n";
    }
    getchar();getchar();
}

void Menu::funcDeleteService() {
    //TODO não funciona por causa do char type que esta em ascii

    char newType;
    Date newDate;
    string newEmployeeName,newPlate;

    cout<<"\nService's Type (M / C / O): ";cin>>newType;
    cout<<"Service's Date (YYYY/MM/DD): ";cin>>newDate;
    cout<<"Service's Employee Name (string): "; cin.ignore();getline(cin,newEmployeeName);
    cout<<"Service's Plane Plate (string): ";getline(cin,newPlate);

    cout<<endl;

    Service findService(newType,newDate,newEmployeeName,newPlate);

    bool found = serviceManager->findTodoService(findService);

    if(found){
        cout<<"\nFound a match!\n";
        if(menuOperationConfirm()){
            bool deleted = serviceManager->deleteTodoService(findService);
            if(deleted)
                cout<<"Deleted!\n";
            else
                cout<<"Value not found!\n";
        }
    }else
        cout<<"Value not found!\n";

    getchar();
}


void Menu::funcDeleteTicket() {
    //TODO
    int id2Delete;
    cout<<"\nID to be deleted: ";cin>>id2Delete;

    if(menuOperationConfirm()){
        cout<<"Deleted!\n";
    }
    getchar();getchar();
}

//_________________________________________________________________________________



void Menu::funcReadPassenger() {
    std::string option;
    out::askOnce<std::string>(cout,cin, option, "Option(n->Search by Name, i->Search by ID)");
    if (option == "i") {
        unsigned int minId, maxId;
        out::askInterval<unsigned int>(cout, cin, minId, maxId, "Passenger ID");
        manager.showSortedPassengersById(cout, minId, maxId);
        getchar();
        getchar();
    } else if (option == "n") {
        std::string searchName;
        cout << "Give us a part of the Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, searchName);
        regex search(".*" + searchName + ".*");
        cout<<endl;

        bool foundMatch = manager.searchPassengerId(cout, search);
        cout << SEPARATION << std::endl;
        if(!foundMatch) cout<<"X\tNo match was found!\n";
        getchar();
    }
}

void Menu::funcReadPlane() {
    std::string option;
    out::askOnce<std::string>(cout,cin, option, "Option(p->Plate Number, t->Plane type)");

    if (option == "p") {
        planePlate min, max;
        out::askInterval<planePlate>(cout, cin, min, max, "Plate Number");
        cout << endl;
        manager.showSortedPlanesById(cout, min, max);
        getchar();
        getchar();
    }else if (option == "t") {
        std::string min;
        out::askOnce<std::string>(cout, cin, min, "Plate Type");
        cout << endl;
        manager.showSortedPlanesOfType(cout, min);
        getchar();
        getchar();
    }
}

void Menu::funcReadFlight() {
    flightNumber min, max;
    out::askInterval<flightNumber>(cout, cin, min, max, "Flight number");
    manager.showSortedFlightsById(cout, min, max);
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
        int ignoreVar = system(CLEAR);

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
        int ignoreVar = system(CLEAR);

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
        int ignoreVar = system(CLEAR);

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
        cout << "  5)  Others" << endl;
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
                case '5'://OTHERS
                    othersSubMenu();
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


void Menu::othersFunc1() {
    cout<<"\nOTHER FUNC 1\n";
    getchar();
}

void Menu::othersFunc2() {
    cout<<"\nOTHER FUNC 2\n";
    getchar();
}

void Menu::othersFunc3() {
    cout<<"\nOTHER FUNC 3\n";
    getchar();
}

void Menu::othersFunc4() {
    cout<<"\nOTHER FUNC 4\n";
    getchar();
}

void Menu::othersFunc5() {
    cout<<"\nOTHER FUNC 5\n";
    getchar();
}


void Menu::othersSubMenu() {

    char userInput;
    string inputError;


    while (true) {
        int ignoreVar = system(CLEAR);

        if (!inputError.empty())
            cout << inputError;
        inputError = "";

        //Start of MENU

        cout << "================="<< endl;
        cout << "   OTHERS MENU" << endl;
        cout << "=================" << endl;
        cout << "  1)  X" << endl;
        cout << "  2)  X" << endl;
        cout << "  3)  X" << endl;
        cout << "  4)  X" << endl;
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

                case '1':
                    othersFunc1();
                    break;
                case '2':
                    othersFunc2();
                    break;
                case '3':
                    othersFunc3();
                    break;
                case '4':
                    othersFunc4();
                    break;
                case '5':
                    othersFunc5();
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
















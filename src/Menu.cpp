#include "../include/Menu.h"


void Menu::saveDataFiles(){
    cout << "\nEnd of program.\n";
    manager.saveToFile();
    std::cout<<"Data saved.";
    getchar();
}



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
    string pName; Date birth;
    cout<<"\nNew Passenger Name (string): ";getline(cin,pName);
    cout<<"\nNew Passenger Birth (YYYY/MM/DD): ";cin>>birth;

    if (menuOperationConfirm()) {
        manager.createPassenger(pName, birth);
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

    cout<<"\nNew Service's Type (m | c | o): ";cin>>newType;
    cout<<"New Service's Date (YYYY/MM/DD): ";cin>>newDate;
    cout<<"New Service's Employee Name (string): "; cin.ignore();getline(cin,newEmployeeName);
    cout<<"New Service's Plane Plate (string): ";getline(cin,newPlate);


    if (menuOperationConfirm()) {
        serviceManager->addToDoService(Service(newType,newDate, newEmployeeName, newPlate));

        cout << "\nService added!\n";
    }
    getchar();getchar();
}

void Menu::BuyTicket() {
    flightNumber flight;
    int passengerID;
    float price;
    char tClass;
    int quant;

    cout<<"\nNumber of tickets: "; cin>>quant;

    cout << "\nNew Ticket's Flight number: "; cin >> flight;

    auto p = manager.getFlightByNumber(flight);
    if (p->getOccupation() + quant > p->getMaxCapacity()) {
        cout << "Sorry, the flight has max capacity of " << p->getMaxCapacity() << '\n';
        cout << "There is only " << p->getMaxCapacity() - p->getOccupation()<< " tickets left" << '\n';
        getchar();getchar();
        return;
    }

    int sold=0;

    while (quant>sold) {
        cout << "New Ticket's Passenger ID : "; cin >> passengerID;
        cout << "New Ticket's Class (x | e) : "; cin >> tClass;

        price = 50.0f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX / (500.0f - 50.0f));

        if (menuOperationConfirm()) {
            manager.createTicket(flight, passengerID, price, static_cast<ClassType>(tClass));
            manager.IncrementFlightOccupation(flight);
            sold++;
            cout << "\nTicket(s) "<<sold<<" / "<<quant<<" added!\n";
        } else
           break;
    }
    getchar(); getchar();

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

void Menu::funcUpdateService(){
    Date date=askDateService();
    char type=askTypeService();
    planePlate plate=askPlateService();
    string emp=askEmployeeService();
    manager.searchUpdateServices(type,date,emp,plate);
    getchar();getchar();
}

int Menu::askChangeId(){
    unsigned id;
    cout<<"\nWhich id do you want to change: ";
    cin>>id;
    return id;
}

Date Menu::askDateService() {
    Date date;
    cout<<"\nWhat date was the service: ";
    cin>>date;
    return date;
}

char Menu::askTypeService() {
    char type;
    cout<<"\nWhat type was the service: ";
    cin>>type;
    //if (type=='m' || type=='c' || type=='o')
    return type;
    //else cout<<"Invalid type";
}

planePlate Menu::askPlateService() {
    planePlate plate;
    cout<<"\nWhat's the plate of the plane where the service happened: ";
    cin>>plate;
    return plate;
}

string Menu::askEmployeeService() {
    string emp;
    cout<<"\nName of employee in the service: ";
    cin.ignore();
    getline(cin,emp);
    return emp;
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

    char newType;
    Date newDate;
    string newEmployeeName,newPlate;

    cout<<"\nService's Type (m | c | o): ";cin>>newType;
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
                cout<<"Value not Found!\n";

        }getchar();
    }else
        cout<<"Value not found!\n";

    getchar();
}




//_________________________________________________________________________________



void Menu::funcReadPassenger() {
    std::string option;
    out::askOnce<std::string>(cout,cin, option, "Option(n->Search by Name, i->Search by ID)");
    if (option == "i") {
        unsigned int minId, maxId;
        std::string sortOption;
        out::askOnce<std::string>(cout,cin, sortOption, "Sort by (n->name, d->birthdate, default = id)");
        out::askInterval<unsigned int>(cout, cin, minId, maxId, "Passenger ID");
        manager.showSortedPassengersBySortOption(cout, sortOption, minId, maxId);
        getchar();
        getchar();
    } else if (option == "n") {
        regex search = out::askParts(cout,cin, "Give us a part of the Name: ");

        bool foundMatch = manager.searchPassengerId(cout, search);
        cout << SEPARATION << SEPARATION<< SEPARATION <<std::endl;
        if(!foundMatch) cout<<"X\tNo match was found!\n";
        getchar();

    }

}

void Menu::funcReadPlane() {
    std::string option;
    out::askOnce<std::string>(cout,cin, option, "Option(p->Plate Number, t->Plane type)");

    if (option == "p") {
        planePlate min, max;
        std::string sortOption;
        out::askOnce<std::string>(cout,cin, sortOption, "Sort by (t->type, c->cap.,n->nr.flights, default = plateNumber)");
        out::askInterval<planePlate>(cout, cin, min, max, "Plate Number");
        cout << endl;
        manager.showSortedPlanesBySortedOption(cout, sortOption, min, max);
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
    std::string option;
    out::askOnce<std::string>(cout,cin, option, "Option(i->id, o->search origin, d->search destiny)");

    if (option == "i") {
        flightNumber min, max;
        std::string sortOption;
        out::askOnce<std::string>(cout,cin, sortOption, "Sort by (o->ocup., d->date, t->time, default = id)");
        out::askInterval<flightNumber>(cout, cin, min, max, "Flight number");
        manager.showSortedFlightsBySortOption(cout, sortOption, min, max);
        getchar();
        getchar();
    } else if (option == "o") {
        std::string sortOption;
        out::askOnce<std::string>(cout,cin, sortOption, "Sort by (o->ocup., d->date, t->time, default = id)");

        regex search = out::askParts(cout,cin, "Give us a part of the airport origin name: ");

        bool foundMatch = manager.searchFlightsOrigins(cout, search, sortOption);
        if(!foundMatch) cout<<"X\tNo match was found!\n";
        getchar();
    } else if (option == "d") {
        std::string sortOption;
        out::askOnce<std::string>(cout,cin, sortOption, "Sort by (o->ocup., d->date, t->time, default = id)");

        regex search = out::askParts(cout,cin, "Give us a part of the airport destiny name: ");

        bool foundMatch = manager.searchFlightsDestiny(cout, search, sortOption);
        if(!foundMatch) cout<<"X\tNo match was found!\n";
        getchar();
    }

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
        cout << "  5)  Transports" << endl;
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
                    saveDataFiles();
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
                case '5'://Transports
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
                    saveDataFiles();
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


void Menu::showNearbyTransports() { // TODO: CHANGE THIS

    std::string airport;

    cout << "\nWhat airport are you in: ";getline(cin, airport);

    cout<<endl;

    out::headerTransports(cout);

    if (!manager.showAirportTransports(cout, airport)) {
        cout << "Not available\n";
    }
    getchar();
}

void Menu::addNewTransport() {
    char c;float d;

    std::string airport;
    cout << "\nAirport to add Transport: "; getline(cin, airport);

    cout<<"\nNew Transport Type (T, S, B): ";cin>>c; // TODO: CHECK IF INPUT IS CORRECTED
    cout<<"New Transport Distance (float): ";cin>>d;

    Transport t(c,d);


    auto generateRandomTimeTable = [=](){
        Time t;
        set<Time> s;

        int numTimes = rand()%10+5;

        for(int i = 0; i<numTimes;i++){
            t.setRandomTime();
            s.insert(t);
        }
        return s;
    };

    t.setTimeTable(generateRandomTimeTable());

    if(menuOperationConfirm()) {
        if(manager.addTransportToAirport(cout, airport, t))
            cout<<"Added new Transport!\n";
        else
            cout << "Airport or transport is incorrect.\nYou can only add a transport to a operable airport.\n";
    }

    getchar(); getchar();
}

void Menu::removeNearbyTransport() {

    char c;float d;
    std::string airport;
    cout << "\nAirport to remove Transport: ";getline(cin, airport);

    cout<<"\nTransport Type (T, S, B): ";cin>>c;
    cout<<"Transport Distance (float): ";cin>>d;

    Transport t(c,d);

    if (menuOperationConfirm() && !manager.removeTransportInAirport(cout, airport, t))
        cout << "No airport has that name.\n";

    getchar(); getchar();

}

void Menu::updateTransports() {
    char c;float d;
    std::string airport;
    cout << "Airport to update Transport ? :" << endl << '>';
    getline(cin, airport);
    cout<<"\nTransport Type (T, S, B): ";cin>>c;
    cout<<"Transport Distance (float): ";cin>>d;

    Transport t(c,d);

    if (menuOperationConfirm() && !manager.updateTransportInAirport(cout, airport, t))
        cout << "No airport has that Name.\n";

    getchar(); getchar();
}

void Menu::doCheckIn() {
    int flightID;
    cout<<"\nFlight ID to Check In: ";cin>>flightID;

    Flight* ptr = manager.getFlightByNumber(flightID);
    bool foundFlight = ptr != nullptr;

    if(foundFlight){

        manager.makeCheckIn(flightID);

    }else cout<<"\nFlight ID not found!\n";


    getchar();getchar();
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

        cout << "==============================="<< endl;
        cout << "          OTHERS MENU" << endl;
        cout << "===============================" << endl;
        cout << "  1)  Check In" << endl;
        cout << "  2)  Buy ticket" << endl;
        cout << "  3)  Go Back" << endl;
        cout << "  0)  Exit" << endl;
        cout << "===============================" << endl;
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
                    saveDataFiles();
                    exit(1);
                case '1':
                    doCheckIn();
                    break;
                case '2':
                    BuyTicket();
                    break;
                case '3'://Go Back
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















#include <algorithm>
#include "../include/Manager.h"

void Manager::setPaths(){
    ifstream dirs(filesDir);

    getline(dirs, flightsPath);
    getline(dirs, planesPath);
    getline(dirs, passengersPath);
    getline(dirs, servicePath);
    getline(dirs, transportsPath);
    getline(dirs, tickets_path);
}


Manager::Manager() {

    setPaths();

    readFlights();
    readPassengers();
    readPlanes();
    readServices();
    readTransports();
    readTickets();

    serviceManager = ServiceManagement(servicePath);
}


void Manager::showSortedPassengersById(ostream &ostream1, unsigned int min, unsigned int max) {

    out::headerPassengers(ostream1);

    auto it = lower_bound(passengers.begin(),passengers.end(), Passenger(min, ""));
    for (;it!=passengers.end();it++) {
        if (it->getID() > max) break;
        out::passenger(ostream1,it);
    }

}

void Manager::showSortedFlightsById(ostream &ostream1, flightNumber min , flightNumber max) {

    out::headerFlights(ostream1);
    auto it = lower_bound(flights.begin(), flights.end(), Flight(min, Date(), Time(),2.4f, "", ""));

    for (;it!=flights.end();it++) {
        if (it->getNumber() > max) break;
        out::flights(ostream1,it);
    }
}


void Manager::showSortedPlanesById(ostream &ostream1, const planePlate& min, const planePlate& max) {

    out::headerPlanes(ostream1);
    auto it = lower_bound(planes.begin(), planes.end(), Plane(min,"",0));

    for (;it!=planes.end();it++) {
        if (it->getNumberPlate() > max) break;
        out::planes(ostream1,it);
    }
}

void Manager::showSortedPlanesOfType(ostream &ostream1, const std::string & min) {
    out::headerPlanes(ostream1);
    auto it = planes.begin();

    for (;it!=planes.end();it++) {
        if (it->getType() == min)
            out::planes(ostream1,it);
    }
}



void Manager::readFlights() {
    std::ifstream ifs_flights(flightsPath);

    Flight flight;
    while (ifs_flights >> flight) {
        flights.push_back(flight);
    }

    ifs_flights.close();
}

void Manager::readPlanes() {
    std::ifstream ifs_planes(planesPath);

    Plane plane;
    while (ifs_planes >> plane) {
        planes.push_back(plane);
    }

    ifs_planes.close();
}

void Manager::readPassengers() {
    std::ifstream ifs_passengers(passengersPath);


    Passenger passenger;
    while (ifs_passengers >> passenger) {
        passengers.push_back(passenger);
    }

    ifs_passengers.close();
}

void Manager::readServices() {
    this->serviceManager = ServiceManagement(servicePath);
}

void Manager::showDoneServices(ostream &ostream1, const Date &min, const Date &max) {
    serviceManager.showDoneServicesFromRange(ostream1, min, max);
}

bool Manager::confirmationPrompt(){
    char confirm;

    cout<<"\nConfirm? (Y/N): ";cin>>confirm;

    if(confirm == 'Y' || confirm == 'y')
        return true;
    else
        cout<<"Canceled. Press any key to continue... \n";

    return false;

}


Manager::~Manager() {

    // TODO: CREATE "SAVE" METHODS
    std::ofstream ofsPlanes(planesPath);
    std::ofstream ofsPassengers(passengersPath);
    std::ofstream ofsFlights(flightsPath);
    std::ofstream ofsTransports(transportsPath);
    std::ofstream ofsTickets(tickets_path);

    for(Plane &p:planes)
        ofsPlanes << p;

    for(Passenger &p:passengers)
        ofsPassengers << p;

    for(Flight &f:flights)
        ofsFlights << f;

    for(auto it= transportsTree.begin();it!=transportsTree.end();it++)
        ofsTransports << (*it).getType()<<" "<<(*it).getDistance()<<" "<<(*it).getTimeTable().size()<<" "<<(*it).getTimeTable()<<endl;

    for (auto & t: tickets) {
        ofsTickets << t;
    }

    ofsPlanes.close();
    ofsFlights.close();
    ofsPassengers.close();
    ofsTransports.close();
    ofsTickets.close();

    serviceManager.saveToFile();

}


void Manager::searchUpdatePassengers(int SearchedID) {

    auto finder = [=](const Passenger &p){
        return p.getID() == SearchedID;
    };

    auto it = find_if(passengers.begin(),passengers.end(),finder);

    if(it!=passengers.end()){
        string newName;
        showSortedPassengersById(cout, SearchedID, SearchedID);
        cout<<"\nProvided the new values below:\n";
        cout<<"\nName: ";cin.ignore();getline(cin,newName);


        cout<<endl;
        if(confirmationPrompt()){
            it->setName(newName);
            cout<<"\nChanges have been saved!\n";
        }
    }
    else
        cout<<"The given ID doesn't match any passenger.";
}

void Manager::searchUpdateFlights(int SearchedID) {

    auto finder = [=](const Flight &f){return SearchedID == f.getNumber();};

    auto it = find_if(flights.begin(),flights.end(),finder);


    if(it!=flights.end()){
        showSortedFlightsById(cout, SearchedID, SearchedID);
        cout<<"\nProvided the new values below:\n";

        Date deparDate;
        Time deparTime;
        float duration;
        int occupation;
        std::string origin,destiny;

        cout<<"Departure Date (YYYY/MM/DD): ";cin>>deparDate;
        cout<<"Departure Time (HH:MM:SS): ";cin>>deparTime;
        cout<<"Duration (float): ";cin>>duration;
        cout<<"Origin (string): "; cin.ignore();getline(cin,origin);
        cout<<"Destiny (string): "; getline(cin,destiny);

        if(confirmationPrompt()){
            it->setDepartureDate(deparDate);
            it->setDepartureTime(deparTime);
            it->setDuration(duration);
            it->setOrigin(origin);
            it->setDestiny(destiny);

            cout<<"\nChanges have been saved!\n";
        }

    }else
        cout<<"The given ID doesn't match any flight.";


}

void Manager::searchUpdatePlanes(const string& searchedPlate){

    auto finder = [=](const Plane &p){
        return p.getNumberPlate() == searchedPlate;
    };

    auto it = find_if(planes.begin(),planes.end(),finder);

    if(it!=planes.end()){
        string newType, newCapacity;
        showSortedPlanesById(cout,searchedPlate, searchedPlate);
        cout<<"\nProvided the new values below:";
        cout<<"\nType: ";cin.ignore();getline(cin,newType);
        cout<<"\nCapacity: ";getline(cin,newCapacity);

        cout<<endl;
        if(confirmationPrompt()){
            it->setType(newType);
            it->setCapacity(stoi(newCapacity));
            cout<<"\nChanges have been saved!\n";
        }
    }
    else{

        cout<<"\nThe given plate doesn't match any plane.\n";
    }

}

void Manager::searchUpdateServices(char type, Date date, string emp, planePlate plate){
    char type1;
    Date date1;
    string employer1;
    planePlate plane1;

    //queue<Service> q1=serviceManager.getToDoServices();
    //vector<Service> apoio;
    Service findService(type, date, emp, plate);

    bool found = serviceManager.findTodoService(findService);

    if (found){
        serviceManager.deleteTodoService(findService);
        cout << "\nProvide the new values below:";
        cout << "\nEmployer: ";getline(cin, employer1);
        cout << "Date: ";cin >> date1;
        cout << "Type: ";cin >> type1;
        cout << "Plane plate: ";cin >> plane1;

        cout << endl;
        if (confirmationPrompt()) {
            Service newService(type1, date1, employer1, plane1);
            serviceManager.addToDoService(newService);
            cout << "\nChanges have been saved!\n";
        }
    }
    else{

        cout<<"The given information doesn't match any service.\n";

    }

}


void Manager::createPassenger(const string &Pname){ // TODO: THE ID SHOULD NOT BE THE BACK + 1 BUT THE LAST CREATED + 1

    unsigned newID = passengers.back().getID()+1;

    Passenger p(newID, Pname);

    passengers.push_back(p);
}

void Manager::createPlane(const planePlate &numberPlate, const string &pType, int capacity) {

    Plane p(numberPlate, pType, capacity);

    //TODO talvez seja sorted por matricula ?
    planes.push_back(p);
}

void Manager::createFlight( const Date &departureDate, const Time &departureTime, const float &duration, std::string origin, std::string destiny) {

    unsigned newID = flights.back().getNumber() + 1;
    Flight f(newID, departureDate, departureTime, duration, origin, destiny);

    flights.push_back(f);

}

void Manager::createTicket(int flight, int passengerID, float price, bool baggage, ClassType tClass) {
    Ticket t(flight,passengerID,price,baggage,tClass);
}
// TODO: WHAT IS THIS ABOVE???
/*Flight Manager::getFlightbyNumber(int number) {
    return flights[number];
}*/





bool Manager::deletePassenger(const unsigned int &idD) {

    auto filter = [=](const Passenger &p){return p.getID()==idD;};

    auto it = find_if(passengers.begin(),passengers.end(),filter);

    if(it!=passengers.end()){
        passengers.erase(it);return true;
    }
    return false;
}

bool Manager::deletePlane(const string &idD) {

    auto filter = [=](const Plane &p){return p.getNumberPlate()==idD;};

    auto it = find_if(planes.begin(),planes.end(),filter);

    if(it!=planes.end()){
        planes.erase(it);return true;
    }
    return false;

}

bool Manager::deleteFlight(const unsigned int &idD) {

    auto filter = [=](const Flight &p){return p.getNumber()==idD;};

    auto it = find_if(flights.begin(),flights.end(),filter);

    if(it!=flights.end()){
        flights.erase(it);return true;
    }
    return false;

}

void Manager::showToDoServices(ostream &ostream1, const Date &min, const Date &max) {
    serviceManager.showToDoServicesFromRange(ostream1, min, max);
}

bool Manager::searchPassengerId(ostream &ostream1, const regex& exp) {
    out::headerPassengers(ostream1);

    bool foundMatch = false;

    for (auto& p : passengers)
        if(regex_match(p.getName() ,exp)){
            foundMatch = true;out::passenger(ostream1,&p);
        }

    return foundMatch;
}


void Manager::readTransports() {

    std::ifstream ifs_transports(transportsPath);


    Transport transport;
    while (ifs_transports >> transport) {
        transportsTree.insert(transport);
    }

    ifs_transports.close();

}

bool Manager::validBuy(Ticket ticket) {
//    if (ticket.sold<flights[ticket.getFlightNumber()].getOccupation())
  //      return true;
    return false;
}

void Manager::readTickets() {
    std::ifstream ifs_ticket(tickets_path);

    Ticket ticket{};
    while (ifs_ticket >> ticket) {
        tickets.insert(ticket);
    }

    ifs_ticket.close();
}

Flight* Manager::getFlightbyNumber(flightNumber number) { // TODO: CHECK IF IT IS WORKING
    auto it = lower_bound(flights.begin(), flights.end(), Flight(number,Date(), Time(), 1.0f,"",""));

    if (it->getNumber() != number) {
        return nullptr;
    }
    Flight& flight = *it;
    return &flight;
}





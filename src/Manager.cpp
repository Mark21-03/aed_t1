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


void Manager::showSortedPassengersBySortOption(ostream& ostream1, const std::string& sortOption, unsigned int min , unsigned int max) { // TODO CHANGE NAME OF METHOD

    out::headerPassengers(ostream1);

    auto it = lower_bound(passengers.begin(),passengers.end(), Passenger(min, ""));

    vector<Passenger*> vec;
    for (;it!=passengers.end();it++) {
        if (it->getID() > max) break;
        vec.push_back(&(*it));
    }

    if (sortOption == "n") {
        sort(vec.begin(),vec.end(),ComparePassengersByName());
    }else if (sortOption == "d") {
        sort(vec.begin(),vec.end(),ComparePassengersByBirthDate());
    }

    for (auto& pa: vec) {
        out::passenger(ostream1,pa);
    }


}

void Manager::showSortedPassengersById(ostream &ostream1, unsigned int min, unsigned int max) {
    out::headerPassengers(ostream1);

    auto it = lower_bound(passengers.begin(),passengers.end(), Passenger(min, ""));

    for (;it!=passengers.end();it++) {
        if (it->getID() > max) break;
        out::passenger(ostream1,it);
    }

}

void Manager::showSortedFlightsBySortOption(ostream &ostream1, const string &sortOption, flightNumber min, flightNumber max) {
    out::headerFlights(ostream1);

    auto it = lower_bound(flights.begin(),flights.end(), Flight(min, Date(), Time(),0.0f, "", ""));

    vector<Flight*> vec;
    for (;it!=flights.end();it++) {
        if (it->getNumber() > max) break;
        vec.push_back(&(*it));
    }

    if (sortOption == "o") {
        sort(vec.begin(),vec.end(),CompareFlightsByOccupation());
    }else if (sortOption == "d") {
        sort(vec.begin(),vec.end(),CompareFlightsByDepartureDate());
    } else if (sortOption == "t") {
        sort(vec.begin(),vec.end(),CompareFlightsByDepartureTime());
    }

    for (auto& pa: vec) {
        out::flights(ostream1,pa);
    }
}


void Manager::showSortedFlightsById(ostream &ostream1, flightNumber min , flightNumber max) {

    out::headerFlights(ostream1);
    auto it = lower_bound(flights.begin(), flights.end(), Flight(min, Date(), Time(),0.0f, "", ""));

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


void Manager::showSortedPlanesBySortedOption(ostream& ostream1, const std::string& sortOption, const planePlate& min, const planePlate& max) {
    out::headerPlanes(ostream1);

    auto it = lower_bound(planes.begin(),planes.end(), Plane(min,"",0));

    vector<Plane*> vec;
    for (;it!=planes.end();it++) {
        if (it->getNumberPlate() > max) break;
        vec.push_back(&(*it));
    }

    if (sortOption == "t") {
        sort(vec.begin(),vec.end(),ComparePlaneByType());
    }else if (sortOption == "c") {
        sort(vec.begin(),vec.end(),ComparePlaneByCapacity());
    }else if (sortOption == "n") {
        sort(vec.begin(),vec.end(),ComparePlaneByNumberOfFlights());
    }

    for (auto& pa: vec) {
        out::planes(ostream1,pa);
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


void Manager::searchUpdatePassengers(int SearchedID) {

    auto finder = [=](const Passenger &p){
        return p.getID() == SearchedID;
    };

    auto it = find_if(passengers.begin(),passengers.end(),finder);

    if(it!=passengers.end()){
        Date birth;
        string newName;
        showSortedPassengersById(cout, SearchedID, SearchedID);
        cout<<"\nProvided the new values below:\n";
        cout<<"\nName (string): ";cin.ignore();getline(cin,newName);
        cout<<"\nBirth Date (YYYY/MM/DD): ";cin>>birth;


        cout<<endl;
        if(confirmationPrompt()){
            it->setName(newName);
            it->setBirth(birth);
            cout<<"\nChanges have been saved!\n";
        }
    }
    else
        cout<<"The given ID doesn't match any passenger.";
}

/*int Manager::findFlightOccupation(int SearchedID) {

    auto finder = [=](const Flight &f){return SearchedID == f.getNumber();};

    auto it = find_if(flights.begin(),flights.end(),finder);

    if (it!=flights.end())
        return (*it).getOccupation();
}
*/
void Manager::IncrementFlightOccupation(int ID) {
    int prevOccup=flights[ID].getOccupation();
    flights[ID].setOccupation(prevOccup+1);
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


void Manager::createPassenger(const string &Pname, Date birth){ // TODO: THE ID SHOULD NOT BE THE BACK + 1 BUT THE LAST CREATED + 1

    unsigned newID = passengers.back().getID()+1;

    Passenger p(newID, Pname, birth);

    passengers.push_back(p);
}

void Manager::createPlane(const planePlate &numberPlate, const string &pType, int capacity) {

    Plane p(numberPlate, pType, capacity);

    planes.push_back(p);
}

void Manager::createFlight( const Date &departureDate, const Time &departureTime, const float &duration, std::string origin, std::string destiny) {

    unsigned newID = flights.back().getNumber() + 1;
    Flight f(newID, departureDate, departureTime, duration, origin, destiny);

    flights.push_back(f);

}

void Manager::createTicket(int flight, int passengerID, float price, ClassType tClass) {
    //TODO testar e terminar

    //srand(time(NULL)); -> this would create the same baggage all over again
    Baggage bag(rand()%10+5,rand()%3+1);

    Ticket t(flight,passengerID,price,bag,tClass);
    tickets.insert(t);
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
    std::string airport;
    while (getline(ifs_transports,airport)) {
        int n; ifs_transports >> n;
        Transport transport;
        BST<Transport> tTree;
        while (n > 0) {
            ifs_transports >> transport;
            tTree.insert(transport);
            n--;
        }
        airportTransports.insert(pair<std::string, BST<Transport>>(airport, tTree));
        ifs_transports.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    ifs_transports.close();

}

void Manager::readTickets() {
    std::ifstream ifs_ticket(tickets_path);

    Ticket ticket{};
    while (ifs_ticket >> ticket) {
        tickets.insert(ticket);
    }

    ifs_ticket.close();
}

Flight* Manager::getFlightbyNumber(flightNumber number) {
    auto it = lower_bound(flights.begin(), flights.end(), Flight(number,Date(), Time(), 1.0f,"",""));

    if (it->getNumber() != number) {
        return nullptr;
    }
    Flight& flight = *it;
    return &flight;
}

bool Manager::searchFlightsOrigins(ostream &ostream1,const regex &exp,const std::string & sortOption ) {
    out::headerFlights(ostream1);

    bool foundMatch = false;

    vector<Flight* > vec;
    for (auto& f : flights)
        if(regex_match(f.getOrigin() ,exp)){
            foundMatch = true;vec.push_back(&(f));
        }

    if (sortOption == "o") {
        sort(vec.begin(),vec.end(),CompareFlightsByOccupation());
    }else if (sortOption == "d") {
        sort(vec.begin(),vec.end(),CompareFlightsByDepartureDate());
    } else if (sortOption == "t") {
        sort(vec.begin(),vec.end(),CompareFlightsByDepartureTime());
    }

    for (auto & f: vec) {
        out::flights(ostream1,f);
    }

    return foundMatch;
}

bool Manager::searchFlightsDestiny(ostream &ostream1,const regex &exp,const std::string & sortOption) {
    out::headerFlights(ostream1);

    bool foundMatch = false;

    vector<Flight* > vec;
    for (auto& f : flights)
        if(regex_match(f.getDestiny() ,exp)){
            foundMatch = true;vec.push_back(&(f));
        }

    if (sortOption == "o") { // TODO: REPEATED CODE
        sort(vec.begin(),vec.end(),CompareFlightsByOccupation());
    }else if (sortOption == "d") {
        sort(vec.begin(),vec.end(),CompareFlightsByDepartureDate());
    } else if (sortOption == "t") {
        sort(vec.begin(),vec.end(),CompareFlightsByDepartureTime());
    }

    for (auto & f: vec) {
        out::flights(ostream1,f);
    }

    return foundMatch;
}

void Manager::makeCheckIn(int flightID) {

    auto finder = [=](const Ticket& t){
        return t.getFlightNumber() == flightID;
    };

    auto it = find_if(tickets.begin(),tickets.end(),finder);

    if(it!=tickets.end()){
        //actually make Check In
        cout<<"\n\nAll this tickets were a match: \n\n";
        moveBaggageToPlane(flightID);
        cout<<"\nAll baggage are now in the plane!\n";
    }else
        cout<<"\nNo tickets for this flight!\n";

}

void Manager::moveBaggageToPlane(int flightID) {

    auto finder = [=](const Ticket& t){
        return t.getFlightNumber() == flightID;
    };

    auto it = find_if(tickets.begin(),tickets.end(),finder);

    BaggageCheckIn bci(4,5,10);


    cout<<"Flight ID\t"<<"Passenger ID\t"<<"Price\t  "<<"Class\t\t\t"<<"Baggage\t\n";
    cout<<SEPARATION<<"-----------------------------------"<<endl;

    auto printBaggage = [](const Baggage& b){
        return to_string(b.getQuantity())+" baggage with "+to_string((int)b.getWeight())+ " kg";
    };

    auto classSeatPrinter = [](int c){
        char a = (char)c;
        if(a == 'e') return "Economic";
        return "Executive";
    };

    while(it->getFlightNumber()==flightID){
        cout<<it->getFlightNumber()<<"\t\t"<<it->getPassengerID()<<"\t\t"<<it->getPrice();
        cout<<"\t  "<<classSeatPrinter(it->getTClass())<<"\t\t"<<printBaggage(it->getBaggage())<<endl;

        bci.queueAdd(it->getBaggage());

        it++;
    }
    cout<<"\nMoving all corresponding baggage through the conveyor belt...\n";getchar();getchar();

    while(bci.getQueueSize()>0){
        if(bci.isTruckFull()){
            cout<<"\nTruck can't take so many bags!\n";break;
        }
        bci.passNextBagaggeToTruck();
    }

    cout<<"\nPassing baggage from conveyor belt to the baggage truck...\n";getchar();

    auto FlightFinder = [=](const Flight & f){
        return f.getNumber() == flightID;
    };

    auto flightIter = find_if(flights.begin(),flights.end(),FlightFinder);

    Baggage aux;

    while(!bci.getTruck().isEmpty()){
       aux = bci.truckTakeBaggage();
        flightIter->addBaggage2Flight(aux);
    }

    cout<<"\nMoving baggage from truck to the plane...\n";getchar();

}

bool Manager::showAirportTransports(ostream & os,const string &airport) {

    if (airportTransports.count(airport)) {
        auto bst = airportTransports[airport];

        BSTItrIn<Transport> it(bst);
        while (!it.isAtEnd()){
            out::transports(os,&it.retrieve());
            it.advance();
        }
        return true;
    }

    return false;
}

bool Manager::addTransportToAirport(ostream &os, const string &airport, Transport& transport) {

    if (airportTransports.count(airport)) {
        BST<Transport>& bst = airportTransports[airport];

        bst.insert(transport);

        return true;
    }

    return false;
}

bool Manager::removeTransportInAirport(ostream &os, const string &airport, Transport &transport) {
    if (airportTransports.count(airport)) {
        BST<Transport> &bst = airportTransports[airport];

        if (bst.remove(transport))
            os << "Removed with success!\n";
        else
            os << "Transport not found!\n";

        return true;
    }

    return false;
}

bool Manager::updateTransportInAirport(ostream &os, const string &airport, Transport &transport) {
    if (airportTransports.count(airport)) {
        BST<Transport> &bst = airportTransports[airport];
        const Transport& nTrs = Transport();
        if (!(bst.find(transport) == nTrs)) {
            short i;
            cout << "New timetable for transport. How many schedules does it have ? \n >";
            cin >> i;
            Time t;
            TimeTable timeTable;
            for (int j = 0; j < i; ++j) {
                try {
                    cout << "Time " << j +1 << " : \n >";
                    cin >> t;
                    timeTable.insert(t);
                }catch (exception& exception) {
                    cout << "Not a valid transport. \n"; return false;
                }
            }
            transport.setTimeTable(timeTable);
            bst.remove(transport);
            bst.insert(transport);
        }
        else
            os << "Sorry... It seems that the transport does not exists\n";

        return true;
    }
    return false;
}


void Manager::saveToFile() {

    std::ofstream ofsPlanes(planesPath);
    std::ofstream ofsPassengers(passengersPath);
    std::ofstream ofsFlights(flightsPath);
    std::ofstream ofsTransports(transportsPath);
    std::ofstream ofsTickets(tickets_path);

    for (Plane &p:planes)
        ofsPlanes << p;

    for (Passenger &p:passengers)
        ofsPassengers << p;

    for (Flight &f:flights)
        ofsFlights << f;

    for (auto &p: airportTransports) {
        ofsTransports << p.first << '\n';

        BSTItrIn<Transport> it(p.second);
        int s = 0;
        while (!it.isAtEnd()) {
            s++;
            it.advance();
        }
        ofsTransports << s << '\n';
        BSTItrPre<Transport> itr(p.second);
        while (!itr.isAtEnd()) {
            const Transport &t = itr.retrieve();
            ofsTransports << t.getType() << " " << t.getDistance() << " " << t.getTimeTable().size()
                          << " " << t.getTimeTable() << endl;
            itr.advance();
        }
    }

    for (auto &t: tickets) {
        ofsTickets << t;
    }

    ofsPlanes.close();
    ofsFlights.close();
    ofsPassengers.close();
    ofsTransports.close();
    ofsTickets.close();

    serviceManager.saveToFile();
}



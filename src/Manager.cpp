#include <algorithm>
#include "../include/Manager.h"


void Manager::setPaths(){
    ifstream dirs(filesDir);

    getline(dirs,flights_path);
    getline(dirs,planes_path);
    getline(dirs,passengers_path);
    getline(dirs,service_path);

}


Manager::Manager() {

    setPaths();

    readFlights();
    readPassengers();
    readPlanes();
    readServices();
}


void Manager::showSortedPassengersByID(ostream &ostream1, unsigned int min, unsigned int max) {

    out::headerPassengers(ostream1);

    auto it = lower_bound(passengers.begin(),passengers.end(), Passenger(min, ""));
    for (;it!=passengers.end();it++) {
        if (it->getID() > max) break;
        out::passenger(ostream1,it);
    }

}

void Manager::showSortedFlightsByID(ostream &ostream1, flightNumber min , flightNumber max) {

    out::headerFlights(ostream1);
    auto it = lower_bound(flights.begin(), flights.end(), Flight(min, Date(), Time(),2.4f, "", ""));

    for (;it!=flights.end();it++) {
        if (it->getNumber() > max) break;
        out::flights(ostream1,it);
    }
}


void Manager::showSortedPlanes(ostream &ostream1,const planePlate& min,const planePlate& max) {

    out::headerPlanes(ostream1);
    auto it = lower_bound(planes.begin(), planes.end(), Plane(min,"",0));

    for (;it!=planes.end();it++) {
        if (it->getNumberPlate() > max) break;
        out::planes(ostream1,it);
    }
}

void Manager::readFlights() {
    std::ifstream ifs_flights(flights_path);

    Flight flight;
    while (ifs_flights >> flight) {
        flights.push_back(flight);
    }

    ifs_flights.close();
}

void Manager::readPlanes() {
    std::ifstream ifs_planes(planes_path);

    Plane plane;
    while (ifs_planes >> plane) {
        planes.push_back(plane);
    }

    ifs_planes.close();
}

void Manager::readPassengers() {
    std::ifstream ifs_passengers(passengers_path);


    Passenger passenger;
    while (ifs_passengers >> passenger) {
        passengers.push_back(passenger);
    }

    ifs_passengers.close();
}

void Manager::readServices() {
    this->serviceManager = ServiceManagement(service_path);
}

void Manager::showDoneServices(ostream &ostream1, const Date &min, const Date &max) {
    serviceManager.showDoneServicesFromRange(ostream1, min, max);
}



Manager::~Manager() {

    serviceManager.~ServiceManagement();

    //Guardar as alterações nos ficheiros
    std::ofstream ofsPlanes(planes_path);
    std::ofstream ofsPassengers(passengers_path);
    std::ofstream ofsFlights(flights_path);

    for(Plane &p:planes)
        ofsPlanes << p;

    for(Passenger &p:passengers)
        ofsPassengers << p;

    for(Flight &f:flights)
        ofsFlights << f;

    ofsPlanes.close();
    ofsFlights.close();
    ofsPassengers.close();


}


void Manager::searchPassengers(int id) {

    string name1;
    bool changed = false;
    for (auto it = passengers.begin(); it != passengers.end(); it++) {
        if ((*it).getID() == id) {
            std::cout << "Valid id."<<endl;
            cout << "(Old name: "<<(*it).getName()<<")       New name:";
            cin.ignore();
            getline(std::cin, name1);
            (*it).setName(name1);
            changed=true;
            break;
        }
    }
    if (!changed) cout<<"Invalid id!"<<endl;
}

void Manager::searchFlights(int id) {
    //enum attributePas {
    //  name,
    //};
    Date deparDate;
    Time deparTime;
    float duration;
    int occupation;
    std::string origin;
    std::string destiny;

    bool changed = false;
    for (auto it = flights.begin(); it != flights.end(); it++) {
        if ((*it).getNumber() == id) {
            std::cout << "Valid id." << endl;
            cout << "(Old departure date: " << (*it).getDepartureDate() << ")       New:";
            cin >> deparDate;
            (*it).setDepartureDate(deparDate);
            cout << "(Old departure time: " << (*it).getDepartureTime() << ")       New:";
            cin >> deparTime;
            (*it).setDepartureTime(deparTime);
            cout << "(Old duration: " << (*it).getDuration() << ")       New:";
            cin >> duration;
            (*it).setDuration(duration);
            cout<<"(Old occupation: "<<(*it).getOccupation()<<")       New:";
            cin>>occupation;
            (*it).setOccupation(occupation);
            cin.ignore();
            cout << "(Old origin: " << (*it).getOrigin() << ")       New:";
            getline(cin, origin);
            (*it).setOrigin(origin);
            cout << "(Old destiny: " << (*it).getDestiny() << ")       New:";
            getline(cin, destiny);
            (*it).setDestiny(destiny);
            changed=true;
        }
    }
    if (!changed) cout<<"Invalid id!"<<endl;
}

void Manager::searchPlanes(string id){
    string numberPlate;
    string  planetype;
    int capacity;
    bool changed=false;
    for (auto it=planes.begin();it!=planes.end();it++){
        if ((*it).getNumberPlate()==id){
            std::cout << "Valid Plate." << endl;
            cout << "(Old Plate's number: " << (*it).getNumberPlate() << ")       New:";
            cin >> numberPlate;
            (*it).setNumberPlate(numberPlate);
            cout << "(Old Plane's type: " << (*it).getType() << ")       New:";
            cin >> planetype;
            (*it).setType(planetype);
            cout << "(Old capacity: " << (*it).getCapacity() << ")       New:";
            cin >> capacity;
            (*it).setCapacity(capacity);
            changed=true;
        }
    }
    if (!changed) cout<<"Invalid Plate!"<<endl;
}

void Manager::searchServices(ServiceType type, Date date, employerName employer, planePlate plane){
    ServiceType type1;
    Date date1;
    employerName employer1;
    planePlate plane1;
    bool changed=false;
    //for (auto it=serviceManager.;it!=planes.end();it++){
    //    if ((*it).getNumberPlate()==id){
}


void Manager::createPassenger(const string &Pname){

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

    unsigned newID = flights.back().getNumber()+1;
    Flight f(newID,departureDate,departureTime,duration,origin,destiny);

    flights.push_back(f);

}





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

void Manager::searchPassengerID(ostream &ostream1, const regex& exp) {
    out::headerPassengers(ostream1);

    for (auto& p : passengers) {
        if(regex_match(p.getName() ,exp))
            out::passenger(ostream1,&p);
    }
}



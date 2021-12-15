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

void Manager::searchPassengers(int id){
    //enum attributePas {
    //  name,
    //};
    string attribute;
    string name;
    bool changed = false;
    for (auto it=passengers.begin();it!=passengers.end();it++){
        if ((*it).getID()==id) {
            std::cout << "Valid id. ";
            while (attribute != "name") {
                std::cout << "What attribute to change?";
                cin >> attribute;
                if (attribute == "name") {
                    std::cout << "What name do you want?";
                    cin >> name;
                    passengers.erase(it);
                    Passenger p1(id, name);
                    passengers.push_back(p1);
                    changed = true;
                    break;
                } else {
                    cout<<"Invalid attribute! ";
                }
            }
        }
    }
    if (!changed) std::cout << "Invalid id!"<<endl;
}


Manager::~Manager(){

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


    serviceManager.~ServiceManagement();

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





#include "../include/Manager.h"




void Manager::setPaths(){
    ifstream dirs(filesDir);

    getline(dirs,flights_path);
    getline(dirs,planes_path);
    getline(dirs,passengers_path);

}


Manager::Manager() {

    setPaths();

    std::ifstream ifs_flights(flights_path);

    Flight flight;
    while (ifs_flights >> flight) {
        flights.push_back(flight);
    }


    ifs_flights.close();


    std::ifstream ifs_passengers(passengers_path);



    Passenger passenger;
    while (ifs_passengers >> passenger) {
        passengers.push_back(passenger);
    }

    ifs_passengers.close();

    std::ifstream ifs_planes(planes_path);

    Plane plane;
    while (ifs_planes >> plane) {
        planes.push_back(plane);
    }

    ifs_planes.close();

}


void Manager::showSortedPassengers(ostream &ostream1) {

    ostream1<<"ID\t"<<"Name"<<endl;
    for (auto p: passengers) {
        ostream1 << p.getID()<<"\t"<<p.getName()<<endl;
    }

}

void Manager::showSortedFlights(ostream &ostream1) {

    ostream1<<setfill(' ')<<"Number\t\t"<<setw(15)<<"Departure Date "<<setw(45)<<"Origin "<<setw(40)<<"Destiny"<<endl;
    for (auto f: flights) {
        ostream1 <<setfill(' ')<<f.getNumber()<<'\t'<<setw(15)<<f.getDepartureDate()<<setw(50)<<f.getOrigin()<<" ⟶ "<<setw(45)<<f.getDestiny()<<endl;
    }
}

void Manager::showSortedPlanes(ostream &ostream1) {

    ostream1<<"Plate\t"<<"Capacity\t"<<"A\t"<<"B\t"<<"C\t"<<endl;
    for (auto p : planes) { // TODO :: ALL THIS FUNCTIONS CAN HAVE A DIFF OUTPUT - IN HERE (do not overload <<)
        ostream1 << p;
    }
}

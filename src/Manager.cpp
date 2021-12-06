#include "../include/Manager.h"

void Manager::showSortedPassengers(ostream &ostream1) {

    for (auto p: passengers) {
        // TODO: this will of course show the \0 chars, maybe this is not the desire here
        ostream1 << p.getID()<<" "<<p.getName()<<endl;
    }

}

Manager::Manager(const std::string &flights_path, const std::string &passengers_path, const std::string& planes_path) {

    std::ifstream ifs_flights(flights_path);

    Flight flight;
    while (ifs_flights >> flight) { // TODO: SOMETHING MADE THIS BROKEN -- IT'S NOT GETTING THE FLIGHTS
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

void Manager::showSortedFlights(ostream &ostream1) {

    for (auto f: flights) {
        ostream1 << f.getNumber()<<" "<<f.getDepartureDate()<<" "<<f.getOrigin()<<"-->"<<f.getDestiny()<<endl;
    }
}

void Manager::showSortedPlanes(ostream &ostream1) {

    for (auto p : planes) { // TODO :: ALL THIS FUNCTIONS CAN HAVE A DIFF OUTPUT - IN HERE (do not overload <<)
        ostream1 << p;
    }
}

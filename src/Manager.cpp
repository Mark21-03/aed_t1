#include "../include/Manager.h"

void Manager::showSortedPassengers(ostream& ostream1) {

    for (auto p: passengers) {
        ostream1 << p; // TODO: this will of course show the \0 chars, maybe this is not the desire here
    }

}

Manager::Manager(const std::string& flights_path) {

    std::ifstream ifs(flights_path);

    vector<Flight> v;
    Flight flight;
    while (ifs >> flight) { // TODO: SOMETHING MADE THIS BROKEN -- IT'S NOT GETTING THE FLIGHTS
        v.push_back(flight);
        ifs.ignore();
    }

    ifs.close();

    flights = v;
}

void Manager::showSortedFlights(ostream& ostream1) {

    for (auto f: flights) {
        ostream1 << f;
    }
}

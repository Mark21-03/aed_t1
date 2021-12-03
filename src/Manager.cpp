#include "../include/Manager.h"

void Manager::showSortedPassengers() {

    for (auto p: passengers) {
        std::cout << p; // TODO: this will of course show the \0 chars, maybe this is not the desire here
    }

}

Manager::Manager(std::string flights_path) {

    std::ifstream ifs(flights_path);

    Flight flight;
    while (ifs >> flight) { // TODO: SOMETHING MADE THIS BROKEN -- IT'S NOT GETTING THE FLIGHTS
        flights.push_back(flight);
    }

    ifs.close();
}

void Manager::showSortedFlights() {
    for (auto f: flights) {
        std::cout << f;
    }

}

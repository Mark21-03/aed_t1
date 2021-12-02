#include "../include/Manager.h"

void Manager::showSortedPassengers() {

    for (auto p: passengers) {
        std::cout << p; // TODO: this will of course show the \0 chars, maybe this is not the desire here
    }

}

Manager::Manager() {

    std::ifstream ifs("../Files/Flights/flights.txt");

    Flight flight;
    while (ifs >> flight) {
        flights.push_back(flight);
    }
}

void Manager::showSortedFlights() {
    for (auto f: flights) {
        std::cout << f;
    }
}

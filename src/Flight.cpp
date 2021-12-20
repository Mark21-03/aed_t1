
#include "../include/Flight.h"
#include "../Exceptions/NameToLongException.h"

Flight::Flight(flightNumber number, const Date &departureDate, const Time &departureTime, float duration,
               std::string origin, std::string destiny) {

    this->number = number;
    this->departureDate = departureDate;
    this->departureTime = departureTime;
    this->duration = duration;
    this->occupation = 0;
    this->maxCapacity = 0; // it still isn't connected to a flight so the max capacity is 0.


    if (origin.size() > STRING_MAX_VALUE || destiny.size() > STRING_MAX_VALUE) {
        throw NameToLongException();
    }

    setOrigin(origin).setDestiny(destiny);

}

Flight::Flight(flightNumber number, const Date &departureDate, const Time &departureTime, int occupation,
               float duration,
               std::string origin, std::string destiny, int maxCapacity) {

    this->number = number;
    this->departureDate = departureDate;
    this->departureTime = departureTime;
    this->duration = duration;
    this->occupation = occupation;
    this->maxCapacity = maxCapacity;

    if (origin.size() > STRING_MAX_VALUE || destiny.size() > STRING_MAX_VALUE) {
        throw NameToLongException();
    }

    setOrigin(origin).setDestiny(destiny);
}


flightNumber Flight::getNumber() const { return this->number; }

Date Flight::getDepartureDate() const { return this->departureDate; }

int Flight::getOccupation() const { return this->occupation; }

float Flight::getDuration() const { return this->duration; }

std::string Flight::getOrigin() const {
    int i = 0;
    string s;
    char c;
    while ((c = origin[i++]) != '\0') {
        s += c;
    }
    return s;
}

std::string Flight::getDestiny() const {
    int i = 0;
    string s;
    char c;
    while ((c = destiny[i++]) != '\0') {
        s += c;
    }
    return s;
}


Flight &Flight::setNumber(flightNumber newNumber) {
    this->number = newNumber;
    return *this;
}

Flight &Flight::setDepartureDate(const Date &newDepartureDate) {
    this->departureDate = newDepartureDate;
    return *this;
}

Flight &Flight::setDuration(float newDuration) {
    this->duration = newDuration;
    return *this;
}

Flight &Flight::setOrigin(const std::string &newOrigin) {
    int i = 0;
    for (const auto &c: newOrigin) {
        if (i > STRING_MAX_VALUE)
            throw NameToLongException();
        this->origin[i++] = c;
    }
    this->origin[i] = '\0';

    return *this;
}

Flight &Flight::setDestiny(const std::string &newDestiny) {
    int i = 0;
    for (const auto &c: newDestiny) {
        if (i > STRING_MAX_VALUE)
            throw NameToLongException();
        this->destiny[i++] = c;
    }
    this->destiny[i] = '\0';

    return *this;
}

Flight &Flight::setOccupation(int newOccupation) {
    this->occupation = newOccupation;
    return *this;
}

char *Flight::getOriginC() {
    return origin;
}

char *Flight::getDestinyC() {
    return destiny;
}

Flight &Flight::setDepartureTime(const Time &newDepartureTime) {
    this->departureTime = newDepartureTime;
    return *this;
}

Time Flight::getDepartureTime() const {
    return this->departureTime;
}

Baggage Flight::takeBaggageFromFlight() {
    Baggage temp = planeStoredBaggage.front();
    planeStoredBaggage.pop();
    return temp;
}

void Flight::addBaggage2Flight(const Baggage &baggage) {
    planeStoredBaggage.push(baggage);
}

queue<Baggage> Flight::getPlaneStoredBaggage() const {
    return planeStoredBaggage;
}

int Flight::getMaxCapacity() const {
    return maxCapacity;
}

Flight &Flight::setMaxCapacity(int newMaxCapacity) {
    this->maxCapacity = newMaxCapacity;
    return *this;
}





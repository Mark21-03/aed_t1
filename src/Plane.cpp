#include "../include/Plane.h"


Plane::Plane(const planePlate &numberPlate, const std::string &pType, int capacity) {
    this->numberPlate = numberPlate;
    this->pType = pType;
    this->capacity = capacity;
}


Plane::Plane(const planePlate &numberPlate, const std::string &pType, int capacity,
             const std::list<flightNumber> &flightPlan) {
    this->numberPlate = numberPlate;
    this->pType = pType;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
}


std::string Plane::getType() const { return this->pType; }

int Plane::getCapacity() const { return this->capacity; }

std::list<flightNumber> Plane::getFlightPlan() const { return this->flightPlan; }

planePlate Plane::getNumberPlate() const {
    return numberPlate;
}


Plane &Plane::setFlightPlan(const std::list<flightNumber> &newFlightPlan) {
    this->flightPlan = newFlightPlan;
    return *this;
}

Plane &Plane::setCapacity(int newCapacity) {
    this->capacity = newCapacity;
    return *this;
}

Plane &Plane::setType(const std::string &newPlaneType) {
    this->pType = newPlaneType;
    return *this;
}

Plane &Plane::setNumberPlate(const string &newNumberPlate) {
    this->numberPlate = newNumberPlate;
    return *this;
}


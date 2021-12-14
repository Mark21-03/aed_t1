#include "../include/Plane.h"


Plane::Plane(const planePlate& numberPlate ,const std::string& pType, int capacity){
    this->numberPlate = numberPlate;
    this->pType = pType;
    this->capacity = capacity;
}


Plane::Plane(const planePlate& numberPlate ,const std::string& pType, int capacity, const std::list<flightNumber>& flightPlan){
    this->numberPlate = numberPlate;
    this->pType = pType;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
}
//Getters
std::string Plane::getType() const{return this->pType;}

int Plane::getCapacity() const {return this->capacity;}

std::list<flightNumber> Plane::getFlightPlan() const {return this->flightPlan;}

planePlate Plane::getNumberPlate() const{
    return numberPlate;
}


//Setters
Plane& Plane::setFlightPlan(const std::list<flightNumber> &flightPlan) { this->flightPlan = flightPlan; return *this;}

Plane& Plane::setCapacity(int capacity) {this->capacity = capacity;return *this;}

Plane& Plane::setType(const std::string& pType) { this->pType = pType;return *this;}

Plane& Plane::setNumberPlate(const string &numberPlate) {
    this->numberPlate = numberPlate;return *this;
}


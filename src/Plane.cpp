#include "Plane.hpp"


Plane::Plane(string numberPlate, int capacity){
    this->numberPlate = numberPlate;
    this->capacity = capacity;
}

Plane::Plane(string numberPlate, int capacity,vector<Flight> flightPlan){
    this->numberPlate = numberPlate;
    this->capacity = capacity;
    this->flightPlan = flightPlan;
}
//Getters
string Plane::getNumberPlate() const{return this->numberPlate;}

int Plane::getCapacity() const {return this->capacity;}

vector<Flight> Plane::getFlightPlan() const {return this->flightPlan;}

//Setters
void Plane::setflightPlan(const vector<Flight> &flightPlan) {this->flightPlan = flightPlan;}

void Plane::setCapacity(int capacity) {this->capacity = capacity;}

void Plane::setNumberPlate(string numberPlate) {this->numberPlate = numberPlate;}




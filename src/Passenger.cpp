#include "../include/Passenger.h"

#include <utility>


std::string Passenger::getName() const{
    int i=0;
    string s;
    char c;
    while ((c = name[i++] )!= '\0') {
        s+=c;
    }
    return s;
}

unsigned int Passenger::getID() const {
    return ID;
}

Passenger& Passenger::setName(const string &name) {

    int i = 0;
    for (auto c: name) {
        if (i > LONGEST_ACCEPTED_NAME)
            throw NameToLongException();
        this->name[i++] = c;
    }
    this->name[i] = '\0';

    return *this;
}

Passenger& Passenger::setID(unsigned int ID) {
    this -> ID = ID;

    return *this;
}



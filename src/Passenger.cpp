#include "../include/Passenger.h"


std::string Passenger::getName() const {
    int i = 0;
    string s;
    char c;
    while ((c = name[i++]) != '\0') {
        s += c;
    }
    return s;
}

unsigned int Passenger::getID() const {
    return ID;
}

Passenger &Passenger::setName(const string &newName) {

    int i = 0;
    for (const auto &c: newName) {
        if (i > LONGEST_ACCEPTED_NAME)
            throw NameToLongException();
        this->name[i++] = c;
    }
    this->name[i] = '\0';

    return *this;
}

Passenger &Passenger::setID(unsigned int newID) {
    this->ID = newID;

    return *this;
}



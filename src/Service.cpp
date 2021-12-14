#include "../include/Service.h"

#include <utility>
#include "../Exceptions/NameToLongException.h"

Service::Service(char type, Date date,string employer,string  plate) : plane(std::move(plate)), date(date) {
    setType(type).setEmployer(employer);
}

//getters
ServiceType Service::getType() const {return this->type;}
Date Service::getDate() const{ return this->date;}
string Service::getEmployer() const { // TODO: THIS IS A REPEATED CODE; MAYBE IT SHOULD BE MADE A UTILITIES SPACE
    int i=0;
    string s;
    char c;
    while ((c = employer[i++] )!= '\0') {
        s+=c;
    }
    return s;
}
planePlate Service::getPlane() const {return plane;}

//setters
Service& Service::setType(char type) {
    if (type == 'm')
        this->type = maintenance;
    else if (type == 'c')
        this->type = cleaning;
    else
        this->type = other;

    return *this;
}
Service& Service::setDate(Date date) {this->date=date; return *this;}
Service& Service::setEmployer(const string& employer) {
    int i = 0;
    for (const auto& c: employer) {
        if (i > LONGEST_ACCEPTED_EMPLOYER_NAME)
            throw NameToLongException();
        this->employer[i++] = c;
    }
    this->employer[i] = '\0';

    return *this;}

Service& Service::setPlate(const planePlate &plane) { this->plane = plane; return *this;}

std::string Service::getInfo() const {
    ostringstream os;
    switch (type) {
        case maintenance:
            os << "Maintenance by " << getEmployer() << " on "<< date.getDate() << " and plane with plate" << plane;break;
        case cleaning:
            os << "Cleaning by " <<getEmployer() << " on "<<date.getDate() << " and plane with plate" << plane;break;
        case other:
            os << "Other services by " << getEmployer() << " on "<<date.getDate() << " and plane with plate" << plane;break;

    }
    return os.str();
}

char *Service::getEmployerNameC() {
    return employer;
}


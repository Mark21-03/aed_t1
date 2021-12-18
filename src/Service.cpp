#include "../include/Service.h"

#include <utility>
#include "../Exceptions/NameToLongException.h"

Service::Service(char type, Date date,const string& employer,string plate) : plane(std::move(plate)), date(date) {
    setType(type).setEmployer(employer);
}

//getters
ServiceType Service::getType() const {return this->type;}
Date Service::getDate() const{ return this->date;}
string Service::getEmployer() const {
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
            os <<setw(1)<<(char)getType()<<setw(30)<< getEmployer() << "\t"<< date.getDate() << "\t" << plane;break;
        case cleaning:
            os <<setw(1)<<(char)getType()<<setw(30)<< getEmployer() << "\t"<<date.getDate() << "\t" << plane;break;
        case other:
            os <<setw(1)<<(char)getType()<<setw(30)<< getEmployer() << "\t"<<date.getDate() << "\t" << plane;break;

    }
    return os.str();
}

char *Service::getEmployerNameC() {
    return employer;
}


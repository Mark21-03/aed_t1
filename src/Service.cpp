#include "../include/Service.h"

#include <utility>
#include "../Exceptions/NameToLongException.h"

Service::Service(char type, Date date, const string &employee, string plate) : plane(std::move(plate)), date(date) {
    setType(type).setEmployee(employee);
}


ServiceType Service::getType() const { return this->type; }

Date Service::getDate() const { return this->date; }

string Service::getEmployee() const {
    int i = 0;
    string s;
    char c;
    while ((c = employee[i++]) != '\0') {
        s += c;
    }
    return s;
}

planePlate Service::getPlane() const { return plane; }


Service &Service::setType(char newType) {
    if (newType == 'm')
        this->type = maintenance;
    else if (newType == 'c')
        this->type = cleaning;
    else
        this->type = other;

    return *this;
}

Service &Service::setDate(Date newDate) {
    this->date = newDate;
    return *this;
}

Service &Service::setEmployee(const string &newEmployee) {
    int i = 0;
    for (const auto &c: newEmployee) {
        if (i > LONGEST_ACCEPTED_EMPLOYEE_NAME)
            throw NameToLongException();
        this->employee[i++] = c;
    }
    this->employee[i] = '\0';

    return *this;
}

Service &Service::setPlate(const planePlate &newPlane) {
    this->plane = newPlane;
    return *this;
}

std::string Service::getInfo() const {
    ostringstream os;

    os << setw(1) << (char) getType() << "\t" << date.getDate() << '\t' << plane << "\t  " << getEmployee()
       << '\r';

    return os.str();
}

char *Service::getEmployeeNameC() {
    return employee;
}


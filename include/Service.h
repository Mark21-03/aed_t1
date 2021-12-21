#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Date.h"
#include "Plane.h"
#include <queue>

#define LONGEST_ACCEPTED_EMPLOYEE_NAME 45

/**
 * An enum representing the types of services available
 */
enum ServiceType {
    maintenance = 'm',/**< A Maintenance service done on an airplane*/
    cleaning = 'c',/**< A Cleaning service done on an airplane*/
    other = 'o'/**< A other type of service done on an airplane*/
};

typedef char employeeName[LONGEST_ACCEPTED_EMPLOYEE_NAME];

/**
 * A class that represents all the information about a Service.
 */
class Service {
private:
    /**
     * The type of the service.
     */
    ServiceType type;
    /**
     * The date in which the service was done or will be done.
     */
    Date date;
    /**
     * The name of the employer responsible for the service.
     */
    employeeName employee{};
    /**
     * The identifier of the plane in which the service will be or was done.
     */
    planePlate plane;

public:

    /**
     * Default constructor
     */
    Service() = default;

    /**
     * Constructs a service with a specified type, a date, the employee
     * who did the service and the plate of the plane where the service happens
     * @param type type of service (m | c | o) - maintenance, cleaning, other
     * @param date date of the service
     * @param employee who did the service
     * @param plate which plane received the service
     */
    Service(char type, Date date, const string &employee, string plate);

    /**
     * Defines new type for a service
     * @param newType value to be set
     * @return changed service object
     */
    Service &setType(char newType);

    /**
     * Defines new date for a service
     * @param newDate value to be set
     * @return changed service object
     */
    Service &setDate(Date newDate);

    /**
     * Defines new employee for a service
     * @param newEmployee value to be set
     * @return changed service object
     */
    Service &setEmployee(const std::string &newEmployee);

    /**
     * Defines new planePlate for a service
     * @param newPlane value to be set
     * @return changed service object
     */
    Service &setPlate(const planePlate &newPlane);

    /**
     * Gives type of service
     * @return service's type
     */
    ServiceType getType() const;

    /**
     * Gives date of service
     * @return service's date
     */
    Date getDate() const;

    /**
     * Gives employee who does a service
     * @return service's employee
     */
    string getEmployee() const;

    /**
     * Gives the planePlate of a service
     * @return service's planePlate
     */
    planePlate getPlane() const;

    /**
     * Gives a formatted service string
     * @return formatted string
     */
    std::string getInfo() const;

    /**
     * Gives service's employee name as a char[]
     * @return service's employee name
     */
    char *getEmployeeNameC();

};

/**
 * Allows for outputting a service to a ostream
 * @param os output stream to be used
 * @param s service to be outputted
 * @return output stream (changed)
 */
inline std::ostream &operator<<(std::ostream &os, const Service &s) {

    os << s.getType() << " " << s.getDate().getDate();

    string name = s.getEmployee();
    for (unsigned int i = 0; i < LONGEST_ACCEPTED_EMPLOYEE_NAME; ++i) {
        if ((size_t)i < name.size())
            os << (name[i]);
        else
            os << '\0';
    }

    os << s.getPlane() << std::endl;

    return os;
}

/**
 * Allows for inputting a service from a istream
 * @param is input stream  to be used
 * @param s service to be set
 * @return input stream (changed)
 */
inline std::istream &operator>>(std::istream &is, Service &s) {
    std::string string1;

    int type;
    Date date;
    std::string employee;
    std::string plane;

    is >> type >> date;

    s.setType((char) type).setDate(date);

    for (int i = 0; i < LONGEST_ACCEPTED_EMPLOYEE_NAME; ++i) {
        s.getEmployeeNameC()[i] = is.get();
    }

    is >> plane;

    s.setPlate(plane);
    return is;
}


/**
 * Tests if two services are equal by testing equivalence between their
 * type, date, employee and planePlate
 * @param s1 left-hand service being compared
 * @param s2 right-hand service being compared
 * @return boolean result from comparison
 */
inline bool operator==(const Service &s1, const Service &s2) {
    return (s1.getType() == s2.getType() && s1.getDate() == s2.getDate()
            && s1.getEmployee() == s2.getEmployee() && s1.getPlane() == s2.getPlane());
}

/**
 * Tests if a service is lesser than another by comparing the service's dates
 * @param s1  left-hand service being compared
 * @param s2 right-hand service being compared
 * @return boolean result from comparison
 */
inline bool operator<(const Service &s1, const Service &s2) {
    return (s1.getDate() < s2.getDate());
}

/**
 * Tests if two services are different by testing if at least one
 * attribute is different between them
 * @param s1 left-hand service being compared
 * @param s2 right-hand service being compared
 * @return boolean result from comparison
 */
inline bool operator!=(const Service &s1, const Service &s2) {
    return !(s1 == s2);
}

#endif //SERVICE_H

#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Date.h"
#include "Plane.h"
#include <queue>

#define LONGEST_ACCEPTED_EMPLOYER_NAME 45

enum ServiceType {
    maintenance = 'm',
    cleaning = 'c',
    other = 'o'
};

typedef char employerName[LONGEST_ACCEPTED_EMPLOYER_NAME];

class Service {
private:
    ServiceType type;
    Date date;
    employerName employer{};
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
     * @param employer who did the service
     * @param plate which plane received the service
     */
    Service(char type, Date date, const string &employer, string plate);

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
     * @param newEmployer value to be set
     * @return changed service object
     */
    Service &setEmployer(const std::string &newEmployer);

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
    string getEmployer() const;

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
    char *getEmployerNameC();

};

/**
 * Allows for outputting a service to a ostream
 * @param os output stream to be used
 * @param s service to be outputted
 * @return output stream (changed)
 */
inline std::ostream &operator<<(std::ostream &os, const Service &s) {

    os << s.getType() << " " << s.getDate().getDate();

    string name = s.getEmployer();
    for (int i = 0; i < LONGEST_ACCEPTED_EMPLOYER_NAME; ++i) {
        if (i < name.size())
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
    std::string employer;
    std::string plane;

    is >> type >> date;

    s.setType((char) type).setDate(date);

    for (int i = 0; i < LONGEST_ACCEPTED_EMPLOYER_NAME; ++i) {
        s.getEmployerNameC()[i] = is.get();
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
            && s1.getEmployer() == s2.getEmployer() && s1.getPlane() == s2.getPlane());
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

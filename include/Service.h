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

class Service{
private:
    ServiceType type;
    Date date;
    employerName employer{};
    planePlate plane;

public:
    Service()=default;
    Service(char type, Date date,const string& employer,string plate);

    Service& setType(char type);
    Service& setDate(Date date);
    Service& setEmployer(const std::string& employer);
    Service& setPlate(const planePlate& plane);

    ServiceType getType() const;
    Date getDate() const;
    string getEmployer() const;
    planePlate getPlane() const;
    std::string getInfo() const;
    char* getEmployerNameC();

};

inline std::ostream& operator<< (std::ostream& os, const Service& s) {

    os << s.getType() << " " << s.getDate().getDate();

    string name = s.getEmployer();
    for (int i = 0; i < LONGEST_ACCEPTED_EMPLOYER_NAME; ++i) {
        if ( i < name.size())
            os << (name[i]);
        else
            os << '\0';
    }

    os << s.getPlane() << std::endl;

    return os;
}

inline std::istream& operator>> (std::istream& is, Service& s) {
    std::string string1;

    int type;
    Date date;
    std::string employer;
    std::string plane;

    is >> type >> date ;

    s.setType((char)type).setDate(date);

    for (int i = 0; i < LONGEST_ACCEPTED_EMPLOYER_NAME; ++i) {
        s.getEmployerNameC()[i] = is.get();
    }

    is >> plane;

    s.setPlate(plane);
    return is;
}

inline bool operator==(const Service &s1, const Service &s2){
    return (s1.getType() == s2.getType() && s1.getDate() == s2.getDate()
            && s1.getEmployer()== s2.getEmployer() && s1.getPlane() == s2.getPlane());
}

inline bool operator<(const Service &s1, const Service &s2){
    return (s1.getDate()<s2.getDate());
}

inline bool operator!=(const Service &s1, const Service &s2){
    return !(s1 == s2);
}

#endif //SERVICO_H

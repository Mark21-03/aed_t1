#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Date.h"
#include <queue>

enum ServiceType {
    maintenance,
    cleaning,
    other
};

class Service{
private:
    ServiceType type; // TODO: ADD A Plane Plane ... as the service is connected to a plane
    Date date;
    string employer;
public:
    Service()=default;
    Service(char type, Date date, string employer);

    void setType(char type);
    void setDate(Date date);
    void setEmployer(string employer);

    ServiceType getType() const;
    Date getDate() const;
    string getEmployer() const;
};

inline std::ostream& operator<< (std::ostream& os,const Service& s) { // TODO: this seems a bit off..
    switch (s.getType()) {
        case 0:
            os << "Maintenance by " <<s.getEmployer() << " on "<<s.getDate();break;
        case 1:
            os << "Cleaning by " <<s.getEmployer() << " on "<<s.getDate();break;
        default:
            os << "Other services by " <<s.getEmployer() << " on "<<s.getDate();break;

    }
    return os;
}

inline bool operator==(const Service &s1, const Service &s2){
    return (s1.getType() == s2.getType() && s1.getDate() == s2.getDate() && s1.getEmployer()== s2.getEmployer());
}

inline bool operator<(const Service &s1, const Service &s2){
    return (s1.getDate()<s2.getDate());
}

inline bool operator!=(const Service &s1, const Service &s2){
    return !(s1.getType() == s2.getType() && s1.getDate() == s2.getDate() && s1.getEmployer()== s2.getEmployer());
}

#endif //SERVICO_H

#ifndef PASSENGER_H
#define PASSENGER_H

#include "Flight.h"
#include "../Exceptions/NameToLongException.h"
#include "Ticket.h"
#include "Baggage.h"

#include <list>
#include <string>
#include <queue>
#include <numeric>

#define LONGEST_ACCEPTED_NAME 60


class Passenger {
private:
    unsigned int ID;
    char name[LONGEST_ACCEPTED_NAME]{};

public:
    Passenger() = default;

    Passenger(unsigned int ID, const std::string& name){
        setName(name);
        this->ID = ID;
    };

    std::string getName() const;
    char* getNameC() {
        return name;
    }
    unsigned int getID() const;

    // setters

    Passenger& setName(const std::string& name);
    Passenger& setID(unsigned int ID);

    friend class ComparePassengersByName;
};

inline std::ostream & operator<<(std::ostream& os, Passenger& l) {

    os << l.getID();

    bool ended = false;
    for (int i = 0; i < LONGEST_ACCEPTED_NAME; ++i) {
        if (ended) {
            os << '\0';
            continue;
        }
        char c =l.getNameC()[i];
        os << c;
        if (c=='\0')
            ended = true;

    }


    os << "\n";
    return os;
}


inline std::istream & operator>>(std::istream& is, Passenger& l) {
    unsigned int temp_ID;
    is >> temp_ID;
    l.setID(temp_ID);

    for (int i = 0; i < LONGEST_ACCEPTED_NAME; ++i) {
        l.getNameC()[i] = is.get();
    }

    return is;
}

inline bool operator<(const Passenger& l1,const Passenger& l2){
    return l1.getID()<l2.getID();
}

inline bool operator==(const Passenger& l1,const Passenger& l2){
    return l1.getID()==l2.getID();
}
inline bool operator!=(const Passenger& l1,const Passenger& l2){
    return l1.getID() != l2.getID();
}

class ComparePassengersByName {
public:
    bool operator()(Passenger* l , Passenger * r) {
        return l->getName()< r->getName();
    }
};

#endif //PASSENGER_H

#include <iostream>
#include <set>
#include "BST.h"
#include "Time.h"

using namespace std;


typedef std::set<Time> TimeTable;

class Transport{
private:
    char type; //S - subway, T - train , B - bus, N - not found TODO: ENUM
    TimeTable timetable;
    float distance ; // in kms

public:
    Transport(){this->type = 'N';this->distance = -1;};
    inline explicit Transport(char type){this->type = type;distance = 0;}
    inline Transport(char type, float distance){this->type = type;this->distance=distance;}

    inline char getType() const{return this->type;}
    bool setType(const char &type);

    inline float getDistance() const{return this->distance;}
    inline void setDistance(const float& distance){this->distance = distance;}

    inline void setTimeTable(const TimeTable& TimeTable){ this->timetable=TimeTable;}
    inline const TimeTable& getTimeTable() const {return this->timetable;} // TODO remember to check if it is working
};


inline bool Transport::setType(const char &type) {
    if(type=='S' || type=='T' || type=='B' ||  type=='N'){
        this->type = type;return true;
    }
    return false;
}


inline bool operator<(const Transport& t1, const Transport& t2){
    if (t1.getType() != t2.getType())
        return t1.getType() < t2.getType(); // this will break the bst in 4 different trees
    if (t1.getDistance() != t2.getDistance())
        return t1.getDistance()<t2.getDistance();
    return t1.getTimeTable() < t2.getTimeTable();
}

inline ostream& operator<<(ostream& os, Transport &t){
    os<<t.getType()<<" "<<t.getDistance();
    return os;
}

inline istream& operator>>(istream& is, Transport &t){
    char type;float distance;
    is>>type>>distance;
    t.setDistance(distance);
    t.setType(type);
    return is;
}

inline bool operator==(const Transport& t1,const Transport& t2){
    return t1.getDistance() == t2.getDistance() && t1.getType() == t2.getType() && t1.getTimeTable() == t2.getTimeTable();
}


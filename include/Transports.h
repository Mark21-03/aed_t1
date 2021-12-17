#include <iostream>
#include "BST.h"
#include "Time.h"

using namespace std;

class Timetable{
private:
    vector<Time>timetable;
public:
    inline vector<Time> getTimeTable(){return timetable;} 
    inline void setTimeTable(vector<Time>timetable){this->timetable = timetable;}
};

class Transport{
private:
    char type; //S - subway, T - train , B - bus, N - not found
    Timetable timetable;
    float distance ; // in kms

public:
    Transport(){this->type = 'N';this->distance = -1;};
    inline explicit Transport(char type){this->type = type;distance = 0;}
    inline Transport(char type, float distance){this->type = type;this->distance=distance;}

    inline char getType() const{return this->type;}
    bool setType(const char &type);

    inline float getDistance() const{return this->distance;}
    inline void setDistance(const float& distance){this->distance = distance;}

    inline void setTimeTable(const Timetable& TimeTable){this->timetable=TimeTable;}
    inline Timetable getTimeTable(){return this->timetable;}
};


inline bool Transport::setType(const char &type) {
    if(type=='S' || type=='T' || type=='B' ||  type=='N'){
        this->type = type;return true;
    }
    return false;
}


inline bool operator<(const Transport& t1, const Transport& t2){
    return t1.getDistance()<t2.getDistance();
}

inline ostream& operator<<(ostream& os, Transport &t){
    os<<t.getType()<<" "<<t.getDistance();
    return os;
}

inline istream& operator>>(istream& is, Transport &t){
    char type;float distance;
    is>>type>>distance;
    cout<<endl<<"DISTANCE = "<<distance<<endl;
    t.setDistance(distance);
    t.setType(type);
    return is;
}




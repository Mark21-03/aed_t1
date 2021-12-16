#include <iostream>
#include "BST.h"

using namespace std;

struct Time{};
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
    inline Transport(char type){this->type = type;}
    inline Transport(char type, float distance){this->type = type;this->distance=distance;}

    inline char getType(){return this->type;}
    bool setChar(const char &type);

    inline float getDistance(){return this->distance;}
    inline void setDistance(const float& distance){this->distance = distance;}

    inline void setTimeTable(const Timetable& TimeTable){this->timetable=TimeTable;}
    inline Timetable getTimeTable(){return this->timetable;}
};


bool Transport::setChar(const char &type){
    if(type=='S' && type=='T' && type=='B' &&  type=='N'){
        this->type = type;return true;
    }
    return false;
}


bool operator<(Transport t1, Transport t2){
    return t1.getDistance()<t2.getDistance();
}

ostream& operator<<(ostream& os, Transport &t){
    os<<t.getType()<<" "<<t.getDistance();
    return os;
}


class Aeroporto{
    private:
 
        
    public:
        Aeroporto(){};
        BST<Transport> transportsTree;

        
};


/*
int main(){
    Aeroporto a;

    

    for(int i =1;i<200;i*=2){
        Transport t('B',i%10);
        a.transportsTree.insert(t);
    }
    
    a.transportsTree.remove(Transport('B',4));
    
    a.transportsTree.printTree();
    
    cout<<"Closest: ";
    Transport t1 = a.transportsTree.findMin();
    cout<<t1<<endl;


    cout<<"Farthest: ";
    Transport t2 = a.transportsTree.findMax();
    cout<<t2<<endl;
    

}
*/
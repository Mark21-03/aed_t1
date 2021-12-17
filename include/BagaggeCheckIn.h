#ifndef AED_T1_BAGAGGECHECKIN_H
#define AED_T1_BAGAGGECHECKIN_H


#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include "../Exceptions/BaggageCheckInExceptions.h"
#include "../include/Baggage.h"


using namespace std;


class BaggageStack{
private:
    stack<Baggage> s;
    unsigned maxSize;

public:
    explicit BaggageStack(unsigned MaxSize): maxSize(MaxSize){};

    void addBaggage(const Baggage& baggage);
    Baggage takeBaggage();

    inline bool isFull(){return maxSize==s.size();}
    inline bool isEmpty(){return s.empty();}
    inline unsigned getMaxSize() const{return maxSize;}
    inline unsigned getCurrentSize(){return s.size();}

};


class Carriage{
private:
    unsigned maxStackHeight=0;
    unsigned maxCapacity = 0;
    unsigned currentCapacity=0;
    vector<BaggageStack> stacks;

public:
    Carriage()= default;
    Carriage(unsigned stacksNum, unsigned baggageNum);
    inline bool isFull() const{return currentCapacity==maxCapacity;}
    inline bool isEmpty() const{return (currentCapacity==0);}

    void addBaggage(const Baggage& baggage);
    Baggage takeBaggage();

    inline unsigned getCurrentCapacity() const{return currentCapacity;}
    inline unsigned getMaxCapacity() const{return maxCapacity;}

};


class BaggageTruck{
private:
    unsigned numCarriages=0; // c = 2
    unsigned numStacks=0; // n = 3
    unsigned numBaggage=0; //m = 4
    unsigned maxCapacity=0;
    unsigned currentCapacity=0;

    vector<Carriage> carriages;

public:
    BaggageTruck()= default;
    BaggageTruck(unsigned carriagesNum,unsigned stacksNum,unsigned baggageNum);

    inline bool isFull() const{return currentCapacity == maxCapacity;}
    inline bool isEmpty() const{return (currentCapacity==0);}
    void addBaggage(const Baggage& baggage);
    Baggage takeBagagge();

    inline unsigned getCurrentCapacity() const{return currentCapacity;}
    inline unsigned getMaxCapacity() const{return maxCapacity;}

};


class BaggageCheckIn{
private:
    queue<Baggage> conveyorBelt;
    BaggageTruck truck;
public:
    explicit BaggageCheckIn(unsigned carriagesNum, unsigned stacksNum, unsigned baggageNum){
        BaggageTruck t(carriagesNum, stacksNum, baggageNum);
        this->truck = t;
    }

    inline void queueAdd(const Baggage& baggage){conveyorBelt.push(baggage);}
    Baggage queueRemove();
    inline Baggage queueBack(){return conveyorBelt.back();}
    inline Baggage queueFront(){return conveyorBelt.front();}
    inline bool queueEmpty(){return conveyorBelt.empty();}

    inline void setQueue(queue<Baggage> bq){this->conveyorBelt = bq;}
    inline queue<Baggage> getQueue(){return this->conveyorBelt;}
    inline unsigned getQueueSize(){return conveyorBelt.size();}

    bool passNextBagaggeToTruck();

    void truckAddBaggage(const Baggage& baggage);
    inline bool isTruckFull(){return truck.isFull();}
    Baggage truckTakeBaggage();
    inline BaggageTruck getTruck(){return truck;}



};





#endif //AED_T1_BAGAGGECHECKIN_H

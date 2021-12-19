#include "../include/BagaggeCheckIn.h"




void BaggageStack::addBaggage(const Baggage& baggage){
    if(s.size()==maxSize) throw fullBaggageStackException();
    s.push(baggage);
}

Baggage BaggageStack::takeBaggage(){
    if(s.size()>0){
        Baggage b = s.top();
        s.pop();
        return b;
    }
    throw emptyBaggageStackException();
}


//__________________________________________________________________________________________

void Carriage::addBaggage(const Baggage& baggage){

    if(isFull()) throw fullCarriageException();

    for(auto it = stacks.begin();it!=stacks.end();it++)
        if(!it->isFull()){
            it->addBaggage(baggage);
            currentCapacity++;
            return;
        }
}

Baggage Carriage::takeBaggage(){

    if(isEmpty()) throw emptyCarriageException();

    for(auto it = stacks.begin();it!=stacks.end();it++)
        if(!it->isEmpty()){
            Baggage b = it->takeBaggage();
            currentCapacity--;
            return b;
        }

    return Baggage();
}



Carriage::Carriage(unsigned stacksNum, unsigned baggageNum){
    maxCapacity = stacksNum * baggageNum;
    maxStackHeight = baggageNum;
    currentCapacity = 0;

    for(int i = 0;i<stacksNum;i++){
        BaggageStack s(baggageNum);
        stacks.push_back(s);
    }
}

//__________________________________________________________________________________________


BaggageTruck::BaggageTruck(unsigned carriagesNum,unsigned stacksNum,unsigned baggageNum){
    maxCapacity = carriagesNum*stacksNum*baggageNum;
    currentCapacity = 0;

    for(unsigned i = 0;i<carriagesNum;i++){
        Carriage c(stacksNum,baggageNum);
        carriages.push_back(c);
    }
}


void BaggageTruck::addBaggage(const Baggage& baggage){
    if(isFull()) throw fullTruckException();

    for(auto it = carriages.begin();it!=carriages.end();it++)
        if(!it->isFull()){
            it->addBaggage(baggage);
        }

    currentCapacity++;
}

Baggage BaggageTruck::takeBagagge(){

    if(isEmpty()) throw emptyTruckException();

    for(auto it = carriages.begin();it!=carriages.end();it++)
        if(!it->isEmpty()){
            Baggage b = it->takeBaggage();
            currentCapacity--;
            return b;
        }
    return Baggage();
}

//__________________________________________________________________________________________

bool BaggageCheckIn::passNextBagaggeToTruck(){
    if(truck.isFull()|| getQueueSize()==0) return false;

    Baggage b =  queueRemove();
    truck.addBaggage(b);

    return true;
}

Baggage BaggageCheckIn::queueRemove(){
    if(getQueueSize()==0) throw emptyQueueException();
    Baggage b = conveyorBelt.front();
    conveyorBelt.pop();
    return b;
}

void BaggageCheckIn::truckAddBaggage(const Baggage& baggage){
    if(!truck.isFull()){
        truck.addBaggage(baggage);
        return;
    }
    throw fullTruckException();
}


Baggage BaggageCheckIn::truckTakeBaggage(){
    if(!truck.isEmpty()){
        return truck.takeBagagge();
    }
    throw emptyTruckException();
}
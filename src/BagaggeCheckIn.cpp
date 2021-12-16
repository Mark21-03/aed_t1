#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <list>
#include <vector>


using namespace std;

//__________________________________________________________________________________________


class EmptyQueueException{
    public:
    EmptyQueueException(){
        cout<<"Cant take anything from an empty Queue!\n";
    };
};

class FullTruckException{
    public:
    FullTruckException(){
        cout<<"Truck cant be filled anymore!\n";
    };
};

class EmptyTruckException{
    public:
    EmptyTruckException(){
        cout<<"Cant take anything from an empty truck!\n";
    };
};

class FullCarriageException{
    public:
    FullCarriageException(){
        cout<<"Carriage cant be filled anymore!\n";
    };
};

class EmptyCarriageException{
    public:
    EmptyCarriageException(){
        cout<<"Cant take anything from an empty carriage!\n";
    };
};

class FullBaggageStackException{
    public:
    FullBaggageStackException(){
        cout<<"BaggageStack cant be filled anymore!\n";
    };
};

class EmptyBaggageStackException{
    public:
    EmptyBaggageStackException(){
        cout<<"Cant take anything from an empty BaggageStack!\n";
    };
};


//__________________________________________________________________________________________

struct Baggage{
    float weight;
    unsigned int quantity;
    bool handheld = false;

    Baggage(){};
    Baggage(float weight, unsigned int quantity){
        this->weight = weight;
        this->quantity = quantity;
    }
    Baggage(float weight, unsigned int quantity, bool handheld){
        this->weight = weight;
        this->quantity = quantity;
        this->handheld = handheld;
    }
    ~Baggage() = default;
};


//__________________________________________________________________________________________

class BaggageStack{
private:
    stack<Baggage> s;
    unsigned maxSize;

public:
    BaggageStack(unsigned MaxSize): maxSize(MaxSize){};

    void addBaggage(const Baggage& baggage);
    Baggage takeBaggage();

    inline bool isFull(){return maxSize==s.size();}
    inline bool isEmpty(){return s.size()==0;}
    inline unsigned getMaxSize(){return maxSize;}
    inline unsigned getCurrentSize(){return s.size();}

};



void BaggageStack::addBaggage(const Baggage& baggage){
    if(s.size()==maxSize) throw FullBaggageStackException();
    s.push(baggage);
}

Baggage BaggageStack::takeBaggage(){
    if(s.size()>0){
        Baggage b = s.top();
        s.pop();
        return b;
    }
    throw EmptyBaggageStackException();
}


//__________________________________________________________________________________________


class Carriage{
private:
    unsigned maxStackHeight,maxCapacity;
    unsigned currentCapacity;
    vector<BaggageStack> stacks;

public:
    Carriage(){};
    Carriage(unsigned stacksNum, unsigned baggageNum);
    inline bool isFull(){return currentCapacity==maxCapacity;}
    inline bool isEmpty(){return (currentCapacity==0);}

    void addBaggage(const Baggage& baggage);
    Baggage takeBaggage();

    inline unsigned getCurrentCapacity(){return currentCapacity;}
    inline unsigned getMaxCapacity(){return maxCapacity;}

};


void Carriage::addBaggage(const Baggage& baggage){

    if(isFull()) throw FullCarriageException();

    for(auto it = stacks.begin();it!=stacks.end();it++)
        if(!it->isFull()){
            it->addBaggage(baggage);
            currentCapacity++;
            return;
        }   
}

Baggage Carriage::takeBaggage(){

    if(isEmpty()) throw EmptyCarriageException();

    for(auto it = stacks.begin();it!=stacks.end();it++)
        if(!it->isEmpty()){
            Baggage b = it->takeBaggage();
            currentCapacity--;
            return b;
        }
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

class BaggageTruck{
private:
    unsigned numCarriages; // c = 2
    unsigned numStacks; // n = 3
    unsigned numBaggage; //m = 4
    unsigned maxCapacity;
    unsigned currentCapacity; 

    vector<Carriage> carriages;
 
public:
    BaggageTruck(){};
    BaggageTruck(unsigned carriagesNum,unsigned stacksNum,unsigned baggageNum);

    inline bool isFull(){return currentCapacity == maxCapacity;}
    inline bool isEmpty(){return (currentCapacity==0);}
    void addBaggage(const Baggage& baggage);
    Baggage takeBagagge();

    inline unsigned getCurrentCapacity(){return currentCapacity;}
    inline unsigned getMaxCapacity(){return maxCapacity;}

};


BaggageTruck::BaggageTruck(unsigned carriagesNum,unsigned stacksNum,unsigned baggageNum){
    maxCapacity = carriagesNum*stacksNum*baggageNum;
    currentCapacity = 0;

    for(unsigned i = 0;i<carriagesNum;i++){
        Carriage c(stacksNum,baggageNum);
        carriages.push_back(c);
    }
}


void BaggageTruck::addBaggage(const Baggage& baggage){
    if(isFull()) throw FullTruckException();

    for(auto it = carriages.begin();it!=carriages.end();it++)
        if(!it->isFull()){
            it->addBaggage(baggage);
        }
    
    currentCapacity++;
}

Baggage BaggageTruck::takeBagagge(){
    
    if(isEmpty()) throw EmptyTruckException();
    
    for(auto it = carriages.begin();it!=carriages.end();it++)
        if(!it->isEmpty()){
            Baggage b = it->takeBaggage();
            currentCapacity--;
            return b;
        }
}



//__________________________________________________________________________________________


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

    inline void setQueue(queue<Baggage> bq){this->conveyorBelt = bq;}
    inline queue<Baggage> getQueue(){return this->conveyorBelt;}
    inline unsigned getQueueSize(){return conveyorBelt.size();}

    bool passNextBagaggeToTruck();

    void truckAddBaggage(const Baggage& baggage);
    Baggage truckTakeBaggage();
    inline BaggageTruck getTruck(){return truck;}

    

};


bool BaggageCheckIn::passNextBagaggeToTruck(){
    if(truck.isFull()|| getQueueSize()==0) return false;
    
    Baggage b =  queueRemove();
    truck.addBaggage(b);

    return true;
}

Baggage BaggageCheckIn::queueRemove(){
    if(getQueueSize()==0) throw EmptyQueueException();
    Baggage b = conveyorBelt.front();
    conveyorBelt.pop();
    return b;
}

void BaggageCheckIn::truckAddBaggage(const Baggage& baggage){
    if(!truck.isFull()){
        truck.addBaggage(baggage);
        return;
    }
    throw FullTruckException();
}


Baggage BaggageCheckIn::truckTakeBaggage(){
    if(!truck.isEmpty()){
        return truck.takeBagagge();
    }
    throw EmptyTruckException();
}

//__________________________________________________________________________________________



ostream& operator<<(ostream& os, Baggage b){
    os<<"Baggage = "<<b.weight<<" x "<<b.quantity;
    return os;
} 

int main(){
    cout<<"Started Program."<<endl;

    Baggage b1;

    BaggageCheckIn f(2,3,4);
    queue<Baggage>q;

    for(int i = 0;i<20;i++){
        Baggage b((i+1)*0.2,24);
        q.push(b);
    }

    f.setQueue(q);

    cout<<f.getQueueSize()<<endl;
    
    f.passNextBagaggeToTruck();

    cout<<f.getQueueSize()<<endl;
    
    b1 = f.truckTakeBaggage();
    
    cout<<b1<<endl;

    cout<<"Ended Program."<<endl;
}
#ifndef AED_T1_BAGGAGECHECKINEXCEPTIONS_H
#define AED_T1_BAGGAGECHECKINEXCEPTIONS_H


#include <iostream>

class emptyQueueException{
public:
    emptyQueueException(){
        std::cout<<"Cant take anything from an empty Queue!\n";
    };
};

class fullTruckException{
public:
    fullTruckException(){
        std::cout<<"Truck cant be filled anymore!\n";
    };
};

class emptyTruckException{
public:
    emptyTruckException(){
        std::cout<<"Cant take anything from an empty truck!\n";
    };
};

class fullCarriageException{
public:
    fullCarriageException(){
        std::cout<<"Carriage cant be filled anymore!\n";
    };
};

class emptyCarriageException{
public:
    emptyCarriageException(){
        std::cout<<"Cant take anything from an empty carriage!\n";
    };
};

class fullBaggageStackException{
public:
    fullBaggageStackException(){
        std::cout<<"BaggageStack cant be filled anymore!\n";
    };
};

class emptyBaggageStackException{
public:
    emptyBaggageStackException(){
        std::cout<<"Cant take anything from an empty BaggageStack!\n";
    };
};


#endif //AED_T1_BAGGAGECHECKINEXCEPTIONS_H

#ifndef AED_T1_BAGGAGECHECKINEXCEPTIONS_H
#define AED_T1_BAGGAGECHECKINEXCEPTIONS_H


#include <iostream>

class EmptyQueueException{
public:
    EmptyQueueException(){
        std::cout<<"Cant take anything from an empty Queue!\n";
    };
};

class FullTruckException{
public:
    FullTruckException(){
        std::cout<<"Truck cant be filled anymore!\n";
    };
};

class EmptyTruckException{
public:
    EmptyTruckException(){
        std::cout<<"Cant take anything from an empty truck!\n";
    };
};

class FullCarriageException{
public:
    FullCarriageException(){
        std::cout<<"Carriage cant be filled anymore!\n";
    };
};

class EmptyCarriageException{
public:
    EmptyCarriageException(){
        std::cout<<"Cant take anything from an empty carriage!\n";
    };
};

class FullBaggageStackException{
public:
    FullBaggageStackException(){
        std::cout<<"BaggageStack cant be filled anymore!\n";
    };
};

class EmptyBaggageStackException{
public:
    EmptyBaggageStackException(){
        std::cout<<"Cant take anything from an empty BaggageStack!\n";
    };
};


#endif //AED_T1_BAGGAGECHECKINEXCEPTIONS_H

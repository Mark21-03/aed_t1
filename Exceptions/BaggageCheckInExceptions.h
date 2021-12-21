#ifndef AED_T1_BAGGAGECHECKINEXCEPTIONS_H
#define AED_T1_BAGGAGECHECKINEXCEPTIONS_H


#include <iostream>

/**
 * Exception for when trying to remove value from empty queue object
 */
class emptyQueueException {
public:
    /**
     * Default Constructor.
     */
    emptyQueueException() {
        std::cout << "Cant take anything from an empty Queue!\n";
    };
};

/**
 * Exception for when trying to insert a value into a already filled Truck object
 */
class fullTruckException {
public:
    /**
     * Default Constructor.
     */
    fullTruckException() {
        std::cout << "Truck cant be filled anymore!\n";
    };
};

/**
 * Exception for when trying to remove value from empty Truck object
 */
class emptyTruckException {
public:
    /**
     * Default Constructor.
     */
    emptyTruckException() {
        std::cout << "Cant take anything from an empty truck!\n";
    };
};

/**
 * Exception for when trying to insert a value into a already filled Carriage object
 */
class fullCarriageException {
public:
    /**
     * Default Constructor.
     */
    fullCarriageException() {
        std::cout << "Carriage cant be filled anymore!\n";
    };
};

/**
 * Exception for when trying to remove a value from empty Carriage object
 */
class emptyCarriageException {
public:
    /**
     * Default Constructor.
     */
    emptyCarriageException() {
        std::cout << "Cant take anything from an empty carriage!\n";
    };
};

/**
 * Exception for when trying to insert a value into a already filled BaggageStack object
 */
class fullBaggageStackException {
public:
    /**
     * Default Constructor.
     */
    fullBaggageStackException() {
        std::cout << "BaggageStack cant be filled anymore!\n";
    };
};

/**
 * Exception for when trying to remove a value from empty BaggageStack object
 */
class emptyBaggageStackException {
public:
    /**
     * Default Constructor.
     */
    emptyBaggageStackException() {
        std::cout << "Cant take anything from an empty BaggageStack!\n";
    };
};


#endif //AED_T1_BAGGAGECHECKINEXCEPTIONS_H

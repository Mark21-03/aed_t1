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


class BaggageStack {
private:
    stack<Baggage> s;
    unsigned maxSize;

public:

    /**
     *  Constructs a BaggageStack object which is a stack with a predefined max capacity
     * @param MaxSize
     */
    explicit BaggageStack(unsigned MaxSize) : maxSize(MaxSize) {};

    /**
     * Adds new Baggage object to stack
     * @param baggage
     */
    void addBaggage(const Baggage &baggage);

    /**
     * Removes Baggage object from top of stack and returns it
     * @return Baggage object popped from the top of the stack
     */
    Baggage takeBaggage();

    /**
     * Tests if stack as reached max capacity
     * @return boolean returns true if full else false
     */
    inline bool isFull() { return maxSize == s.size(); }

    /**
     * Tests if stack is empty
     * @return boolean returns true if empty else false
     */
    inline bool isEmpty() { return s.empty(); }

    /**
     * Returns the max capacity of the stack
     * @return max stack capacity
     */
    inline unsigned getMaxSize() const { return maxSize; }

    /**
     * Gives current stacks size
     * @return current stacks size
     */
    inline unsigned getCurrentSize() { return s.size(); }

};


class Carriage {
private:
    unsigned maxStackHeight = 0;
    unsigned maxCapacity = 0;
    unsigned currentCapacity = 0;
    vector<BaggageStack> stacks;

public:

    /*
     * Default constructor
     */
    Carriage() = default;

    /**
     * Creates Carriage object which is made of 1 or more BaggageStacks
     * @param stacksNum number of BaggageStacks to be created in the Carriage
     * @param baggageNum max capacity/height of the BaggageStacks created
     */
    Carriage(unsigned stacksNum, unsigned baggageNum);

    /**
     * Tests if all BaggageStacks in the Carriage object are full
     * @return boolean returns true if Carriage is full else false
     */
    inline bool isFull() const { return currentCapacity == maxCapacity; }

    /**
     * Tests if Carriage is empty
     * @return boolean returns true if empty else false
     */
    inline bool isEmpty() const { return (currentCapacity == 0); }

    /**
     * Adds Baggage to one of Carriage's not full BaggageStacks
     * @param baggage Baggage object to be added
     */
    void addBaggage(const Baggage &baggage);

    /**
     * Removes a Baggage object from one of the not empty BaggageStacks in the Carriage
     * @return removed Baggage object
     */
    Baggage takeBaggage();

    /**
     * Gives current capacity of the Carriage, thus the product of the current capacity of each
     * BaggageStack by the number of BaggageStack in the Carriage
     * @return number of Baggage objects inside the Carriage
     */
    inline unsigned getCurrentCapacity() const { return currentCapacity; }

    /**
     * Gives max capacity of the Carriage, thus the product of the max capacity of each
     * BaggageStack by the number of BaggageStack in the Carriage
     * @return max possible number of Baggage objects in the Carriage
     */
    inline unsigned getMaxCapacity() const { return maxCapacity; }

};


class BaggageTruck {
private:
    unsigned numCarriages = 0;
    unsigned numStacks = 0;
    unsigned numBaggage = 0;
    unsigned maxCapacity = 0;
    unsigned currentCapacity = 0;

    vector<Carriage> carriages;

public:

    /**
     * Default Constructor
     */
    BaggageTruck() = default;

    /**
     * Creates a Truck object composed of Carriage objects which itself is also composed by BaggageStacks
     * @param carriagesNum Number of carriages to be created
     * @param stacksNum Number of BaggageStacks inside each Carriage
     * @param baggageNum Max height/size of each BaggageStack
     */
    BaggageTruck(unsigned carriagesNum, unsigned stacksNum, unsigned baggageNum);


    /**
     * Tests if all Carriage objects inside the truck are full
     * @return boolean returns true if truck is full else false
     */
    inline bool isFull() const { return currentCapacity == maxCapacity; }

    /**
     * Tests if all Carriages in the truck
     * @return boolean returns true if empty else false
     */
    inline bool isEmpty() const { return (currentCapacity == 0); }

    /**
     * Adds new Baggage object to one of the truck's Carriages
     * @param baggage object to be added
     */
    void addBaggage(const Baggage &baggage);

    /**
     * Removes a Baggage object from the truck (one of its carriages)
     * @return removed Baggage object
     */
    Baggage takeBagagge();

    /**
     * Gives the sum of all truck's Carriages capacity, thus the
     * number of Baggage objects inside the truck
     * @return number of Baggage objects in the truck
     */
    inline unsigned getCurrentCapacity() const { return currentCapacity; }

    /**
     * Gives the sum of all truck's Carriages max capacity
     * @return max number of Baggage objects that truck object can hold
     */
    inline unsigned getMaxCapacity() const { return maxCapacity; }

};

/**
 * Creates a conveyor belt (queue) and a Truck (multiple stacks)
 * to hold and process Baggage objects during a Check In
 */
class BaggageCheckIn {
private:
    queue<Baggage> conveyorBelt;
    BaggageTruck truck;
public:

    /**
     * Constructs a BaggageCheckIn object which has a conveyorBelt and a Truck
     * @param carriagesNum Number of Carriages to be created in the truck
     * @param stacksNum Number of BaggageStacks inside each Carriage
     * @param baggageNum Max height/size of each BaggageStack
     */
    explicit BaggageCheckIn(unsigned carriagesNum, unsigned stacksNum, unsigned baggageNum) {
        BaggageTruck t(carriagesNum, stacksNum, baggageNum);
        this->truck = t;
    }

    /**
     * Adds a new Baggage object to the conveyorBelt queue
     * @param baggage object to be added
     */
    inline void queueAdd(const Baggage &baggage) { conveyorBelt.push(baggage); }

    /**
     * Removes the front of the conveyorBelt queue Baggage object
     * @return removed Baggage object
     */
    Baggage queueRemove();

    /**
     * Gets the last Baggage object added to the conveyorBelt queue
     * @return last Baggage object in the queue
     */
    inline Baggage queueBack() { return conveyorBelt.back(); }

    /**
     * Gets the first Baggage object in he conveyorBelt queue
     * @return first Baggage object in the queue
     */
    inline Baggage queueFront() { return conveyorBelt.front(); }

    /**
     * Tests if conveyorBelt queue is empty
     * @return boolean true if empty else false
     */
    inline bool queueEmpty() { return conveyorBelt.empty(); }

    /**
     * Replaces conveyorBelt queue with given queue object
     * @param bq Given queue to be set
     */
    inline void setQueue(const queue<Baggage>& bq) { this->conveyorBelt = bq; }

    /**
     * Gives a copy of the current conveyorBelt queue
     * @return conveyorBelt's copy
     */
    inline queue<Baggage> getQueue() { return this->conveyorBelt; }

    /**
     * Gives the current number of Baggage objects in the conveyorBelt queue
     * @return number of Baggage objects in the queue
     */
    inline unsigned getQueueSize() { return conveyorBelt.size(); }

    /**
     * Tries to remove the first Baggage object in the conveyorBelt queue and add it to the truck
     * verifying in the process if queue is empty or truck is full
     * @return boolean true if it was able to pass Baggage object from queue to truck else false
     */
    bool passNextBagaggeToTruck();

    /**
     * Adds Baggage object directly to the truck
     * @param baggage
     */
    void truckAddBaggage(const Baggage &baggage);

    /**
     * Tests if all Carriage objects inside the truck are full
     * @return boolean returns true if truck is full else false
     */
    inline bool isTruckFull() { return truck.isFull(); }

    /**
     * Removes a Baggage from one of Truck's Carriages
     * @return removed Baggage object
     */
    Baggage truckTakeBaggage();

    /**
     * Gives a copy of the Truck object
     * @return Truck object's copy
     */
    inline BaggageTruck getTruck() { return truck; }


};


#endif //AED_T1_BAGAGGECHECKIN_H

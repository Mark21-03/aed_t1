#ifndef AED_T1_BAGGAGE_H
#define AED_T1_BAGGAGE_H


#include <iostream>

class Baggage{
private:
    float weight;
    unsigned quantity;
    bool handheld = false;
public:

    /**
     * Constructs empty Baggage
     */
    Baggage(){weight = 0;quantity = 0;};

    /**
     * Constructs a Baggage object with weight and quantity
     * @param weight Sum of Baggage's weight
     * @param quantity Number of Baggage
     */
    inline Baggage(float weight, unsigned int quantity){
        this->weight = weight;
        this->quantity = quantity;
    }

    /**
     * Constructs a Baggage object with weight, quantity and
     * if its transported with it's passenger
     * @param weight Sum of Baggage's weight
     * @param quantity Number of Baggage
     * @param handheld hand Baggage boolean
     */
    inline Baggage(float weight, unsigned int quantity, bool handheld){
        this->weight = weight;
        this->quantity = quantity;
        this->handheld = handheld;
    }

    /**
     * Gives boolean telling if Baggage is handheld
     * @return boolean true if passenger takes the Baggage with him
     */
    inline bool getHandheld() const {return handheld;}

    /**
     * Gives the weight of the Baggage
     * @return  Baggage's weight
     */
    inline float getWeight() const {return weight;}

    /**
     * Gives the number of Baggage
     * @return number of Baggage
     */
    inline unsigned getQuantity() const {return quantity;}

    /**
     * Sets the weight of the Baggage
     * @param weight value to be set
     */
    inline void setWeight(const float& weight){this->weight = weight;}

    /**
     * Sets the number of the Baggage
     * @param quantity value to be set
     */
    inline void setQuantity(const unsigned & quantity){this->quantity = quantity;}

    /**
     * Sets if Baggage is taken with the passenger
     * @param handheld boolean value to be set
     */
    inline void setHandheld(const bool& handheld){this->handheld = handheld;}
};

/**
 * Outputs Baggage object to ostream
 * @param os ostream to be used
 * @param b Baggage object tio be outputted
 * @return ostream used (changed)
 */
inline std::ostream& operator<<(std::ostream& os, Baggage b){
    os<<"Baggage = "<<b.getWeight()<<" x "<<b.getQuantity();
    return os;
}


#endif //AED_T1_BAGGAGE_H

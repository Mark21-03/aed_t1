#ifndef AED_T1_BAGGAGE_H
#define AED_T1_BAGGAGE_H


#include <iostream>

/**
 * A class that represents a baggage or baggage's transported by a passenger.
 */
class Baggage {
private:
    /**
     * A variable that represents the weight of a baggage.
     */
    float weight;
    /**
     * A variable that represents the quantity of baggage's transported.
     */
    unsigned quantity;
    /**
     * A Bool telling if the baggage's should go to the airplane basement or not.
     */
    bool handheld = false;
public:

    /**
     * Constructs empty Baggage
     */
    Baggage() {
        weight = 0;
        quantity = 0;
    };

    /**
     * Constructs a Baggage object with weight and quantity
     * @param weight Sum of Baggage's weight
     * @param quantity Number of Baggage
     */
    inline Baggage(float weight, unsigned int quantity) {
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
    inline Baggage(float weight, unsigned int quantity, bool handheld) {
        this->weight = weight;
        this->quantity = quantity;
        this->handheld = handheld;
    }

    /**
     * Gives boolean telling if Baggage is handheld
     * @return boolean true if passenger takes the Baggage with him
     */
    inline bool getHandheld() const { return handheld; }

    /**
     * Gives the weight of the Baggage
     * @return  Baggage's weight
     */
    inline float getWeight() const { return weight; }

    /**
     * Gives the number of Baggage
     * @return number of Baggage
     */
    inline unsigned getQuantity() const { return quantity; }

    /**
     * Sets the weight of the Baggage
     * @param newWeight value to be set
     */
    inline void setWeight(const float &newWeight) { this->weight = newWeight; }

    /**
     * Sets the number of the Baggage
     * @param newQuantity value to be set
     */
    inline void setQuantity(const unsigned &newQuantity) { this->quantity = newQuantity; }

    /**
     * Sets if Baggage is taken with the passenger
     * @param newHandheld boolean value to be set
     */
    inline void setHandheld(const bool &newHandheld) { this->handheld = newHandheld; }
};

/**
 * Outputs Baggage object to ostream
 * @param os ostream to be used
 * @param b Baggage object tio be outputted
 * @return ostream used (changed)
 */
inline std::ostream &operator<<(std::ostream &os, Baggage b) {
    os << b.getWeight() << " " << b.getQuantity();
    return os;
}

/**
 * Outputs Baggage object to ostream
 * @param os ostream to be used
 * @param b Baggage object tio be outputted
 * @return ostream used (changed)
 */
inline std::istream &operator>>(std::istream &is, Baggage &b) {
    float w;
    unsigned q;
    is >> w >> q;

    b.setWeight(w);
    b.setQuantity(q);

    return is;
}


#endif //AED_T1_BAGGAGE_H

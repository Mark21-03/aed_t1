#ifndef AED_T1_BAGGAGE_H
#define AED_T1_BAGGAGE_H


#include <iostream>

class Baggage{
private:
    float weight;
    unsigned quantity;
    bool handheld = false;
public:
    Baggage(){weight = 0;quantity = 0;};
    inline Baggage(float weight, unsigned int quantity){
        this->weight = weight;
        this->quantity = quantity;
    }
    inline Baggage(float weight, unsigned int quantity, bool handheld){
        this->weight = weight;
        this->quantity = quantity;
        this->handheld = handheld;
    }

    inline bool getHandheld() const {return handheld;}
    inline float getWeight() const {return weight;}
    inline unsigned getQuantity() const {return quantity;}

    inline void setWeight(const float& weight){this->weight = weight;}
    inline void setQuantity(const unsigned & quantity){this->quantity = quantity;}
    inline void setHandheld(const bool& handheld){this->handheld = handheld;}
};

inline std::ostream& operator<<(std::ostream& os, Baggage b){
    os<<"Baggage = "<<b.getWeight()<<" x "<<b.getQuantity();
    return os;
}


#endif //AED_T1_BAGGAGE_H

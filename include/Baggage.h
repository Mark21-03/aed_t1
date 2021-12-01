#ifndef BAGGAGE_H
#define BAGGAGE_H

#include <queue>

class Baggage{
private:
   float weight;
   float length;
   float width;
   float thickness;
public:
    Baggage(float weight, float length, float width, float thickness);
    void setWeight(float weight);
    void setLength(float length);
    void setWidth(float width);
    void setThickness(float thickness);

    float getWeight() const;
    float getLength() const;
    float getWidth() const;
    float getThickness() const;

};

#endif //BAGGAGE_H

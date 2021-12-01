#include "../include/Baggage.h"

Baggage::Baggage(float weight, float length, float width, float thickness) {
    this->weight=weight;
    this->length=length;
    this->width=width;
    this->thickness=thickness;
}

//setters
void Baggage::setLength(float length) {this->length=length;}
void Baggage::setThickness(float thickness) {this->thickness=thickness;}
void Baggage::setWeight(float weight) {this->weight=weight;}
void Baggage::setWidth(float width) {this->width=width;}

//getters
float Baggage::getLength() const {return this->length;}
float Baggage::getThickness() const {return this->thickness;}
float Baggage::getWeight() const {return this->weigth;}
float Baggage::getWidth() const {return this->width;}

//fazer funçao com restriçao de peso, comprimento, tamanho, profundidade

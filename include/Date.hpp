#pragma once

#include "DateException.hpp"
#include <iostream>
#include <string>
#include <sstream> //alows stringstream

using namespace std;

class Date{
    private: 
        int day;
        int month;
        int year;
        string acceptedSep = "/-";

    public:
    Date(){}
    ~Date(){}
    Date(int day, int month, int year);
    Date(string date);

    inline int getDay() const{return this->day;}
    inline int getMonth() const{return this->month;}
    inline int getYear() const{return this->year;}

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int day, int month, int year);
    void setDate(string date);



};

ostream& operator<<(ostream &out,Date &date);

istream& operator>>(istream &in,Date &date);

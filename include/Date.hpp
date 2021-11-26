#pragma once

#include <iostream>
#include <string>
#include <sstream> //alows stringstream

using namespace std;

class Date{
    private: 
        int day;
        int month;
        int year;

    public:
    Date(){}
    ~Date(){}
    Date(int day, int month, int year);
    Date(string date);

    int getDay(){return this->day;}
    int getMonth(){return this->month;}
    int getYear(){return this->year;}

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year){this->year = year;}

    void setDate(int day, int month, int year){
        setDay(day);setMonth(month);setYear(year);
    }

};

//custom Exception
class InvalidDateException: public exception{
    public:
        InvalidDateException(){
            cout<<"Invalid Date!"<<endl;
        }
        InvalidDateException(const char*errorMsg){
            cout<<errorMsg<<endl;
        }
};


ostream& operator<<(ostream &out,Date &date);

istream& operator>>(istream &in,Date &date);

#include "Date.hpp"

Date::Date(int day, int month, int year){
    this->setDate(day, month, year);
}

Date::Date(string date){
    /*
        this->day = stoi(s.substr(0, s.find('/')));
        s = s.substr(s.find('/') + 1);
        month = stoi(s.substr(0, s.find('/')));
        s = s.substr(s.find('/') + 1);
        this->year = stoi(s);
    */
    istringstream inStr (date);
    int year,month,day;
    char sep;
    inStr>>day>>sep;
    if(sep=='/' or sep=='-'){
        inStr>>month>>sep>>year;
        if(sep=='/' or sep=='-')
            setDate(day,month,year);
        else
            throw InvalidDateException("Wrong Format. Use DD/MM/YYYY");
    }else
        throw InvalidDateException("Wrong Format. Use DD/MM/YYYY");
}


void Date::setDay(int day){
    if(day>=1 && day<=31)
        this->day = day;
    else 
        throw InvalidDateException("Invalid Day. Must be between 1 and 31.");
}

void Date::setMonth(int month){
    if(month>=1 && month<=12)
        this->month = month;
    else 
        throw InvalidDateException("Invalid Month. Must be between 1 and 12.");
}

ostream& operator<<(ostream &out,Date &date){
    out<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear();
    return out;
}

istream& operator>>(istream &in,Date &date){
    int day,month,year;
    in>>day>>month>>year;
    date.setDate(day,month,year);
    return in;
}






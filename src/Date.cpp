#include "Date.hpp"

Date::Date(int day, int month, int year){
    this->setDate(day, month, year);
}

Date::Date(string date){
    setDate(date);
}


void Date::setDay(int day){
    if(day>=1 && day<=31)
        this->day = day;
    else
        throw InvalidDateException("Invalid Day. Must be between 1 and 31. Value provided: ",day);
}

void Date::setDate(int day, int month, int year){
    setDay(day);setMonth(month);setYear(year);
}

void Date::setMonth(int month){
    if(month>=1 && month<=12)
        this->month = month;
    else{
        throw InvalidDateException("Invalid Month. Must be between 1 and 12. Value provided: ",month);
    }

}

void Date::setYear(int year) {
    if(year>=0)
        this->year = year;
    else{
        throw InvalidDateException("Invalid Year. Must be between >=0. Value provided: ",year);
    }

}

void Date::setDate(string date) {

    istringstream inStr (date);
    int year,month,day;
    char sep;bool validSep;



    inStr>>day>>sep;
    validSep= acceptedSep.find(sep)!=string::npos;

    if(validSep)
    {
        inStr>>month>>sep>>year;
        validSep= acceptedSep.find(sep)!=string::npos;

        if(validSep){
            inStr>>year;setDate(day,month,year);
        }
        else
            throw InvalidDateException("Wrong Format. Use DD/MM/YYYY.");
    }else
        throw InvalidDateException("Wrong Format. Use DD/MM/YYYY.");
}


ostream& operator<<(ostream &out,Date &date){
    out<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear();
    return out;
}

istream& operator>>(istream &in,Date &date){
    string input;
    in>>input;
    date.setDate(input);
    return in;
}






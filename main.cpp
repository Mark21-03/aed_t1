#include <iostream>
//#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include <vector>

#include "include/Date.h"
#include "include/Plane.h"

using namespace std;

int main(){

    Date d;
    cout<<d<<endl;

    Flight f(21368,d,12.3,"Lisbon","Porto");
    vector<Flight> v = {f};

    Plane a("A134",213,v);

    string str = a.getFlightPlan()[0].getOrigin();

    cout<<str<<endl;

}
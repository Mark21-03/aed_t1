#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <vector>

#include "include/Date.h"
#include "include/Plane.h"
#include "include/Passenger.h"

int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);

    Date d;
    std::cout<<d<<std::endl;

    Flight f(21368,d,12.3,"Lisbon","Porto");
    vector<Flight> v = {f};

    Plane a("A134",213,v);

    string str = a.getFlightPlan()[0].getOrigin();

    std::cout<<str<<std::endl;

    Passenger me(293939,"Ricardo");

    std::cout << me.getName() << std::endl;


    return RUN_ALL_TESTS();
}
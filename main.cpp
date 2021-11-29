#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "include/Date.h"
#include "include/Plane.h"
#include "include/Passenger.h"
#include "include/BST.h"

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){

    testing::InitGoogleTest(&argc, argv);

    Date d;
    std::cout<<d<<std::endl;

    BST<int> bst;

    for(int i=0;i<100;i++) bst.insert(i);

    cout<<bst.find(200)<<endl;
    cout<<bst.findMax()<<endl;


    Flight f(21368,d,12.3,"Lisbon","Porto");
    vector<Flight> v = {f};

    Plane a("A134",213,v);

    string str = a.getFlightPlan()[0].getOrigin();

    std::cout<<str<<std::endl;

    Passenger passenger1(293939,"Ricardo");

    std::cout << passenger1.getName() << std::endl;


    return RUN_ALL_TESTS();
}
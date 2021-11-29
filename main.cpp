#include <iostream>
//#include "gtest/gtest.h"
//#include "gmock/gmock.h"

#include <vector>

#include "include/Date.h"
#include "include/Plane.h"
#include "include/binaryTree.h"
#include "include/bst.h"

using namespace std;

int main(){

    BST<int> bst;
    BinaryTree<int> bt;


    for(int i=0;i<100;i++) bst.insert(i);

    cout<<bst.find(200)<<endl;
    cout<<bst.findMax()<<endl;



    Date d(2013,07,23);
    cout<<d<<endl;

    Flight f(21368,d,12.3,"Lisbon","Porto");
    vector<Flight> v = {f};

    Plane a("A134",213,v);

    string str = a.getFlightPlan()[0].getOrigin();

    cout<<str<<endl;

}
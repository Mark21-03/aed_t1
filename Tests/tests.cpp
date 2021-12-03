#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include "../include/Passenger.h"
#include "../include/ServiceManagement.h"

using testing::Eq;


TEST(test_Passenger, genericTestOnClassPassenger) {

    Passenger aP(123456789, "Joaquim");

    ASSERT_EQ(aP.getName(), "Joaquim");
    ASSERT_EQ(aP.getID(), 123456789);

    aP.setName("Ricardo");
    aP.setID(1345);

    ASSERT_EQ(aP.getName(), "Ricardo");
    ASSERT_EQ(aP.getID(), 1345);

}

TEST(test_ticket_passenger, passengerBuyingTickets) {

    Passenger aP(123456789, "Joaquim");

    Date d;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Ticket at(f);

    aP.addTicket(at);

    Ticket r = aP.getNextFlights().front();
    ASSERT_EQ(r, at
    );

}

TEST(test_Passenger_Record, passengerOperator) {

    Passenger aP(123456789, "Joaquim Andre Araujo de Matos ");

    Date d;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, 3.5, "Porto", "Lisbon");

    Ticket at(f);
    Ticket at2(f2);

    aP.addTicket(at);
    aP.addTicket(at2);
    cout << aP ;
}

TEST(test_creation_of_recordsOfFlights, inoutOperator) {
    Passenger aP(123456789, "Joaquim Andre Araujo de Matos ");
    Passenger aP2(12002, "Orlando Manuel da Silva Pinto");

    Date d;
    vector<Flight> v;

    ifstream ifs("../Files/Flights/flights.txt");


    Flight flight;
    Flight f(140, d, 3.5, "Porto", "Lisbon");
    Flight f2(160, d, 6.5, "Porto", "Roma");

    while(ifs >> flight) {
        v.push_back(flight);
    }

    Ticket at(v[0]);
    Ticket at2(v[1]);

    aP.addTicket(at);
    aP.addTicket(at2);

    std::ofstream ofs("../Files/Passengers/passengers.txt", ios::app);
    std::ofstream ofsF("../Files/Flights/flights.txt", ios::app);


    ASSERT_EQ(v[0].getOrigin(), "Porto");
    ASSERT_EQ(v[0].getDestiny(), "Lisbon");
    //ofs << aP << aP2;
    //ofsF << f << f2;

}

TEST(Test_In_Passenger, inOperatorsPassenger) {

    stringstream s("21345 Andre");
    Passenger p;
    s>>p;
    ASSERT_EQ(p.getID(),21345);
    ASSERT_EQ(p.getName(),"Andre");

}

TEST(Test_Compare_Passenger, CompareOperatorsPassenger) {

    Passenger p1(12357,"Marco");
    Passenger p2(12357,"André");
    Passenger p3(9305,"Carlos");

    ASSERT_EQ(p1 == p2,true);
    ASSERT_EQ(p1!=p2,false);
    ASSERT_EQ(p1<p2,false);
    ASSERT_EQ(p2 == p3,false);
    ASSERT_EQ(p1!=p3,true);
    ASSERT_EQ(p3<p2,true);

}

TEST(Test_ServiceManagement, OperatorsManagement) {

    Date d1("2012/03/21");
    Date d2("2018/11/29");
    Date d3("2021/03/01");
    Service s1('c',d1,"Rui Rocha");
    Service s2('o',d2,"Pedro Moreira");
    Service s3('m',d3,"Alfredo Costa");

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;


}
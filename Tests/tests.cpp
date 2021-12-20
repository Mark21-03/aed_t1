#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <fstream>
#include <algorithm>
#include "../include/Passenger.h"
#include "../include/ServiceManagement.h"
#include "../include/Manager.h"

using testing::Eq;


//__________________________________________DONE______TESTS_________________________________________________




TEST(Test_Passenger, TestClassPassengerGetterSetter) {

    Passenger p2(141211, "Carlos", Date("2021/12/13"));

    EXPECT_EQ(p2.getName(), "Carlos");
    EXPECT_EQ(p2.getID(), 141211);
    EXPECT_EQ(p2.getBirthDate().getDate(), "2021/12/13");

    p2.setName("Diogo");
    p2.setID(1340);
    p2.setBirth(Date("1998/01/02"));

    EXPECT_EQ(p2.getName(), "Diogo");
    EXPECT_EQ(p2.getID(), 1340);
    EXPECT_EQ(p2.getBirthDate().getDate(), "1998/01/02");

}


TEST(Test_Passenger, TestClassPassengerCompare) {

    Passenger p(123456789, "Joaquim");

    p.setName("Ricardo");
    p.setID(1345);

    Passenger p2(141211, "Carlos", Date("2021/12/13"));

    EXPECT_EQ(p2.getName(), "Carlos");
    EXPECT_EQ(p2.getID(), 141211);
    EXPECT_EQ(p2.getBirthDate().getDate(), "2021/12/13");

    p2.setName("Diogo");
    p2.setID(1340);
    p2.setBirth(Date("1998/01/02"));

    EXPECT_EQ(p2.getName(), "Diogo");
    EXPECT_EQ(p2.getID(), 1340);
    EXPECT_EQ(p2.getBirthDate().getDate(), "1998/01/02");

    EXPECT_EQ(p2 < p, true);
    EXPECT_EQ(p == p2, false);

}


TEST(Test_Baggage, TestClassBaggage) {

    Baggage b1;

    EXPECT_EQ(b1.getHandheld(), false);
    EXPECT_EQ(b1.getWeight(), 0);
    EXPECT_EQ(b1.getQuantity(), 0);

    b1.setWeight(5.17);
    b1.setHandheld(true);
    b1.setQuantity(7);

    EXPECT_EQ(b1.getHandheld(), true);
    EXPECT_EQ(b1.getWeight(), (float) 5.17);
    EXPECT_EQ(b1.getQuantity(), 7);

    Baggage b2(10.23, 3);

    EXPECT_EQ(b2.getHandheld(), false);
    EXPECT_EQ(b2.getWeight(), (float) 10.23);
    EXPECT_EQ(b2.getQuantity(), 3);

}


TEST(Test_Service, TestClassServiceGetterSetter) {

    Service s1(maintenance, Date("2012/06/29"), "Joaquim Moreira", "CS-TKK");

    EXPECT_EQ(s1.getType(), 'm');
    EXPECT_EQ(s1.getDate().getDate(), "2012/06/29");
    EXPECT_EQ(s1.getEmployer(), "Joaquim Moreira");
    EXPECT_EQ(s1.getPlane(), "CS-TKK");

    s1.setType(cleaning);
    s1.setDate(Date("1999/12/12"));
    s1.setEmployer("Maria Eduarda");
    s1.setPlate("CL-BCD");

    EXPECT_EQ(s1.getType(), 'c');
    EXPECT_EQ(s1.getDate().getDate(), "1999/12/12");
    EXPECT_EQ(s1.getEmployer(), "Maria Eduarda");
    EXPECT_EQ(s1.getPlane(), "CL-BCD");

}


TEST(Test_Service, TestClassServiceCompare) {

    Service s1(maintenance, Date("2012/06/29"), "Joaquim Moreira", "CS-TKK");

    s1.setType(cleaning);
    s1.setDate(Date("1999/12/12"));
    s1.setEmployer("Maria Eduarda");
    s1.setPlate("CL-BCD");

    Service s2(cleaning, Date("1999/12/12"), "John Rodriguez", "CL-BCD");

    EXPECT_EQ(s1 == s2, false);
    EXPECT_EQ(s1 != s2, true);

    s2.setEmployer("Maria Eduarda");

    EXPECT_EQ(s1 == s2, true);
    EXPECT_EQ(s1 != s2, false);

    s1.setDate(Date("2010/12/12"));

    EXPECT_EQ(s2 < s1, true);

}


TEST(Test_Passenger, CompareOperatorsPassenger) {

    Passenger p1(12357, "Marco");
    Passenger p2(12357, "André");
    Passenger p3(9305, "Carlos");

    EXPECT_EQ(p1 == p2, true);
    EXPECT_EQ(p1 != p2, false);
    EXPECT_EQ(p1 < p2, false);
    EXPECT_EQ(p2 == p3, false);
    EXPECT_EQ(p1 != p3, true);
    EXPECT_EQ(p3 < p2, true);

}


TEST(Test_Passenger, PassengerFile) {

    ifstream s("../Files/passengers.txt");
    Passenger p;
    s >> p;

    EXPECT_EQ(p.getID(), 0);
    EXPECT_EQ(p.getName(), "Frederica Neves");

}


TEST(Test_TransportTree, TransportMap) {

    map<string, BST<Transport>> airportTransports;
    std::ifstream ifs_transports("../Files/transports.txt");
    std::string airport;

    while (getline(ifs_transports, airport)) {
        int n;
        ifs_transports >> n;
        Transport transport;
        BST<Transport> tTree;
        while (n > 0) {
            ifs_transports >> transport;
            tTree.insert(transport);
            n--;
        }
        airportTransports.insert(pair<std::string, BST<Transport>>(airport, tTree));
    }

    ifs_transports.close();

}


TEST(Test_ServiceManagement, OperatorsManagement) {

    Date d1("2012/03/21");
    Date d2("2018/11/29");
    Date d3("2021/03/01");
    Service s1('c', d1, "Rui Rocha", "CS-AKJ");
    Service s2('o', d2, "Pedro Moreira", "CS-AKJ");
    Service s3('m', d3, "Alfredo Costa", "CS-AKJ");


    istringstream istringstream1("99 2012/03/21Rui Rocha                                    CS-AKJ");

    Service s;
    istringstream1 >> s;

    EXPECT_EQ(s.getType(), cleaning);
    EXPECT_EQ(s.getDate().getDate(), "2012/03/21");

}


TEST(Test_Time, TimeGetSetException) {

    Time t1(21, 12, 59);

    EXPECT_EQ(t1.getHour(), 21);
    EXPECT_EQ(t1.getMinute(), 12);
    t1.setTime(1, 2, 0);
    EXPECT_EQ(t1.getSecond(), 0);

    // Current Time
    Time r;
    cout << "Current time is " << r;

    try {
        Time t2(24, 0, 0);
        EXPECT_EQ(true, false); //this should never run
    } catch (InvalidTimeException) {
        NULL;
    }
    try {
        Time t2(1, 61, 0);
        EXPECT_EQ(true, false); //this should never run
    } catch (InvalidTimeException) {
        NULL;
    }
    try {
        Time t2(-1, 0, 60);
        EXPECT_EQ(true, false); //this should never run
    } catch (InvalidTimeException) {
        NULL;
    }

}


TEST(Test_Time, TimeOverloading) {

    Time t1(21, 12, 0);
    Time t2(21, 12, 45);

    EXPECT_EQ(t1 < t2, true);
    t1.setSecond(48);
    EXPECT_EQ(t1 < t2, false);
    EXPECT_EQ(t1 != t2, true);
    t1.setTime(21, 12, 45);
    EXPECT_EQ(t1 == t2, true);
    EXPECT_EQ(t1 <= t2, true);

}


TEST(Test_Plane, InOutOperators) {
    std::list<flightNumber> lF{0, 30, 40};
    Plane plane("CS-AKJ", "A321", 200, lF);

    std::ifstream ifs("../Files/planes.txt");

    Plane plane2;

    ifs >> plane2;

    EXPECT_EQ(plane.getNumberPlate(), plane2.getNumberPlate());
    EXPECT_EQ(plane.getCapacity(), plane2.getCapacity());

    ifs.close();
}


TEST(Test_Plane, TestClassPlane) {

    std::list<flightNumber> fp = {20, 40, 50};
    Plane p1("B11", "A00", 140, fp);

    EXPECT_EQ(p1.getCapacity(), 140);
    EXPECT_EQ(p1.getNumberPlate(), "B11");
    EXPECT_EQ(p1.getFlightPlan(), fp);

    p1.setCapacity(210);
    p1.setNumberPlate("A10");
    p1.setFlightPlan({10, 30, 40});

    list<flightNumber> lTest = {10, 30, 40};

    EXPECT_EQ(p1.getFlightPlan(), lTest);
    EXPECT_EQ(p1.getNumberPlate(), "A10");
    EXPECT_EQ(p1.getCapacity(), 210);

}


TEST (Test_Plane, CompareOperatorsPlane) {
    Plane p1("B00", "rr", 150, {10, 30});
    Plane p2("A80", "rr", 260, {10, 30});
    Plane p3("B00", "rr", 300, {40, 70, 80});

    EXPECT_EQ(p1 == p3, true);
    EXPECT_EQ(p1 != p3, false);
    EXPECT_EQ(p1 < p3, false);
    EXPECT_EQ(p2 == p3, false);
    EXPECT_EQ(p2 < p3, true);
    EXPECT_EQ(p1 != p2, true);
    EXPECT_EQ(p1 < p2, false);
}


TEST(Test_Plane, inOperatorsPlane) {

    ifstream i("../Files/planes.txt");
    Plane p1;
    i >> p1;
    EXPECT_EQ(p1.getNumberPlate(), "CS-AKJ");
    EXPECT_EQ(p1.getCapacity(), 200);
    EXPECT_EQ(p1.getFlightPlan().size(), 6);

}


TEST(Test_Passenger, inOperatorsPassenger) {

    ifstream i("../Files/passengers.txt");
    Passenger p;
    i >> p;

    EXPECT_EQ(p.getID(), 0);
    EXPECT_EQ(p.getName(), "Frederica Neves");
    EXPECT_EQ(p.getBirthDate().getDate(), "1942/05/05");

}


TEST(Test_Ticket, inOperatorsTicket) {

    ifstream i("../Files/tickets.txt");
    Ticket t;
    i >> t;

    // 0 0 101 469.18 5.00 1

    Baggage b(5, 1);

    EXPECT_EQ(t.getFlightNumber(), 0);
    EXPECT_EQ(t.getPassengerID(), 0);
    EXPECT_EQ(t.getTClass(), economic);
    EXPECT_EQ(t.getPrice(), (float) 469.18);
    EXPECT_EQ(t.getBaggage().getQuantity(), b.getQuantity());
    EXPECT_EQ(t.getBaggage().getWeight(), b.getWeight());

}


TEST(Test_Service, inOperatorsService) {

    ifstream i("../Files/services.txt");
    string n;
    getline(i, n);

    Service s;
    i >> s;

    EXPECT_EQ(s.getType(), cleaning);
    EXPECT_EQ(s.getDate().getDate(), "2021/12/21");
    EXPECT_EQ(s.getEmployer(), "Denise Alana Cunha Machado");
    EXPECT_EQ(s.getPlane(), "CS-HLH");

}


TEST(Test_Flight, inOperatorsFlight) {

    ifstream i("../Files/flights.txt");
    Flight f;
    i >> f;

    EXPECT_EQ(f.getNumber(), 0);
    EXPECT_EQ(f.getDepartureDate().getDate(), "2022/01/12");
    EXPECT_EQ(f.getDepartureTime(), Time(06, 49, 50));
    EXPECT_EQ(f.getOccupation(), 158);
    EXPECT_EQ(f.getDuration(), (float) 2.19535);
    EXPECT_EQ(f.getOrigin(), "Beirut Rafic Hariri International Airport");
    EXPECT_EQ(f.getDestiny(), "Cairo International Airport");
    EXPECT_EQ(f.getMaxCapacity(), 170);


}


TEST(Test_Transport, inOperatorsTransport) {

    ifstream i("../Files/transports.txt");
    string n;
    getline(i, n);
    getline(i, n);

    Transport t;
    i >> t;

    EXPECT_EQ(t.getType(), 'B');
    EXPECT_EQ(t.getDistance(), (float) 0.23);

}


TEST(Test_ServiceManagement, TestClassServiceManagement) {

    string service_path = "../Files/services.txt";

    ifstream fs(service_path);
    int to_doSize;
    fs >> to_doSize;

    ServiceManagement sm(service_path);

    queue<Service> qs = sm.getToDoServices();

    Service s = qs.front();

    EXPECT_EQ(sm.findTodoService(qs.front()), true);

    EXPECT_EQ(qs.size(), to_doSize);

    sm.DoneLatestService();
    qs = sm.getToDoServices();

    EXPECT_EQ(qs.size(), to_doSize - 1);

    sm.deleteTodoService(qs.front());
    qs = sm.getToDoServices();

    EXPECT_EQ(qs.size(), to_doSize - 2);

    EXPECT_EQ(sm.findTodoService(s), false);

}


TEST(Test_BaggageStack, TestClassBaggageStack) {

    int maxSize = 3;
    Baggage b;

    BaggageStack bs(maxSize);

    EXPECT_EQ(bs.getMaxSize(), maxSize);

    EXPECT_EQ(bs.isEmpty(), true);
    bs.addBaggage(b);

    EXPECT_EQ(bs.isEmpty(), false);
    EXPECT_EQ(bs.isFull(), false);

    bs.addBaggage(b);
    bs.addBaggage(b);

    EXPECT_EQ(bs.isFull(), true);

    EXPECT_EQ(bs.takeBaggage().getWeight(), b.getWeight());
    EXPECT_EQ(bs.takeBaggage().getQuantity(), b.getQuantity());

    EXPECT_EQ(bs.getCurrentSize(), 1);

}


TEST(Test_BaggageTruck, TestClassBaggageTruck) {

    int maxSize = 3;
    int numS = 2;
    int numC = 1;
    int maxCapacity = maxSize * numS * numC;

    Baggage b;

    BaggageTruck bs(numC, numS, maxSize);

    EXPECT_EQ(bs.isEmpty(), true);

    bs.addBaggage(b);
    bs.addBaggage(b);
    bs.addBaggage(b);
    bs.addBaggage(b);
    bs.addBaggage(b);

    EXPECT_EQ(bs.getCurrentCapacity(), 5);

    EXPECT_EQ(bs.isFull(), false);

    bs.addBaggage(b);

    EXPECT_EQ(bs.isFull(), true);

    EXPECT_EQ(bs.takeBagagge().getWeight(), b.getWeight());
    EXPECT_EQ(bs.takeBagagge().getQuantity(), b.getQuantity());

    EXPECT_EQ(bs.getCurrentCapacity(), 4);

}


TEST(Test_BaggageCheckIn, TestClassBaggageCheckInTruck) {

    int maxSize = 3;
    int numS = 2;
    int numC = 1;
    int maxCapacity = maxSize * numS * numC;

    Baggage b;

    BaggageCheckIn bs(numC, numS, maxSize);

    EXPECT_EQ(bs.isTruckFull(), false);
    EXPECT_EQ(bs.getTruck().getMaxCapacity(), maxCapacity);

    bs.truckAddBaggage(b);
    bs.truckAddBaggage(b);
    bs.truckAddBaggage(b);
    bs.truckAddBaggage(b);
    bs.truckAddBaggage(b);

    EXPECT_EQ(bs.isTruckFull(), false);

    bs.truckAddBaggage(b);

    EXPECT_EQ(bs.isTruckFull(), true);

    EXPECT_EQ(bs.truckTakeBaggage().getWeight(), b.getWeight());
    EXPECT_EQ(bs.truckTakeBaggage().getQuantity(), b.getQuantity());

    EXPECT_EQ(bs.getTruck().getCurrentCapacity(), 4);

}


TEST(Test_BaggageCheckIn, TestClassBaggageCheckInQueue) {

    int maxSize = 3;
    int numS = 2;
    int numC = 1;
    int maxCapacity = maxSize * numS * numC;

    Baggage b;

    BaggageCheckIn bs(numC, numS, maxSize);

    EXPECT_EQ(bs.queueEmpty(),true);
    EXPECT_EQ(bs.getQueueSize(),0);

    bs.queueAdd(b);
    bs.queueAdd(b);
    bs.queueAdd(b);

    EXPECT_EQ(bs.getQueueSize(),3);
    EXPECT_EQ(bs.queueFront().getQuantity(),b.getQuantity());
    EXPECT_EQ(bs.queueEmpty(),false);

    bs.passNextBagaggeToTruck();
    bs.passNextBagaggeToTruck();

    EXPECT_EQ(bs.getQueueSize(),1);

    EXPECT_EQ(bs.queueRemove().getQuantity(), b.getQuantity());

    EXPECT_EQ(bs.queueEmpty(),true);

}




//__________________________________________DONE______TESTS_________________________________________________









//_____________________________________________TOMAS________________________________________________________


// Testar os diferentes construtores,  getters e setters das classes

//Fazer testes à parte tmb para operadores de comparaçao  == , < , != ... caso existam nessas classes

TEST(Test_Date, TestClassDate) {}

TEST(Test_Flight, TestClassFlight) {}

TEST(Test_Ticket, TestClassTicket) {}

TEST(Test_Time, TestClassTime) {}

TEST(Test_Transport, TestClassTransport) {}




//_____________________________________________TOMAS________________________________________________________



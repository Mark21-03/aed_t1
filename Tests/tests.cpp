#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Passenger.h"

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
    Ticket at(f, "c2", 'C', 'E', 15.5f);

    aP.
    buyTicket(at);

    Ticket r = aP.getNextFlights().front();
    ASSERT_EQ(r, at
    );

}
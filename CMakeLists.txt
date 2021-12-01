cmake_minimum_required(VERSION 3.10)
project(aed_t1)

set(CMAKE_CXX_STANDARD 11)

set(DEBUG_MODE "FALSE") #Change only the boolean to swap between modes

if(DEBUG_MODE MATCHES TRUE)
    add_subdirectory(lib/googletest-master)
    include_directories(lib/googletest-master/googletest/include)
    include_directories(lib/googletest-master/googlemock/include)

    add_executable(aed_t1
            mainTest.cpp src/Baggage.cpp src/Plane.cpp src/Date.cpp src/Flight.cpp
            src/Passenger.cpp  src/Service.cpp Tests/tests.cpp
            include/Date.h include/Plane.h include/Flight.h include/Passenger.h
            include/BST.h include/Baggage.h include/Service.h
            Exceptions/InvalidIDException.h
            Exceptions/NameToLongException.h src/Ticket.cpp include/Ticket.h
            include/MenuAlpha.h)
    target_link_libraries(aed_t1 gtest gtest_main)
    message("Debug mode")
endif()
if (DEBUG_MODE MATCHES FALSE)
    add_executable(aed_t1
            main.cpp src/Baggage.cpp src/Plane.cpp src/Date.cpp src/Flight.cpp
            src/Passenger.cpp  src/Service.cpp
            include/Date.h include/Plane.h include/Flight.h include/Passenger.h
            include/BST.h include/Baggage.h include/Service.h
            Exceptions/InvalidIDException.h
            Exceptions/NameToLongException.h src/Ticket.cpp include/Ticket.h
            include/MenuAlpha.h )
    message("Release mode")

endif ()
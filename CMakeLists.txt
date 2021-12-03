cmake_minimum_required(VERSION 3.10)
project(aed_t1)

set(CMAKE_CXX_STANDARD 11)

set(CREATE_EXE TRUE)  #creates a exe folder for the execution file in cmake-buid-release

if(CMAKE_BUILD_TYPE MATCHES Debug)
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
        include/MenuAlpha.h include/Manager.h src/Manager.cpp include/ServiceManagement.h src/ServiceManagement.cpp)
    target_link_libraries(aed_t1 gtest gtest_main)
    message("Debug mode")
endif()
if (CMAKE_BUILD_TYPE MATCHES Release)

    #creates exe file (easier to run mainMenu() in the terminal)
    if(CREATE_EXE MATCHES TRUE)
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY exe/)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY exe/)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY exe/)
    endif()

    add_executable(aed_t1
            main.cpp src/Baggage.cpp src/Plane.cpp src/Date.cpp src/Flight.cpp
            src/Passenger.cpp  src/Service.cpp
            include/Date.h include/Plane.h include/Flight.h include/Passenger.h
            include/BST.h include/Baggage.h include/Service.h
            Exceptions/InvalidIDException.h
            Exceptions/NameToLongException.h src/Ticket.cpp include/Ticket.h
            include/MenuAlpha.h src/Manager.cpp include/Manager.h
            include/ServiceManagement.h src/ServiceManagement.cpp)
    message("Release mode")

endif ()
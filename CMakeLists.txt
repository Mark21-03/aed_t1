cmake_minimum_required(VERSION 3.10)
project(aed_t1)

set(CMAKE_CXX_STANDARD 11)

set(CREATE_EXE TRUE)  #creates a exe folder for the execution file in cmake-buid-release

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_subdirectory(lib/googletest-master)
    include_directories(lib/googletest-master/googletest/include)
    include_directories(lib/googletest-master/googlemock/include)

    add_executable(aed_t1
        mainTest.cpp src/Plane.cpp src/Date.cpp src/Flight.cpp
        src/Passenger.cpp  src/Service.cpp Tests/tests.cpp src/BagaggeCheckIn.cpp
        include/Date.h include/Plane.h include/Flight.h include/Passenger.h
        include/BST.h include/Service.h
        Exceptions/InvalidIDException.h include/Transports.h
        Exceptions/NameToLongException.h src/Ticket.cpp include/Ticket.h
            include/Menu.h include/Manager.h src/Manager.cpp include/ServiceManagement.h src/ServiceManagement.cpp
        include/Time.h Exceptions/InvalidTimeException.h src/Time.cpp src/Menu.cpp include/Output.h src/Output.cpp include/BagaggeCheckIn.h Exceptions/BaggageCheckInExceptions.h include/Baggage.h)

    target_link_libraries(aed_t1 gtest gtest_main)
    message("Debug mode")
endif()
if (CMAKE_BUILD_TYPE MATCHES Release)

    add_executable(aed_t1
            main.cpp src/Plane.cpp src/Date.cpp src/Flight.cpp
            src/Passenger.cpp  src/Service.cpp src/BagaggeCheckIn.cpp
            include/Date.h include/Plane.h include/Flight.h include/Passenger.h
            include/BST.h include/Service.h
            Exceptions/InvalidIDException.h
            Exceptions/NameToLongException.h src/Ticket.cpp include/Ticket.h
            include/Menu.h src/Manager.cpp include/Manager.h include/Transports.h
            include/ServiceManagement.h src/ServiceManagement.cpp include/Time.h Exceptions/InvalidTimeException.h src/Time.cpp src/Menu.cpp src/Output.cpp include/Output.h include/Input.h src/Input.cpp include/BagaggeCheckIn.h Exceptions/BaggageCheckInExceptions.h include/Baggage.h)
    message("Release mode")

    # Doxygen Build
    find_package(Doxygen)
    if(DOXYGEN_FOUND)
        set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
        if(NOT EXISTS "${BUILD_DOC_DIR}")
            file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
        endif()
        set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
        set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
        configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
        message("Doxygen build started")
        add_custom_target(Doxygen ALL
                COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
                WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
                COMMENT "Generating API documentation with Doxygen"
                VERBATIM)
    else(DOXYGEN_FOUND)
        message("Doxygen needs to be installed to generate the documentation.")
    endif(DOXYGEN_FOUND)

endif ()
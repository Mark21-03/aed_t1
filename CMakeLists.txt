cmake_minimum_required(VERSION 3.10)
project(aed_t1)

set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)

add_executable(aed_t1 main.cpp include/Plane.h include/Date.h include/Flight.h src/Plane.cpp src/Date.cpp src/Flight.cpp)

#target_link_libraries(aed_t1 gtest gtest_main)

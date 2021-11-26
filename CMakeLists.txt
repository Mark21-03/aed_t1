cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(project1 VERSION 1.0)

add_executable(out main.cpp ${SRC_FILES})
target_include_directories(out PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

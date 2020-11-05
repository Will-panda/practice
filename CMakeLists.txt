cmake_minimum_required(VERSION 2.8.3)
project(test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++11 -pthread ")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

find_package (Threads)  

find_package(Eigen REQUIRED)
include_directories(${EIGEN_INCLUDE_DIR})

message(STATUS "Eigen dir: ${EIGEN_INCLUDE_DIR}")
message(STATUS "camke moudle path: ${CMAKE_MODULE_PATH}")



add_subdirectory(${PROJECT_SOURCE_DIR}/cpp_practice)
add_subdirectory(${PROJECT_SOURCE_DIR}/leetcode)
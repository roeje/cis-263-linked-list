cmake_minimum_required(VERSION 3.3)
project(hw311)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hw311_main.cpp)
add_executable(hw311 ${SOURCE_FILES})
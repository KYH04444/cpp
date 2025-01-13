cmake_minimum_required(VERSION 3.10)
set(PACKAGE_NAME smart_pointer)
project(smart_pointer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
add_executable(oopCar src/Exercise01.cpp)
add_executable(smtPtr src/Exercise00.cpp)
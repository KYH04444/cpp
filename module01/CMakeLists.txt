cmake_minimum_required(VERSION 3.10)
project(car)

include_directories(include)
add_executable(car src/car.cpp)
add_executable(sdv src/softwareDefinedCar.cpp)
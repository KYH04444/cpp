cmake_minimum_required(VERSION 3.10)

set(PACKAGE_NAME module0)
project(module0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
add_executable(convert src/convert.cpp)
add_executable(phoneBook src/phoneBook.cpp)
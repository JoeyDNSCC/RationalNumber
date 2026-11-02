cmake_minimum_required(VERSION 4.3)
project(rational)

set(CMAKE_CXX_STANDARD 20)

add_executable(rational main.cpp
        RationalNumber.cpp
        RationalNumber.h
)

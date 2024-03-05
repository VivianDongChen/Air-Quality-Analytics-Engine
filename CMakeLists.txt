cmake_minimum_required(VERSION 3.26)
project(finalproject)

set(CMAKE_CXX_STANDARD 17)

add_executable(finalproject main.cpp
        Date.cpp
        Time.cpp
        AirQuality.h
        AirQuality.cpp
        MinHeap.cpp
        MenuFunction.h
        MenuFunction.cpp
        DateTime.cpp
        Vector.h
        Vector.cpp
)

cmake_minimum_required(VERSION 3.30)
project(Task)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(Task main.cpp
        maiFunc.cpp
        maiFunc.h
        TextFunctions.cpp
        TextFunctions.h)


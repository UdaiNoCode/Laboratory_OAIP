cmake_minimum_required(VERSION 3.30)
project(Task2)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")

add_executable(Task2 main.cpp
        menusFunc/menuFunc.cpp
        menusFunc/menuFunc.h
        StructFunc/structFunctions.cpp
        StructFunc/structFunctions.h
        FuncPractical/myFunc.cpp
        FuncPractical/myFunc.h)

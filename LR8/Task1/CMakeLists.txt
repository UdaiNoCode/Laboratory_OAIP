cmake_minimum_required(VERSION 3.30)
project(LR8)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")

add_executable(LR8 main.cpp
        StructFunc/StrucFunctions.cpp
        StructFunc/StrucFunctions.h
        Menu/menu.cpp
        Menu/menu.h
        MainFunc/MainTaskFunc.cpp
        MainFunc/MainTaskFunc.h)

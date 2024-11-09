cmake_minimum_required(VERSION 3.29)
project(Google_Test)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

add_executable(Task_5_Google_Tests_ main.cpp Saper.c Saper.h)
target_link_libraries(Task_5_Google_Tests_ ${GTEST_LIBRARIES})

enable_testing()
add_test(Test_1 Task_5_Google_Tests_)

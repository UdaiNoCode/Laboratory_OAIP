
cmake_minimum_required(VERSION 3.29)
project(Task_1_Google_Tests_)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

add_executable(Task_1_Google_Tests_ main.cpp Task_1.cpp Task_1.h)
target_link_libraries(Task_1_Google_Tests_ ${GTEST_LIBRARIES})

enable_testing()
add_test(Test_1 Test_2 Test_3 Test_4 Task_1_Google_Tests_)


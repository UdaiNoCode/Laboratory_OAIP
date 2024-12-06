cmake_minimum_required(VERSION 3.29)
project(Google_Test)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

add_executable(Google_Tests main.cpp ../Task/TextFunctions.cpp ../Task/TextFunctions.h)
target_link_libraries(Google_Tests ${GTEST_LIBRARIES})

enable_testing()
add_test(Test_1 Test_2 Test_3 Test_9 Test_10 Test_4 Test_5 Test_6 Test_7 Test_8 TestSec_1 TestFirst_1 TestFirst_2 TestFirst_3 TestFirst_4 TestFirst_5 TestFirst_6 TestFirst_7 TestFirst_8 TestFirst_10 TestFirst_9 Test Google_Tests)
cmake_minimum_required(VERSION 3.29)
project(Google_Test)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)

add_executable(Google_Tests main.cpp main_magic.c main_magic.h)
target_link_libraries(Google_Tests ${GTEST_LIBRARIES})

enable_testing()
add_test(ODD_2 ODD_1 ODD_3 ODD_4 EVEN_1 EVEN_2 EVEN_3 EVEN_4  Google_Tests)

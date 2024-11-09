#include <iostream>
#include "Task_1.h"
#include<gtest/gtest.h>
long double nums[] = {1,100,3,4,5};
long double nums_1[] = {1,1243,2435525,4646456,412334,234234,123,12313,1};
long double nums_2[] = {0,0,0,0,0,0,1};
long double nums_3[] = {-1,-2,-3, 0.23,0.233, 2323.322};

TEST(finder, Test_1) {
    ASSERT_EQ(4, finder(nums, 5));
}
TEST(finder, Test_2) {
    ASSERT_EQ(1, finder(nums_1, 9));
}
TEST(finder, Test_3) {
    ASSERT_EQ(7, finder(nums_2, 7));
}
TEST(finder, Test_4) {
    ASSERT_EQ(4, finder(nums_3, 6));
}
int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0 ;
}

extern "C"{
#include "main_magic.h"
}
#include<gtest/gtest.h>

long long summ_coluum_check(int n_sise) {
    return ryad_check(choose_and_print(n_sise),n_sise);
}

// TEST(summ_coluum_check, ODD) {
//     ASSERT_EQ(15, summ_coluum_check(3));
// }


TEST(summ_coluum_check, ODD_1) {
    ASSERT_EQ(15, summ_coluum_check(3));
}

TEST(summ_coluum_check, ODD_2) {
    ASSERT_EQ(1, summ_coluum_check(3));
}
TEST(summ_coluum_check, ODD_3) {
    ASSERT_EQ(15, summ_coluum_check(1001));
}

TEST(summ_coluum_check, ODD_4) {
    ASSERT_EQ(15, summ_coluum_check(3));
}

TEST(summ_coluum_check, EVEN_1) {
    ASSERT_EQ(34, summ_coluum_check(4));
}

TEST(summ_coluum_check, EVEN_2) {
    ASSERT_EQ(32020, summ_coluum_check(40));
}
TEST(summ_coluum_check, EVEN_3) {
    ASSERT_EQ(62500250, summ_coluum_check(500));
}

TEST(summ_coluum_check, EVEN_4) {
    ASSERT_EQ(2056, summ_coluum_check(16));
}





int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

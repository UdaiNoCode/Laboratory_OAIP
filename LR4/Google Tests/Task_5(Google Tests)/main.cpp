#include <iostream>
extern "C"{
#include "Saper.h"
}
#include <gtest/gtest.h>

int checker(int m, int n) {
    int** array = new int*[m];
    for (int i = 0; i < m; i++) {
        array[i] = new int[n];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> array[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        delete[] array[i];
    }
    delete[] array;

    return summer(matrix_game(m,n,array),m,n);
}

TEST(checke, Test_1) {
    ASSERT_EQ(8, checker(3, 3));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}

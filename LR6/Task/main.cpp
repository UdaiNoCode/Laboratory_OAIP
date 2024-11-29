#include <cstring>
#include <iostream>
#include "TextFunctions.h"
#include "maiFunc.h"

class LabWork {
    public:
        static void Task_1(char* array, size_t size_array, int k) {
            size_t size = strlen(array);
            int c = inWichWorld(array, size, k);
            std::cout << c << std::endl;
            free(array);
        }

        static void Task_2(char* array, size_t size_array) {
            std::pair<int, char**> params = findWorld(array, strlen(array));
            for (int i = 0; i < params.first; i++) {
                std::cout << params.second[i] << std::endl;
            }
            for (int i = 0; i < params.first; i++) {
                delete[] params.second[i];
            }
            delete[] params.second;
        }

        static void Task_3(char* array, size_t size_array) {}
};

int main() {
    char* input = readline();

    LabWork::Task_2(input, strlen(input));

}

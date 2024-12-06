#include <cstring>
#include <iostream>
#include "TextFunctions.h"
#include "maiFunc.h"

void Task_1(char* array, size_t size_array, int k) {
    size_t size = strlen(array);
    int c = inWichWorld(array, size, k);
    std::cout << c << std::endl;
    free(array);
}

void Task_2(char* array, size_t size_array) {
    std::pair<int, char**> params = findWorld(array, strlen(array));
    for (int i = 0; i < params.first; i++) {
        std::cout << params.second[i] << std::endl;
    }
    for (int i = 0; i < params.first; i++) {
        delete[] params.second[i];
    }
    delete[] params.second;
}

void Task_3(char* array, size_t size_array) {
    std::cout << findSum(array, size_array) << std::endl;
}


int main() {
    std::cout << "Введите исходную строку: \n" << std::endl;
    char* input = readline();

    std::cout <<"Выберете какую часть работы вы хотите использовать: \n"
                "1 или 2 или 3"<< std::endl;

    int n;
    std::cin >> n;

    switch (n) {
        case 1:{
            context_1();

            std::cout<<"Введите k\n";
            int k;
            std::cin >> k;

            Task_1(input, strlen(input), k);
            break;
        }
        case 2: {
            context_2();
            Task_2(input, strlen(input));
            break;
        }
        case 3: {
            context_3();
            Task_3(input, strlen(input));
            break;
        }
        default:
            std::cout<<"Ошибка ввода\n";
    }

    free(input);

}

//
// Created by udainoko on 12/17/24.
//
#include <iostream>
#include <cmath>
#include "inputValidateFunc.h"


// size_t checkValidateSize_t() {
//     size_t number;
//     while (!(std::cin >> number)) {
//         std::cout << "Invalid input. Please enter an integer: ";
//         std::cin.clear();
//         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     }
//
//     return number;
// }

size_t checkValidateSize_t() {

    size_t x;
    while (!(std::cin >> x) or std::cin.get() != '\n')
    {
        std::cout << "Error!" << std::endl << "Введите значение повторно "<< ": ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return x;
}
int checkValidateInt() {

    int x;
    while (!(std::cin >> x) or std::cin.get() != '\n')
    {
        std::cout << "Error!" << std::endl << "Введите значение повторно "<< ": ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return x;
}

double checkValidateDouble() {
    double x;
    while (!(std::cin >> x) or std::cin.get() != '\n')
    {
        std::cout << "Error!" << std::endl << "Введите значение повторно "<< ": ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return x;
}
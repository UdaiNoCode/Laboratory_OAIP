//
// Created by udainoko on 12/17/24.
//
#include <iostream>
#include <cmath>
#include "inputValidateFunc.h"


size_t checkValidateSize_t() {
    size_t number;
    while (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return number;
}

double checkValidateDouble() {
    double number;
    while (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter an real number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }
    return number;
}
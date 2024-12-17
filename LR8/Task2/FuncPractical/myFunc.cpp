//
// Created by udainoko on 12/15/24.
//


#include <iostream>
#include <format>
#include <cmath>

#include "myFunc.h"
#include "../StructFunc/structFunctions.h"
#include "../menusFunc/menuFunc.h"

double salaryCounter(double salary, double hours) {

    double salaryPerHour = salary / 144;

    const double tax = 0.12;

    double upHours = hours - 144;
    if (upHours < 0) {
        upHours = 0;
    }
    hours = hours - upHours;
    double totalSalary = salaryPerHour * hours  + salaryPerHour * upHours * 2;
    double totTaxSal = totalSalary * (1 - tax);

    return totTaxSal;
}

void printTotalSalaty(Person *persons, size_t size) {
    std::cout<<"+-----------------------+-----------------+\n";
    std::cout<<"|         Person        |      TotSal     |\n";
    std::cout<<"+-----------------------+-----------------+\n";



    if (size == 0)
        std::cout<<"|           No persons was added...       |\n";

    for (int i = 0; i < size; i++) {
        double totalSalary = salaryCounter(persons[i].mounthSalry, persons[i].mounthHours);
        std::cout<< std::format("|{:^23}|{:^17.2f}|\n",
                            persons[i].name, totalSalary);

    }
    std::cout<<"+-----------------------+-----------------+\n";
}

void changeSalary(Person *persons, size_t size, size_t index) {
    if (index > size) {
        return;
    }

    std::cout<<"Введите новую заработную плату\n";
    std::cout<<">";
    double newSalary;
    std::cin>>newSalary;

    persons[index - 1].mounthSalry = newSalary;
    std::cout<<"Зарплата успешно изменена\n";

}

void changeHours(Person *persons, size_t size, size_t index) {
    if (index > size) {
        return;
    }

    std::cout<<"Введите новые рабочие часы в течение месяца\n";
    std::cout<<">";
    double newHours;
    std::cin>>newHours;

    persons[index - 1].mounthHours = newHours;
    std::cout<<"Рабочие часы успещно изменены\n";

}

void changing(Person *persons, size_t size) {
    std::cout<<"Введите номер работника , ведомость которого хотиет изменить\n";
    std::cout<<">";
    size_t index;
    std::cin>>index;

    int option;

    do {
        change::print_menu();
        std::cin >> option;

        switch (option) {
            case 1: {
                changeSalary(persons, size, index);
                break;
            }
            case 2: {
                changeHours(persons, size, index);
                break;
            }
            default: {
            }
        }

        if (option != 3) {
            menu::stop_system();
        }

    }while(option != 3);
}

void includeMain(Person* persons, size_t personsSize) {
    int option;

    do {
        inclmenu::print_menu();
        std::cin >> option;

        switch (option) {
            case 1: {
                printTotalSalaty(persons, personsSize);
                break;
            }
            case 2: {
                changing(persons, personsSize);
                break;
            }
            default: {
            }
        }

        if (option != 3) {
            menu::stop_system();
        }
    }while(option != 3);

}
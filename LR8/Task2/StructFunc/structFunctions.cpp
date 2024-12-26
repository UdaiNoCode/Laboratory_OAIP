//
// Created by udainoko on 12/15/24.
//
#include <iostream>
#include <format>
#include<string>

#include "structFunctions.h"
#include "../menusFunc/inputValidateFunc.h"


std::pair<Person*, size_t> newPersons() {

    std::cout << "Введите количество учетных записей\n";
    size_t persCount;
    std::cin>>persCount;
    if (std::cin.fail()) {
        persCount = checkValidateSize_t();
    }


    auto persons = new Person[persCount];


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (size_t i = 0; i < persCount; ++i) {
            std::cout << "Введите ФИО: \n";
            std::getline(std::cin, persons[i].name); // Read full name with spaces

            std::cout << "Введите табельный номер: \n";
            std::cin >> persons[i].tabelNumber;

            std::cout << "Введите количество проработанных часов: \n";
            std::cin>>persons[i].mounthHours;
            if (std::cin.fail()) {
                persons[i].mounthHours = checkValidateDouble();
            }

            std::cout << "Введите месячную зарплату:\n";
            std::cin>>persons[i].mounthSalry;
            if (std::cin.fail()) {
                persons[i].mounthSalry = checkValidateDouble();
            }


            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    return {persons, persCount};

}

void printPersons(Person *persons, size_t size) {
    std::cout<<"+-----------------------+---------------+------------+------------+\n";
    std::cout<<"|         Person        |     Number    | Hours/mon  | Salary/mon |\n";
    std::cout<<"+-----------------------+---------------+------------+------------+\n";


    if (size == 0)
        std::cout<<"|                       No persons was added...                   |\n";

    for (int i = 0; i < size; i++) {
        std::cout<< std::format("|{:^23}|{:^15}|{:^12.2f}|{:^12.2f}|\n",
                            persons[i].name, persons[i].tabelNumber,
                            persons[i].mounthHours, persons[i].mounthSalry);


    }
    std::cout<<"+-----------------------+---------------+------------+------------+\n";
}

Person* addPerson(Person* persons, size_t &size) {

    auto newPersons = new Person[size + 1];

    for (int i = 0; i < size; i++) {
        newPersons[i] = persons[i];
    }
    delete[] persons;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout<<"Введите ФИО\n";
    std::getline(std::cin, newPersons[size].name);

    std::cout<<"Введите табельный номер: \n";
    std::cin>>newPersons[size].tabelNumber;

    std::cout<<"Введите колличесво проработанный часов: \n";
    std::cin>>newPersons[size].mounthHours;
    if (std::cin.fail()) {
        newPersons[size].mounthHours = checkValidateDouble();
    }

    std::cout<<"Введите месячную зарплату:\n";
    std::cin>>newPersons[size].mounthSalry;
    if (std::cin.fail()) {
        newPersons[size].mounthSalry = checkValidateDouble();
    }

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    size++;
    return newPersons;
}

Person* deleteOnePerson(Person *persons, size_t &size, size_t index) {
    if (index >= size) {
        return persons;
    }

    auto newPersons = new Person[size - 1];

    for (size_t i = 0; i < index; i++) {
        newPersons[i] = persons[i];
    }
    for (size_t i = index + 1; i < size; i++) {
        newPersons[i - 1] = persons[i];
    }

    delete[] persons;

    size--;

    return newPersons;
}


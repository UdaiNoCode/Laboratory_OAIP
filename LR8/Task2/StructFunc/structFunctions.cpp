//
// Created by udainoko on 12/15/24.
//
#include <iostream>
#include <format>

#include "structFunctions.h"


std::pair<Person*, size_t> newPersons() {
    std::cout<<"Введите колличество учетных записей\n";
    size_t persCount;
    std::cin>>persCount;

    auto persons = new Person[persCount];

    for(int i = 0; i < persCount; i++) {

        std::cout<<"Введите ФИО\n";
        std::cin>>persons[i].name;

        std::cout<<"Введите табельный номер: \n";
        std::cin>>persons[i].tabelNumber;

        std::cout<<"Введите колличесво проработанный часов: \n";
        std::cin >> persons[i].mounthHours;

        std::cout<<"Введите месячную зарплату:\n";
        std::cin>> persons[i].mounthSalry;

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

    std::cout<<"Введите ФИО\n";
    std::cin>>newPersons[size].name;

    std::cout<<"Введите табельный номер: \n";
    std::cin>>newPersons[size].tabelNumber;

    std::cout<<"Введите колличесво проработанный часов: \n";
    std::cin >> newPersons[size].mounthHours;

    std::cout<<"Введите месячную зарплату:\n";
    std::cin>> newPersons[size].mounthSalry;

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


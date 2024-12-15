//
// Created by udainoko on 12/15/24.
//
#include <utility>
#include <random>
#include <iostream>
#include <format>
#include <iomanip>
#include <unordered_set>
#include <algorithm>

#include "StrucFunctions.h"

#include <unordered_map>


void arrayCreate(Person* person, size_t i) {
    person[i].marks.math = new int[person[i].marks.n_size];
    person[i].marks.chemistry = new int[person[i].marks.n_size];
    person[i].marks.physical = new int[person[i].marks.n_size];
}

double middleArifm(int* array, size_t size) {

    double sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum / size;
}

int autoMarks() {
    std::random_device random_device; // Источник энтропии.
    std::mt19937 generator(random_device()); // Генератор случайных чисел.


    std::uniform_int_distribution<> distribution(1, 10); // Равномерное распределение [1, 240]

    int mark = distribution(generator); // Случайное число.
    return mark;
}

void deletePerson(Person* persons, size_t& n) {
    for (int i = 0; i < n; i++) {
        delete[] persons[i].marks.physical;
        delete[] persons[i].marks.math;
        delete[] persons[i].marks.chemistry;
    }
    delete[] persons;
    persons = nullptr;
    n = 0;
}

std::pair<Person*, size_t> newPersons() {
    std::cout<<"Введите колличество учетных записей\n";
    size_t persCount;
    std::cin>>persCount;

   auto persons = new Person[persCount];

    for(int i = 0; i < persCount; i++) {

        std::cout<<"Введите ФИО\n";
        std::cin>>persons[i].name;

        std::cout<<"Введите адресс проживания: \n";
        std::cin>>persons[i].address;

        std::cout<<"Введите колличесво отметок: \n";
        std::cin >> persons[i].marks.n_size;

        arrayCreate(persons, i);

        std::cout<<"Функция автозаполнения отметок: \n"
                    "1: Да\n"
                    "2: Нет\n";

        short autoCheck;
        std::cin>>autoCheck;

        switch (autoCheck) {
            case 1: {

                for(int j = 0; j < persons[i].marks.n_size; j++) {
                    persons[i].marks.math[j] = autoMarks();
                    persons[i].marks.physical[j] = autoMarks();
                    persons[i].marks.chemistry[j] = autoMarks();
                }
                break;
            }
            case 2: {
                std::cout<<"Введите отметки по математике: \n";
                for(int j = 0; j < persons[i].marks.n_size; j++) {
                    std::cin>>persons[i].marks.math[j];
                }

                std::cout<<"Введите отметки по химии: \n";
                for(int j = 0; j < persons[i].marks.n_size; j++) {
                    std::cin>>persons[i].marks.chemistry[j];
                }

                std::cout<<"Введите отметки по физике: \n";
                for(int j = 0; j < persons[i].marks.n_size; j++) {
                    std::cin>>persons[i].marks.physical[j];
                }
                break;
            }
            default: {
                std::cout<<"Wrong input!\n";
                break;
            }
        }


    }
    return {persons, persCount};
}

void print_persons(Person *persons, size_t size) {
    std::cout.precision(3);
    std::cout<<"+-----------------------+---------------+------------+------------+------------+\n";
    std::cout<<"|         Person        |    Address    | Math Marks | Phys Marks | Chem Marks |\n";
    std::cout<<"+-----------------------+---------------+------------+------------+------------+\n";

    if (size == 0)
        std::cout<<"|                             No persons was added...                          |\n";

    for (int i = 0; i < size; i++) {
        std::cout<<std::setprecision(3)<< std::format("|{:^23}|{:^15}|{:^12.2f}|{:^12.2f}|{:^12.2f}|\n",
                            persons[i].name, persons[i].address,
                            middleArifm(persons[i].marks.math, persons[i].marks.n_size),
                            middleArifm(persons[i].marks.physical, persons[i].marks.n_size),
                            middleArifm(persons[i].marks.chemistry, persons[i].marks.n_size));
        std::cout.precision(3);
    }
    std::cout.precision(3);
    std::cout<<"+-----------------------+---------------+------------+------------+------------+\n";
}

void print_finded_persons(Person *persons, size_t size,  std::unordered_set<size_t>& indexed) {
    std::cout<<"+-----------------------+---------------+------------+------------+------------+\n";
    std::cout<<"|         Person        |    Address    | Math Marks | Phys Marks | Chem Marks |\n";
    std::cout<<"+-----------------------+---------------+------------+------------+------------+\n";


    if (indexed.empty())
        std::cout<<"|                              No persons founded...                           |\n";

    for (auto i: indexed) {
        std::cout.precision(3);
            std::cout<<std::setprecision(3)<< std::format("|{:^23}|{:^15}|{:^12.2f}|{:^12.2f}|{:^12.2f}|\n",
                                persons[i].name, persons[i].address,
                                middleArifm(persons[i].marks.math, persons[i].marks.n_size),
                                middleArifm(persons[i].marks.physical, persons[i].marks.n_size),
                                middleArifm(persons[i].marks.chemistry, persons[i].marks.n_size));

        std::cout.precision(3);

    }
    std::cout<<"+-----------------------+---------------+------------+------------+------------+\n";
}

Person* add_person(Person* persons, size_t &size) {

    auto newPersons = new Person[size + 1];

    for (int i = 0; i < size; i++) {
        newPersons[i] = persons[i];
    }
    // if (persons != nullptr) {
    //     delete[] persons;
    // }


    std::cout<<"Введите ФИО\n";
    std::cin>>newPersons[size].name;

    std::cout<<"Введите адресс проживания: \n";
    std::cin>>newPersons[size].address;

    std::cout<<"Введите колличесво отметок: \n";
    std::cin >> newPersons[size].marks.n_size;
    arrayCreate(newPersons, size);

    std::cout<<"Функция автозаполнения отметок: \n"
                "1: Да\n"
                "2: Нет\n";

    short autoCheck;
    std::cin>>autoCheck;

    switch (autoCheck) {
        case 1: {

            for(int j = 0; j < newPersons[size].marks.n_size; j++) {
                newPersons[size].marks.math[j] = autoMarks();
                newPersons[size].marks.physical[j] = autoMarks();
                newPersons[size].marks.chemistry[j] = autoMarks();
            }
            break;
        }
        case 2: {
            std::cout<<"Введите отметки по математике: \n";
            for(int j = 0; j < newPersons[size].marks.n_size; j++) {
                std::cin>>newPersons[size].marks.math[j];
            }

            std::cout<<"Введите отметки по химии: \n";
            for(int j = 0; j < newPersons[size].marks.n_size; j++) {
                std::cin>>newPersons[size].marks.chemistry[j];
            }

            std::cout<<"Введите отметки по физике: \n";
            for(int j = 0; j < newPersons[size].marks.n_size; j++) {
                std::cin>>newPersons[size].marks.physical[j];
            }
            break;
        }
        default: {
            std::cout<<"Wrong input!\n";
            break;
        }
    }

    size++;
    return newPersons;
}


//reutn thr number in the list
std::unordered_set<size_t> find_person(Person *persons, size_t size) {
    std::cout<<"Выберите тип поиска: \n";
    std::cout<<"1.  По ФИО\n";
    std::cout<<"2.  По Адрессу\n";
    std::cout<<">";

    int type;
    std::cin>>type;
    std::cout<<std::endl;
    std::unordered_set<size_t> persons_index;

    switch (type) {
        case 1: {
            std::string name;

            std::cout<<"Введите ФИО (параметр поиска)\n";
            std::cout<<">";
            std::cin>>name;

            for (size_t i = 0; i < size; i++) {
                if (persons[i].name == name) {
                    persons_index.insert(i);
                }
            }
            break;
        }
        case 2: {
            std::string city;

            std::cout<<"Введите адресс (параметр поиска)\n";
            std::cout<<">";
            std::cin>>city;

            for (size_t i = 0; i < size; i++) {
                if (persons[i].address == city) {
                    persons_index.insert(i);
                }
            }
            break;
        }
        default: {
            std::cout<<"Wrong input!\n";
        }
    }
    return persons_index;
}


void sort_persons(Person *persons, size_t size) {
    std::sort(persons, persons + size, [](const Person &p1, const Person &p2) {
            // All in lowercase and compare
            std::string name1 = p1.name;
            std::string name2 = p2.name;

            std::ranges::transform(name1, name1.begin(), ::tolower);
            std::ranges::transform(name2, name2.begin(), ::tolower);
            return name1 <= name2;
   });
}

Person* deleteOnePerson(Person *persons, size_t &size, size_t index) {
    if (index > size) {
        return persons;
    }

    auto newPersons = new Person[size - 1];

    for (size_t i = 0; i < index; i++) {
        newPersons[i] = persons[i];
    }
    for (size_t i = index; i < size - 1; i++) {
        newPersons[i] = persons[i + 1];
    }

    // delete[] persons;
    for (size_t i = 0; i < size; i++) {
        delete[] persons[i].marks.math;
        delete[] persons[i].marks.chemistry;
        delete[] persons[i].marks.physical;
    }
    delete[] persons;

    size--;
    return newPersons;
}
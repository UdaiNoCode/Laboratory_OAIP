#include <iostream>
#include <utility>
#include <unordered_set>


#include "MainFunc/MainTaskFunc.h"
#include "StructFunc/StrucFunctions.h"
#include "Menu/menu.h"


int main() {

    int variant;
    bool screen = true;
    bool cleaned = false;
    std::pair<Person*, size_t> persons_pair = newPersons();

    Person* persons = persons_pair.first;
    size_t persons_size = persons_pair.second;
    std::system("clear");

    do {
        print_menu();
        std::cin >> variant;

        switch (variant) {
            case 1: {
                cleaned = false;
                persons = add_person(persons, persons_size);
                break;
            }
            case 2: {
                print_persons(persons, persons_size);
                break;
            }
            case 5: {
                cleaned = true;
                deletePerson(persons, persons_size);
                persons = nullptr;
                std::cout<<"List cleaned\n";
                break;
            }
            case 3: {
                std::unordered_set<size_t> indexes = find_person(persons, persons_size);
                print_finded_persons(persons, persons_size, indexes);
                break;
            }
            case 4: {
                sort_persons(persons, persons_size);
                std::cout<<"List sorted\n";
                break;
            }
            case 6: {
                size_t var;
                std::cout<<"Введите номер для удаления: \n";
                std::cout<<">";
                std::cin>>var;
                persons = deleteOnePerson(persons, persons_size, var - 1);
                std::cout<<"Данный об студенте под номером "<<var<<" успешно удалены\n";
                break;
            }
            case 7: {
                mainFunc::main_task(persons, persons_size);
                break;
            }
            default: {
            }
        }

        if (variant != 8 ) {
            stop_system();
        }

        if (variant == 8) {
            screen = false;
        }
    }while (screen);

    if (!cleaned) {
        deletePerson(persons, persons_size);
    }
}
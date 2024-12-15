#include <iostream>

#include "menusFunc/menuFunc.h"
#include "StructFunc/structFunctions.h"
#include "FuncPractical/myFunc.h"

int main() {

    bool screen = true;
    bool cleaned = false;
    int option;

    std::pair<Person*, size_t> perPair = newPersons();
    Person* persons = perPair.first;
    size_t personsSize = perPair.second;

    do {
        menu::print_menu();
        std::cin >> option;

        switch (option) {
            case 1: {
                cleaned = false;
                persons = addPerson(persons, personsSize);
                break;
            }
            case 2: {
                printPersons(persons, personsSize);
                break;
            }
            case 3: {
                cleaned = true;

                delete[] persons;

                persons = nullptr;
                personsSize = 0;

                break;
            }
            case 4: {
                size_t var;
                std::cout<<"Введите номер для удаления: \n";
                std::cout<<">";
                std::cin>>var;
                persons = deleteOnePerson(persons, personsSize, var - 1);
                std::cout<<"Данный об работнике под номером "<<var<<" успешно удалены\n";
                break;
            }
            case 5: {
                includeMain(persons, personsSize);
                break;
            }
            default: {
            }
        }

        if (option != 6) {
            menu::stop_system();
        }
        if(option == 6) {
            screen = false;
        }

    }while(screen);
    if (!cleaned) {
        delete[] persons;
    }
}

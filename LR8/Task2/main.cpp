#include <iostream>

#include "menusFunc/menuFunc.h"
#include "StructFunc/structFunctions.h"
#include "FuncPractical/myFunc.h"
#include "FileSave/SaveAndCreate.h"
#include "menusFunc/inputValidateFunc.h"

int main() {

    bool screen = true;
    bool cleaned = false;
    int option;

    Person* persons = nullptr;
    size_t personsSize = 0;

    std::cout <<"Press 1 to load previous data: \n";
    std::cout<< "Press 2 to start new session: \n";
    std::cout <<">";
    int n;
    std::cin >> n;
    if (n == 1) {
        std::pair<Person*, size_t> perPair = SaveAndLoad::LoadForFile();
        persons = perPair.first;
        personsSize = perPair.second;
    }
    else {
        std::pair<Person*, size_t> perPair = newPersons();
        persons = perPair.first;
        personsSize = perPair.second;
    }

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
            case 6: {
                bool isSaved = SaveAndLoad::SaveAndCreateFile(persons, personsSize);
            }
            default: {
            }
        }

        if (option != 7) {
            menu::stop_system();
        }
        if(option == 7) {
            screen = false;
        }

    }while(screen);
    if (!cleaned) {
        delete[] persons;
    }
}

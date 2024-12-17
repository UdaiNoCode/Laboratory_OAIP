//
// Created by udainoko on 12/17/24.
//
#include <fstream>


#include "../StructFunc/structFunctions.h"
#include "SaveAndCreate.h"

#include <iostream>

namespace SaveAndLoad {
    bool SaveAndCreateFile(const Person* persons, size_t personCount) {
        std::ofstream file("/home/udainoko/Documents/453503/ОАиП/LR8/Task2/FileSave/Data.txt");
        if (!file.is_open()) {
            std::cout << "Smth went wrong! File could not be opened!" << std::endl;
            return false;
        }

        file << personCount << std::endl;

        for (size_t i = 0; i < personCount; i++) {
            file <<persons[i].name<<std::endl;
            file <<persons[i].tabelNumber<<std::endl;
            file <<persons[i].mounthHours<<std::endl;
            file <<persons[i].mounthSalry<<std::endl;
        }

        file.close();

        std::cout << "File saved successfully!" << std::endl;
        return true;
    }

    std::pair<Person*, size_t> LoadForFile() {
        std::ifstream inFile("/home/udainoko/Documents/453503/ОАиП/LR8/Task2/FileSave/Data.txt");
        if (!inFile.is_open()) {
            return std::make_pair(nullptr, 0);
        }

        size_t personCount;
        inFile >> personCount;

        auto persons = new Person[personCount];

        for (size_t i = 0; i < personCount; i++) {
            inFile >> persons[i].name >> persons[i].tabelNumber >> persons[i].mounthHours >> persons[i].mounthSalry;
        }
        inFile.close();

        std::string line;
        return std::make_pair(persons, personCount);
    }
}

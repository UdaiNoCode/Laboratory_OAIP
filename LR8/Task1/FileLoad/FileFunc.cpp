//
// Created by udainoko on 12/21/24.
//

#include "FileFunc.h"

#include <fstream>
#include <string>
#include <iostream>

void writeArrayToFile(const Person *persons, int count) {
    std::ofstream outFile("/home/udainoko/Documents/453503/ОАиП/LR8/Task1/FileLoad/Binary.dat", std::ios::binary);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!" << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char *>(&count), sizeof(count));

    for (int i = 0; i < count; ++i) {

        size_t nameSize = persons[i].name.size();
        outFile.write(reinterpret_cast<char *>(&nameSize), sizeof(nameSize));
        outFile.write(persons[i].name.c_str(), nameSize);

        size_t addressSize = persons[i].address.size();
        outFile.write(reinterpret_cast<char *>(&addressSize), sizeof(addressSize));
        outFile.write(persons[i].address.c_str(), addressSize);

        outFile.write(reinterpret_cast<const char *>(&persons[i].marks.n_size), sizeof(persons[i].marks.n_size));
        outFile.write(reinterpret_cast<const char *>(persons[i].marks.math), sizeof(int) * persons[i].marks.n_size);
        outFile.write(reinterpret_cast<const char *>(persons[i].marks.physical), sizeof(int) * persons[i].marks.n_size);
        outFile.write(reinterpret_cast<const char *>(persons[i].marks.chemistry), sizeof(int) * persons[i].marks.n_size);
    }

    outFile.close();
}

// Person read
void readArrayFromFile(Person *&persons, int &count) {
    std::ifstream inFile("/home/udainoko/Documents/453503/ОАиП/LR8/Task1/FileLoad/Binary.dat", std::ios::binary);
    if (!inFile) {
        std::cerr << "Ошибка открытия файла для чтения!" << std::endl;
        return;
    }

    // Struct count
    inFile.read(reinterpret_cast<char *>(&count), sizeof(count));
    persons = new Person[count];

    for (int i = 0; i < count; ++i) {

        size_t nameSize;
        inFile.read(reinterpret_cast<char *>(&nameSize), sizeof(nameSize));
        persons[i].name.resize(nameSize);
        inFile.read(&persons[i].name[0], nameSize);

        size_t addressSize;
        inFile.read(reinterpret_cast<char *>(&addressSize), sizeof(addressSize));
        persons[i].address.resize(addressSize);
        inFile.read(&persons[i].address[0], addressSize);

        inFile.read(reinterpret_cast<char *>(&persons[i].marks.n_size), sizeof(persons[i].marks.n_size));
        persons[i].marks.math = new int[persons[i].marks.n_size];
        persons[i].marks.physical = new int[persons[i].marks.n_size];
        persons[i].marks.chemistry = new int[persons[i].marks.n_size];

        inFile.read(reinterpret_cast<char *>(persons[i].marks.math), sizeof(int) * persons[i].marks.n_size);
        inFile.read(reinterpret_cast<char *>(persons[i].marks.physical), sizeof(int) * persons[i].marks.n_size);
        inFile.read(reinterpret_cast<char *>(persons[i].marks.chemistry), sizeof(int) * persons[i].marks.n_size);
    }

    inFile.close();
}



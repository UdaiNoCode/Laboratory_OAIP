//
// Created by udainoko on 12/17/24.
//

#ifndef SAVEANDCREATE_H
#define SAVEANDCREATE_H
namespace SaveAndLoad {
    bool SaveAndCreateFile(const Person* persons, size_t personCount);

    std::pair<Person*, size_t> LoadForFile();
}

#endif //SAVEANDCREATE_H

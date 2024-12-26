//
// Created by udainoko on 12/21/24.
//

#ifndef FILEFUNC_H
#define FILEFUNC_H
#include "../StructFunc/StrucFunctions.h"
void writeArrayToFile(const Person *persons, int count);

void readArrayFromFile(Person *&persons, int &count);

#endif //FILEFUNC_H

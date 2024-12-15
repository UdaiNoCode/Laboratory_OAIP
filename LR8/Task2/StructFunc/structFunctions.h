//
// Created by udainoko on 12/15/24.
//


#ifndef STRUCTFUNCTIONS_H
#define STRUCTFUNCTIONS_H
#include <string>

struct Person {
    std::string name;
    std::string tabelNumber;
    double mounthHours;
    double mounthSalry;

};
typedef struct Person Person;



std::pair<Person*, size_t> newPersons();

void printPersons(Person *persons, size_t size);

Person* addPerson(Person* persons, size_t &size);

Person* deleteOnePerson(Person *persons, size_t &size, size_t index);

#endif //STRUCTFUNCTIONS_H

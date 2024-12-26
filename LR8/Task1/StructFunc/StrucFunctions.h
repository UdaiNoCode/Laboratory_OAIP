//
// Created by udainoko on 12/15/24.
//


#pragma once
#ifndef STRUCFUNCTIONS_H
#define STRUCFUNCTIONS_H
#include <utility>
#include <iostream>
#include <unordered_set>

struct Marks {
    int n_size;
    int *math;
    int *physical;
    int *chemistry;
};
typedef struct  Marks Marks;

struct Person {
    std::string name;
    std::string address;
    Marks marks;
};
typedef struct Person person;


void deletePerson(Person* persons, size_t& n);

std::pair<Person*, size_t> newPersons();


void print_persons(Person* persons, size_t size);

Person* add_person(Person* persons, size_t &size);

std::unordered_set<size_t> find_person(Person *persons, size_t size);

void print_finded_persons(Person *persons, size_t size, std::unordered_set<size_t>& indexed);

void sort_persons(Person *persons, size_t size);

Person* deleteOnePerson(Person *persons, size_t &size, size_t index);

#endif //STRUCFUNCTIONS_H

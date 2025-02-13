#include "TextFunctions.h"

#include <cstring>
#include <iostream>

int trueWorldCounter(char* array, size_t size) {
    int counter = 1;
    for (size_t i = 0; i < size; i++) {
        if (array[i] == ' ' and array[i + 1] != ' ') {
            counter++;
        }
    }
    return counter;
}

int inWichWorld(char* array, size_t size,int k) {
    if (size < k or k < 0) {
        return -1;
    }

    int world_counter = 1;

    for (size_t i = 0; i < k - 1; i++) {
        if (array[i] == ' ' and array[i + 1] != ' ') {
            world_counter++;
        }
    }

    if (array[k - 1] == ' ') {
        return world_counter != 0? world_counter - 1 : 0;
    }
    return world_counter;
}

std::pair<int, char**> findWorld(char* array, size_t size) {

    char* word = new char[size + 1];

    strcpy(word, array);
    word[size] = '\0';

    int word_count = trueWorldCounter(word, size);

    char** words_out_array = new char*[word_count];

    char *pch = strtok (word,"       ");
    int i_count = 0;

    while (pch != nullptr)                         // пока есть лексемы
    {
        words_out_array[i_count] = new char[strlen(pch) + 1];
        if (strlen(pch) == 1 or pch[0] == pch[strlen(pch) - 1]) {
            strcpy(words_out_array[i_count], pch);
            i_count++;
        }
        pch = strtok (nullptr, "       ");
    }
    if (array != nullptr) {
        free(array);
    }
    return {i_count, words_out_array};

}

int findSum(char* array, size_t size) {
    int sum = 0;
    int minus = -1;

    bool first_in = false;

    for (size_t i = 0; i < size; i++) {
        if (isdigit(array[i])) {
            if (!first_in) {
                first_in = true;
                if (i != 0 and array[i - 1] == '-') {
                    sum += (array[i] - '0')*minus;
                    minus *= -1;
                }
                else{
                    sum += (array[i] - '0');
                }

            }
            else {
                sum += (array[i] - '0')*minus;
                minus *= -1;
            }
        }
    }
    return sum;

}
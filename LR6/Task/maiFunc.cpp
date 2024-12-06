//
// Created by udainoko on 11/28/24.
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <utility>
#include "maiFunc.h"

#include <iostream>

char *readline() {
    char *s = (char *)malloc(1);
    std::cout<<"Enter a string: \t"; // It can be of any length
    int c;
    int i = 0;
    /* Read characters until found an EOF or newline character. */
    while((c = getchar()) != '\n' && c != EOF)
    {
        s[i++] = c;
        s = (char*)realloc(s, i+1); // Add space for another character to be read.
    }
    s[i] = '\0';  // Null terminate the string
    return s;

}

void context_1() {
    std::cout<<"Дана строка, состоящая из слов, разделенных пробелами. Вывести\n"
"на экран порядковый номер слова, содержащего k-ю позицию, если в k-й\n"
"позиции пробел, то вывести номер предыдущего слова. Значение k ввести с\n"
"клавиатуры.\n";
}

void context_2() {
    std::cout<<"В тексте найти и напечатать слова, начинающиеся и\n"
                "оканчивающиеся гласной букво\n";
}

void context_3() {
    std::cout<<"Ввести строку и вычислить сумму входящих в неё цифр, причем\n"
            "знак очередного слагаемого должен быть противоположным знаку\n"
            "предыдущего слагаемого\n";
}




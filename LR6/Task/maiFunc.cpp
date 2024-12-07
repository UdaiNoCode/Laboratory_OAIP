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
    std::cout<<"Enter a string: \t";
    int c;
    int i = 0;
    /* Read characters until found an EOF or newline character. */
    while((c = getchar()) != '\n' && c != EOF)
    {
        s[i++] = c;
        s = (char*)realloc(s, i+1); // Add space for another character to be read.
    }
    s[i] = '\0';
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
                "оканчивающиеся одинаковой буквой\n";
}

void context_3() {
    std::cout<<"Ввести строку и вычислить сумму входящих в неё цифр, причем\n"
            "знак очередного слагаемого должен быть противоположным знаку\n"
            "предыдущего слагаемого\n";
}


size_t input_size_validate() {
    size_t number;
    std::cout << "Enter an integer: ";
    while (!(std::cin >> number)) {
        std::cout << "Invalid input. Please enter an positive integer: ";
        std::cin.clear();
        std::cin.ignore(12345, '\n');
    }
    return number;
}

bool program_stop() {
    std::cout<<"Если хотите завершить программу нажмите q\nЧтобы повторить вывод нажмите r\n";
    std::string stop_check;
    std::cin>>stop_check;
    while(stop_check != "q" and  stop_check != "r" ) {
        std::cout<<"Введите згачение еще раз:\n"
                   "q - завершение\n"
                   "r - рестарт\n";

        std::cin>>stop_check;
    }
    if (stop_check == "q") {
        std::cout<<"Программа завершена";
        return false;
    }
    return true;
}
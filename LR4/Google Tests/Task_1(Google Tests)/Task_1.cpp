#include <iostream>
#include <cmath>
#include "Task_1.h";


int finder(long double array[],int len_massive ) {



    int element_less_counter{0};


    long double middle_elment = len_massive % 2 == 0 ? array[len_massive / 2] : array[len_massive / 2 + 1];
    for(int i = 0; i < len_massive; i++) {
            if(fabsl(middle_elment - array[i]) <= 3) {
                element_less_counter++;
            }
        }

    return element_less_counter;

}

#include <iostream>
#include <cmath>

long double array[10000];
void contex_menu() {
    std::cout<<"Ввести одномерный статический массив из k чисел."<<std::endl;
    std::cout<<"Найти количество элементов массива, отличающихся от среднего"
                "значения элементов массива не более чем на 3."<<std::endl;
}

long double check_validate() {
    long double x;
    while (!(std::cin >> x) or std::cin.get() != '\n')
    {
        std::cout << "Error!" << std::endl << "Введите значение повторно "<< ": ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return x;
}
int check_validate_int() {
    int x;
    while (!(std::cin >> x) or std::cin.get() != '\n')
    {
        std::cout << "Error!" << std::endl << "Введите значение повторно "<< ": ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return x;
}

int int_cheker() {
    int a;
    while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно:\n";
        std::cin >> a;
    }
    return a;
}


int main() {
    contex_menu();


    bool screen = true;
    int len_massive;
    int element_less_counter{0};
    std::string input_check;
    while(screen) {
        element_less_counter = 0;
        std::cout<<"Введите длинну массива: ";
        len_massive = check_validate_int();
        std::cout<<"\n";

        for(int i = 0; i < len_massive; i++) {
            long double elem = check_validate();
            array[i] = elem;
        }

        long double middle_elment = len_massive % 2 == 0 ? array[len_massive / 2] : array[len_massive / 2 + 1];
        for(int i = 0; i < len_massive; i++) {
            if(fabsl(middle_elment - array[i]) <= 3) {
                element_less_counter++;
            }
        }



        std::cout<<"Колличество таких эллементов = " << element_less_counter<<std::endl;

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
            screen = false;
        }
    }
}
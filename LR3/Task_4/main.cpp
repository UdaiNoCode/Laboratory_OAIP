#include <iostream>
#include <cmath>

void contex_menu() {
    std::cout<<"Необходимо разложить функцию Y(x) из своего варианта в ряд S(x),\n"
        "затем с помощью полученного ряда найти значение функции и сравнить его со\n"
        "значением, вычисленным с помощью стандартных функций. программа\n"
        "должна запросить у пользователя количество членов ряда (n), затем запросить\n"
        "у пользователя количество чисел, от которых он хочет посчитать функцию,\n"
        "затем пользователь вводит по одному числу (x от 0.1, до 1), программа считаетзначение функции с помощью ряда и с помощью стандартных функций и\n"
        "выводит оба значения.\n";

    std::cout<<"Выполснено Савиновым Арсенией г.453503\n"<<std::endl;

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

int factorial(int  n){

    return (n==0) || (n==1) ? 1 : n * factorial(n-1);
}

long double my_func( long double x) {
    long double y = (1.0 - x * x / 2.0) * cosl(x) - x/2 * sinl(x);
    return y;
}

long double riad(long double n, long double x) {
    long double riad_sum{0};
    for (int i = 0; i <= n; i++) {
        long double y = pow(-1.0 , i) * (2 * i * i + 1)/(double)(factorial(2*i)) * powl(x , 2 * i);
        riad_sum += y;
    }
    return riad_sum;
}

int main(){

    contex_menu();


    while(true) {
        std::cout <<"Сколько чисел от который вы хотите посчитать функцию\n";
        int atgument_counter = check_validate_int();


        for (int i = 0; i < atgument_counter; i++){
            std::cout<<"Введите количество членов ряда 4-byte n"<<std::endl;
            int n = check_validate_int();


            std::cout<<"Введите аргумент в x диапазоне (0.1, 1)" << std::endl;

            long double x = check_validate();
            if(x < 0.1 or x > 1) {
                x = check_validate();
            }


            std::cout<<"f(x) = "<<my_func(x)<<std::endl<<"riad(n,x) = "<<riad(n,x)<<std::endl;
        }

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
            break;
        }
    }
    std::cout<<"Программа завершена";
}

#include <iostream>
#include<cmath>



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

long double my_function(long double x) {
    long double y = sinl(log10l(x)) + x*(cosl(x*x) / sinl(x*x));
    return y;
}

int main() {
    bool screen = true;
    while(screen) {
        long double min_func_val = my_function(0.5);
        long double min_funnc_x = 0;

        std::cout << "Введите шаг поиска" << std::endl;

        long double step = check_validate();

        for(long double i = 0.5; i <= 1.5; i += step) {
            if(fabsl(my_function(i)) <=  min_func_val) {
                min_func_val = my_function(i);
                min_funnc_x = i;
            }
        }
        std::cout <<"Корень уравнения = "<< min_funnc_x << std::endl<<std::endl;

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
    std::cout<<"Программа завершена";
}
#include <iostream>
#include <cmath>

int main() {
    std::cout << "Используя цикл do while найти сумму ряда d = 1/(2^n) + 1/(3n)  с точностью 𝜀 = 10^-3 " << std::endl;
    std::cout<<"Выполнено Савиновым Арсением г.453503\n\n\n";
    bool screen = true;
    while(screen){
        long double n {1}, d_n{0}, d_i;

        do {
            d_i = 1/pow(2,n) + 1/(pow(3, n));
            d_n += d_i;
            n += 1;
        }
        while (d_i >= 0.001);

        std::cout<<"Сумма ряда = "<<d_n<<std::endl;


        std::cout<<"Если хотите завершить программу нажмите q\nЧтобы повторить вывод нажмите r\n";
        std::string stop_check;
        std::cin>>stop_check;
        while(stop_check != "q" and  stop_check != "r" ) {
            std::cout<<"Введите значение еще раз:\n"
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

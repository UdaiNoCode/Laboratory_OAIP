#include <iostream>
#include <cmath>
#include <utility>


void contex_menu() {
    std::cout<<"Использую цикл for составить программу вычисления значений\n"
                    "функции y = sin(x) - cos(x) на отрезке [A, B] в точках 𝑋𝑖 = 𝐴 + 𝑖 ∗ 𝐻,\n"
                    "где H = (B - A) / M, M = 20, A = 0, B = π / 2.\n";

    std::cout<<"Выполснено Савиновым Арсенией г.453503"<<std::endl;

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

int main() {
    contex_menu();
    const double A = 0, B = M_PI/2, M = 20;
    double h = (B - A) / M;
    while (true) {
        long double start_i, x;

        std::cout<<"Введите значение шага i в промежутке от [0, 20]"<<std::endl;

        start_i = check_validate();

        std::cout<<h<<std::endl;
        for (long double i = 0; i <= B; i += start_i) {
            x = A + i * h;
            std::cout<<"i("<<i<<") = "<<x<<std::endl;
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

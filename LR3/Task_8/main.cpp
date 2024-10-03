#include <iostream>
#include <cmath>

int main()
{
    bool screen = true;
    while(screen) {
        long double b_0;
        std::cout << "Введите первый член прогрессии" << std::endl;
        std::cin >> b_0;
        int shag_b = -2;

        std::cout<<"Введите колличество" << std::endl;
        int n_number;
        std::cin >> n_number;

        long double sum_of_progression = b_0 *(pow(shag_b, n_number) - 1) / (shag_b - 1);

        std::cout<<sum_of_progression<<std::endl;


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
   std::cout << "Завершение программы";
}

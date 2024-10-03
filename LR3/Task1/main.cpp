
#include <iostream>

int main() {
    //Context menu
    std::cout<<"Используя цикл while вычислить 𝑁 = ∑30𝑖=1(𝑎𝑖 − 𝑏𝑖 )\n";
    std::cout<<"Выполнено Савиновым Арсением г.453503\n\n\n";

    while (true) {
        long double a,b,n_summ{0};


        for(int i = 1; i <= 30; i++) {

            if (i % 2 == 0) {
                a = i/2;
                b = i * i * i;
            }
            else {
                a = i;
                b = i * i;
            }

            n_summ += (a + b) * (a + b);


        }
        std::cout<<"Сумма равна  = "<<n_summ<<std::endl;

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

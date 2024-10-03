#include <iostream>
#include <cmath>
#include <utility>

bool str_chek(std::string input){
    int dot_counter = 0, i_if_minus;
    if(input[0] == '-' && input.length() != 1){
        i_if_minus = 1;

    }
    else{
        i_if_minus = 0;
    }


    for (int i = i_if_minus; i < input.length(); i ++)
    {
        if(isdigit(input[i]) == false){
            if (input[i] == '.' && dot_counter < 1){
                dot_counter ++;
            }
            else{
                return false;
            }
        }
    }
    return true;

}

long double durachek_check_v_1(bool type, std::string first_input)
{

    bool cheker = type;
    std::string input_in_test = std::move(first_input);
    while (!cheker)
    {
        std::cout<<"Введите значение повторно: \n";
        std::cin>>input_in_test;
        cheker = str_chek(input_in_test);

    }

    long double return_cin = std::stold(input_in_test);
    return return_cin;
}




int main() {
    const double A = 0, B = M_PI/2, M = 20;
    double h = (B - A) / M;
    while (true) {
        long double start_i, x;
        std::string start;
        std::cout<<"Введите значение шага i в промежутке от [0, 20]"<<std::endl;
        std::cin>>start;

        start_i = durachek_check_v_1(str_chek(start), start);
        if(start_i < 0 or start_i > 20) {
            start = "Wrong input";
            start_i = durachek_check_v_1(str_chek(start), start);
        }
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

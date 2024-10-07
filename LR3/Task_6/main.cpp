#include <iostream>
#include <cmath>


bool str_chek(std::string input){
    int dot_counter = 0, i_if_minus;
    if(input[0] == '-' && input.length() != 1){
        i_if_minus = 1;

    }
    else{
        i_if_minus = 0;
    }

    int e_counter {0},  if_e{0};
    if(input[0] == 'e') {
        if_e = 1;
    }



    for (int i = i_if_minus; i < input.length(); i ++)
    {
        if(isdigit(input[i]) == false){
            if (input[i] == '.' && dot_counter < 1) {
                dot_counter ++;
            }
            else if(input[i] == 'e' && if_e == 0 && e_counter <= 1) {
                e_counter++;
            }
            else {
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


int factorial( int n){

    return (n==0) || (n==1) ? 1 : n * factorial(n-1);
}

long double sinus(long double x) {
    long double x_1 = x * 180/ M_PI;
    if (x_1 >= 90) {
        x_1 = 180 - x_1;;
    }
    if (x_1 <= -90) {
        x_1 = -1 *(180 + x_1);
    }
    x_1 = x_1 * M_PI / 180;
    long double y{0};
    for (int i = 0; i <= 15; i++) {
        y +=  pow(-1, i) * (powl(x_1, 2 * i  + 1)) / factorial(2 * i + 1);
    }
    return y;
}

long double cosus(long double x) {
    long double x_1 = x * 180/ M_PI;;
    long double y{0};
    int minus{1};
    x_1 = x_1 < 0? -1 * x_1 : x_1;
    if(x_1 > 90) {
        x_1 = 180 - x_1;
        minus = -1;;
    }

    x_1 = x_1 * M_PI / 180;
    for(int i = 0 ; i <= 15; i++) {
        y += pow(-1, i) * (powl(x_1, 2 * i)) / factorial(2 * i);
    }
    return y * minus;
}


long double logos(long double x_1) {
    long double x = x_1 < 0? -1 * x_1 : x_1;

    if (x >= 2) {
        return logos(x/2.0) + 0.6931;
    }

    x = x-1;

    long double total = 0.0;
    long double xToTheIPower = x;

    for (unsigned i = 1; i < 100; i++) {

        if (i%2 == 1) {
            total += xToTheIPower / (i);
        } else {
            total -= xToTheIPower / (i);
        }

        xToTheIPower *= x;
    }

    return total;
}



int main() {

    bool screen = true;

    while(screen) {
        std::string input;

        std::cout<<"Введите угол в градусах"<<std::endl;
        std::cin >> input;
        long double ugol_def = durachek_check_v_1(str_chek(input), input);
        long double ugol = ugol_def - 180 * truncl(ugol_def/ 180);
        // std::cout << ugol<< std::endl;
        std::cout << "sin(x) = " <<  sinus(ugol * M_PI / 180) << std::endl;
        std::cout << "cos(x) = " <<cosus(ugol * M_PI / 180) << std::endl;
        if(ugol_def == 0) {
            std::cout<<"BAN";
        }else {
            std::cout << "ln(x) = "<<logos(ugol_def * M_PI / 180) << std::endl;
        }


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

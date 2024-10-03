#include <iostream>
#include<cmath>


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

 double durachek_check_v_1(bool type, std::string first_input)
{

    bool cheker = type;
    std::string input_in_test = std::move(first_input);
    while (!cheker)
    {
        std::cout<<"Введите значение повторно: \n";
        std::cin>>input_in_test;
        cheker = str_chek(input_in_test);

    }

    double return_cin = std::stold(input_in_test);
    return return_cin;
}

double my_function(double x) {
    double y = sin(log10(x)) + x*(cos(x*x) / sin(x*x));
    return y;
}
int main() {
    bool screen = true;
    while(screen) {
        double min_func_val = my_function(0.5);
        double min_funnc_x = 0;

        std::cout << "Введите шаг поиска" << std::endl;
        std::string input_step;
        double step;
        std::cin >> input_step;
        step = durachek_check_v_1(str_chek(input_step), input_step);

        for(double i = 0.5; i <= 1.5; i += step) {
            if(abs(my_function(i)) <=  min_func_val) {
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
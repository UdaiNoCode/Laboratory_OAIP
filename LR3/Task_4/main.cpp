#include <iostream>
#include <cmath>

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

int factorial( double n){

    return (n==0) || (n==1) ? 1 : n * factorial(n-1);
}

 double my_func( double x) {
     double y = (1.0 - x * x / 2) * cos(x) - x/2 * sin(x);
    return y;
}

double riad(double n, double x) {
    double riad_sum{0};
    for (int i = 0; i <= n; i++) {
        double y = pow(-1.0 , i) * (2 * i * i + 1)/(double)(factorial(2*i)) * pow(x , 2 * i);
        riad_sum += y;
    }
    return riad_sum;
}

int main()
{
    while(true) {
        std::cout <<"Сколько чисел от который вы хотите посчитать функцию\n";
        int atgument_counter;
        std::cin >> atgument_counter;
        if(std::cin.fail()) {
            atgument_counter = int_cheker();
        }

        for (int i = 0; i < atgument_counter; i++){
            std::cout<<"Введите количество членов ряда 4-byte n"<<std::endl;
            int n;
            std::cin >> n;
            if(std::cin.fail()) {
                n = int_cheker();
            }


            std::cout<<"Введите аргумент в x диапазоне (0.1, 1)" << std::endl;
            std::string x_input;
            std::cin >> x_input;
            long double x = durachek_check_v_1(str_chek(x_input), x_input);
            if(x < 0.1 or x > 1) {
                x_input = "Wrong input";
                x = durachek_check_v_1(str_chek(x_input), x_input);
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

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


int factorial( double n){

    return (n==0) || (n==1) ? 1 : n * factorial(n-1);
}

double sinus(double x) {
    double x_1 = x * 180/ M_PI;
    if (x_1 >= 90) {
        x_1 = 180 - x_1;;
    }
    if (x_1 <= -90) {
        x_1 = -1 *(180 + x_1);
    }
    x_1 = x_1 * M_PI / 180;
    double y{0};
    for (int i = 0; i <= 20; i++) {
        y +=  pow(-1, i) * (pow(x_1, 2 * i  + 1)) / factorial(2 * i + 1);
    }
    return y;
}

double cosus(double x) {
    double x_1 = x * 180/ M_PI;;
    double y{0};
    int minus{1};
    x_1 = x_1 < 0? -1 * x_1 : x_1;
    if(x_1 > 90) {
        x_1 = 180 - x_1;
        minus = -1;;
    }

    x_1 = x_1 * M_PI / 180;
    for(int i = 0 ; i <= 20; i++) {
        y += pow(-1, i) * (pow(x_1, 2 * i)) / factorial(2 * i);
    }
    return y * minus;
}

double logos(double x) {

        double x_1 = x <  0? -1 * x : x;
        double ratio = (x_1 - 1) / (x_1 + 1);

        double accumul = ratio;

        double total = accumul;

        int power = 3;
        int n = 40;
        while (power < n) {

            accumul *= ratio;

            accumul *= ratio;

            total += (1 / (double) power) * accumul;

            power += 2;
        }

        return 2.0 * total;

}


int main() {
    long double ugol, ugol_cel, ugol_def, y_ugol ;
    std::string input;

    std::cin >> input;
    ugol_def = durachek_check_v_1(str_chek(input), input);
    ugol = ugol_def - 180 * truncl(ugol_def/ 180);
    std::cout << ugol<< std::endl;
    std::cout << "sin(x) = " <<  sinus(ugol * M_PI / 180) << std::endl;
    std::cout << "cos(x) = " <<cosus(ugol * M_PI / 180) << std::endl;
    if(ugol != 0){
        std::cout << "ln(x) = "<<logos(ugol * M_PI / 180) << std::endl;
    }
    else {
        std::cout<<"ln(x) не существует\n";
    }
}
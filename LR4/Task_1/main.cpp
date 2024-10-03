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


int main() {
    std::cout<<"Ввести одномерный статический массив из k чисел."<<std::endl;
    std::cout<<"Найти количество элементов массива, отличающихся от среднего"
                "значения элементов массива не более чем на 3."<<std::endl;


    bool screen = true;
    int len_massive;
    int element_less_counter{0};
    std::string input_check;
    while(screen) {
        element_less_counter = 0;
        std::cout<<"Введите длинну массива: ";
        std::cin>>len_massive;
        if(std::cin.fail()) {
            len_massive = int_cheker();
        }
        std::cout<<"\n";
        double array[len_massive];
        double elem, middle_elment;
        for(int i = 0; i < len_massive; i++) {
            std::cin>>input_check;
            elem = durachek_check_v_1(str_chek(input_check), input_check);
            array[i] = elem;
        }

        middle_elment = len_massive % 2 == 0 ? len_massive / 2 : len_massive / 2 + 1;
        for(int i = 0; i < len_massive; i++) {
            if(fabs(middle_elment - array[i]) <= 3) {
                element_less_counter++;
            }
        }



        std::cout<<"Колличество таких эллементов = " << element_less_counter<<std::endl;

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
}
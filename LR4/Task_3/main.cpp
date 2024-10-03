#include <iostream>


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
        std::cin.ignore();
        std::cout << "Введите значение повторно:\n";
        std::cin >> a;
    }
    return a;
}


int main() {

    std::cout << "Найти в каждой строке матрицы максимальный элемент." << std::endl;
    std::cout <<"Сделано Савиновым Арсением гр. 453503"<<std::endl;
    bool screen = true;

    while(screen) {

        std::cout <<"Введите размер матрицы N * M (Целочисленный 8-byte)"<<std::endl;
        int n, m;
        std::cin >> n;
        if(std::cin.fail()) {
            n = int_cheker();
        }
        std::cin >> m;
        if(std::cin.fail()) {
            m = int_cheker();
        }
        std::cout<<"\n";

        double matrix[n][m], line_of_max[n];
        std::string input_in;

        std::cout<<"Введите элементы матрицы: \n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                std::cin >> input_in;
                matrix[i][j] = durachek_check_v_1(str_chek(input_in), input_in);
            }
        }

        for(int i = 0; i < n; i++) {
            int maximum = matrix[i][0];
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] > maximum) {
                    maximum = matrix[i][j];
                }
            }
            line_of_max[i] = maximum;
        }

        for(int i = 0; i < n; i++) {
            std::cout<<i + 1<<" строка : "<<line_of_max[i]<<std::endl;
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
            screen = false;
        }
    }
    std::cout<<"Программа завершена\n";
}

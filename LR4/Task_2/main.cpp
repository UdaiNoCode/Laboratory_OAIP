
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>


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

int main()
{
    std::cout << "Дана действительная квадратная матрица порядка N. Рассмотрим те\n"
            "элементы, которые расположены в строках, начинающихся с\n"
            "отрицательного элемента. Найти сумму тех из них, которые\n"
            "расположены соответственно ниже, выше и на главной диагонали\n"
            "матрицы." << std::endl;

    std::cout<<"Выполнено Савиновым Арсением"<<std::endl;
    bool screen = true;
    while(screen) {
        int n_matrix_syze;
        double under_diog_sum{0}, on_diog_sum{0}, above_diog_sum{0};
        std::cout<<"Введите размер матрицы N: ";
        std::cin >> n_matrix_syze;
        std::string input_elem;
        if(std::cin.fail()) {
            n_matrix_syze = int_cheker();
        }
        std::cout<<std::endl;

        std::vector<std::vector<double>> matrix;
        std::vector<double> submatrix;

        for(int i = 0; i < n_matrix_syze; i++) {
            for(int j = 0; j < n_matrix_syze; j++) {
                std::cin >> input_elem;
                submatrix.push_back(durachek_check_v_1(str_chek(input_elem), input_elem));
            }
            matrix.push_back(submatrix);

        }

        for(int i = 0; i < n_matrix_syze; i++) {
            if(matrix[i][0] < 0) {
                //under the dioganal
                for(int j = 0; j < i; j++) {
                    under_diog_sum += matrix[i][j];
                }

                on_diog_sum += matrix[i][i];

                for(int j = i + 1; j < n_matrix_syze; j++ ) {
                    above_diog_sum += matrix[i][j];
                }
            }
        }
        std::cout<<"Сумма ниже диоганали: "<<under_diog_sum<<std::endl;
        std::cout<<"Сумма на диогашали: "<<on_diog_sum<<std::endl;
        std::cout<<"Сумма выше диоганали: "<<above_diog_sum<<std::endl;

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

        matrix.clear();
        submatrix.clear();
    }
}

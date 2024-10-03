#include <iostream>
#include <vector>
#include <set>

const int max_len = 32400;
bool chek_not_syb(std::string inp) {
    if(inp == "*") {
        return false;
    }
    return true;


}


int int_cheker() {
    int a;
    while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(max_len, '\n');
        std::cout << "Введите значение повторно:\n";
        std::cin >> a;
    }
    return a;
}

std::vector<std::vector<std::string>> area_pluss(int index_m, int index_n, std::vector<std::vector<std::string>> input) {
    if(index_m == 0 && index_n == 0) {
        input[index_m + 1][index_n] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(std::stoi(input[index_m + 1][index_n]) + 1) : "*";
        input[index_m][index_n + 1] = chek_not_syb(input[index_m][index_n + 1]) ? std::to_string(std::stoi(input[index_m][index_n + 1]) + 1) : "*";
        input[index_m + 1][index_n + 1] = chek_not_syb(input[index_m + 1][index_n + 1]) ? std::to_string(std::stoi(input[index_m + 1][index_n + 1]) + 1) : "*";
    }
    else if(index_m == input[0].size() - 1 && index_n == input[0].size() - 1) {
        input[index_m - 1][index_n] = chek_not_syb(input[index_m - 1][index_n]) ? std::to_string(std::stoi(input[index_m - 1][index_n]) + 1): "*";
        input[index_m][index_n - 1] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(std::stoi(input[index_m][index_n - 1]) + 1): "*";
        input[index_m - 1][index_n - 1] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(std::stoi(input[index_m - 1][index_n + 1]) + 1): "*";
    }
    else if(index_m == 0 && index_n == input.size() - 1){
        input[index_m + 1][index_n] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(std::stoi(input[index_m + 1][index_n]) + 1): "*";
        input[index_m][index_n - 1] = chek_not_syb(input[index_m][index_n - 1])?std::to_string(std::stoi(input[index_m][index_n - 1]) + 1): "*";
        input[index_m + 1][index_n - 1] = chek_not_syb(input[index_m + 1][index_n - 1])?std::to_string(std::stoi(input[index_m + 1][index_n - 1]) + 1): "*";
    }
    else if(index_m == input.size() - 1 && index_n == 0) {
        input[index_m - 1][index_n] = chek_not_syb(input[index_m - 1][index_n])?std::to_string(stoi(input[index_m - 1][index_n]) + 1): "*";
        input[index_m][index_n + 1] = chek_not_syb(input[index_m][index_n + 1])?std::to_string(stoi(input[index_m][index_n + 1]) + 1): "*";
        input[index_m - 1][index_n + 1] = chek_not_syb(input[index_m - 1][index_n + 1])?std::to_string(stoi(input[index_m - 1][index_n + 1]) + 1): "*";
    }
    else if(index_m == 0) {
        input[index_m + 1][index_n] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(std::stoi(input[index_m + 1][index_n]) + 1): "*";
        input[index_m][index_n + 1] = chek_not_syb(input[index_m][index_n + 1])?std::to_string(std::stoi(input[index_m][index_n + 1]) + 1): "*";
        input[index_m][index_n - 1] = chek_not_syb(input[index_m][index_n - 1])?std::to_string(std::stoi(input[index_m][index_n - 1]) + 1): "*";
        input[index_m + 1][index_n + 1] = chek_not_syb(input[index_m + 1][index_n + 1])?std::to_string(std::stoi(input[index_m + 1][index_n + 1]) + 1): "*";
        input[index_m + 1][index_n - 1] = chek_not_syb(input[index_m + 1][index_n - 1])?std::to_string(std::stoi(input[index_m + 1][index_n - 1]) + 1): "*";
    }
    else if(index_m == input[0].size() - 1) {
        input[index_m - 1][index_n] = chek_not_syb(input[index_m - 1][index_n])?std::to_string(stoi(input[index_m - 1][index_n]) + 1): "*";
        input[index_m][index_n + 1] = chek_not_syb(input[index_m][index_n + 1])?std::to_string(stoi(input[index_m][index_n + 1]) + 1): "*";
        input[index_m][index_n - 1] = chek_not_syb(input[index_m][index_n - 1])?std::to_string(stoi(input[index_m][index_n - 1]) + 1): "*";
        input[index_m - 1][index_n + 1] = chek_not_syb(input[index_m - 1][index_n + 1])?std::to_string(stoi(input[index_m - 1][index_n + 1]) + 1): "*";
        input[index_m - 1][index_n - 1] = chek_not_syb(input[index_m - 1][index_n - 1])?std::to_string(stoi(input[index_m - 1][index_n - 1]) + 1): "*";
    }
    else if(index_n == input[0].size() - 1) {
        input[index_m + 1][index_n] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(stoi(input[index_m + 1][index_n]) + 1): "*";
        input[index_m - 1][index_n] = chek_not_syb(input[index_m - 1][index_n])?std::to_string(stoi(input[index_m - 1][index_n]) + 1): "*";
        input[index_m][index_n - 1] = chek_not_syb(input[index_m][index_n - 1])?std::to_string(stoi(input[index_m][index_n - 1]) + 1): "*";
        input[index_m + 1][index_n - 1] = chek_not_syb(input[index_m + 1][index_n - 1])?std::to_string(stoi(input[index_m + 1][index_n - 1]) + 1): "*";
        input[index_m - 1][index_n - 1] = chek_not_syb(input[index_m - 1][index_n - 1])?std::to_string(stoi(input[index_m - 1][index_n - 1]) + 1): "*";
    }
    else if(index_n == 0) {
        input[index_m + 1][index_n] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(stoi(input[index_m + 1][index_n]) + 1): "*";
        input[index_m - 1][index_n] = chek_not_syb(input[index_m - 1][index_n])?std::to_string(stoi(input[index_m - 1][index_n]) + 1): "*";
        input[index_m][index_n + 1] = chek_not_syb(input[index_m][index_n + 1])?std::to_string(stoi(input[index_m][index_n + 1]) + 1): "*";
        input[index_m + 1][index_n + 1] = chek_not_syb(input[index_m + 1][index_n + 1])?std::to_string(stoi(input[index_m + 1][index_n + 1]) + 1): "*";
        input[index_m - 1][index_n + 1] = chek_not_syb(input[index_m - 1][index_n + 1])?std::to_string(stoi(input[index_m - 1][index_n + 1]) + 1): "*";
    }
    else {
        input[index_m + 1][index_n] = chek_not_syb(input[index_m + 1][index_n])?std::to_string(stoi(input[index_m + 1][index_n]) + 1): "*";
        input[index_m - 1][index_n] = chek_not_syb(input[index_m - 1][index_n])?std::to_string(stoi(input[index_m - 1][index_n]) + 1): "*";
        input[index_m][index_n + 1] = chek_not_syb(input[index_m][index_n + 1])?std::to_string(stoi(input[index_m][index_n + 1]) + 1): "*";
        input[index_m][index_n - 1] = chek_not_syb(input[index_m][index_n - 1])?std::to_string(stoi(input[index_m][index_n - 1]) + 1): "*";
        input[index_m - 1][index_n + 1] = chek_not_syb(input[index_m - 1][index_n + 1])?std::to_string(stoi(input[index_m - 1][index_n + 1]) + 1): "*";
        input[index_m - 1][index_n - 1] = chek_not_syb(input[index_m - 1][index_n - 1])?std::to_string(stoi(input[index_m - 1][index_n - 1]) + 1): "*";
        input[index_m + 1][index_n + 1] = chek_not_syb(input[index_m + 1][index_n + 1])?std::to_string(stoi(input[index_m + 1][index_n + 1]) + 1): "*";
        input[index_m + 1][index_n - 1] = chek_not_syb(input[index_m + 1][index_n - 1])?std::to_string(stoi(input[index_m + 1][index_n - 1]) + 1): "*";
    }
    return input;
}

int main() {
    bool screen = true;
    std::set<std::string> buf_check = {".", "*"};
    while(screen){
        int m_side, n_side;
        std::cout<<"Enter the side of the matrix: \n";
        std::cin>>m_side;
        if(std::cin.fail()) {
            m_side = int_cheker();
        }
        std::cin>>n_side;
        if(std::cin.fail()) {
            n_side = int_cheker();
        }

        std::vector<std::vector<std::string>> game_area;
        std::vector<std::string> sub_area_line;

        //Game area init
        for(int i=0;i<m_side;i++) {
            for(int j=0;j<n_side;j++) {
                std::string input_in;
                std::cin>>input_in;
                while(!buf_check.contains(input_in)) {
                    std::cout<<"Wrong input! Try again!\n";
                    std::cin>>input_in;
                }

                if(input_in == ".") {
                    input_in = "0";
                }
                sub_area_line.push_back(input_in);
            }
            game_area.push_back(sub_area_line);
            sub_area_line.clear();
        }


        for(int i=0;i<m_side;i++) {
            for(int j=0;j<n_side;j++) {
                if(game_area[i][j] == "*") {
                    game_area = area_pluss(i,j,game_area);
                }
            }
        }

        for(int i=0;i<m_side;i++) {
            for(int j=0;j<n_side;j++) {
                std::cout<<game_area[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
        game_area.clear();
        sub_area_line.clear();

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

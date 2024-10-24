#include <iostream>
#include <vector>
#include <algorithm>


std::string minus_one(std::string a) {
    if(a[0] == '-') {
        a[a.size() - 1] = ((a[a.size() - 1] - '0') + 1) + '0';
    }
    else {
        a[a.size() - 1] = ((a[a.size() - 1] - '0') - 1) + '0';
    }
    return a;
}
int max(int a, int b) {
    return a >= b ? a : b;
}
bool xor_check(bool a, bool b) {
    if(a == b or !a == !b) {
        return false;
    }
        return true;
}
//
// std::tuple<std::string, int> double_conventer(std::string a) {
//     int dot_pos = a.find('.');
//     a.erase(a.begin() +  dot_pos);
//     std::tuple<std::string, int>  ret_par = {a, dot_pos};
//     return std::tuple<std::string, int>
// }

std::string multyplus(std::string s1, std::string s2) {
    std::string result, median_res, median_res_mod;
    bool minus_1{false}, minus_2{false};


    if(s1[0] == '-') {
        minus_1 = true;
        s1.erase(s1.begin());
    }

    if(s2[0] == '-') {
        minus_2 = true;
        s2.erase(s2.begin());
    }

    if(s1.length() >= s2.length()) {


        int add{0};

        for(int i = s2.length() - 1; i >= 0; i--) {
            for(int j = s1.length() - 1; j >= 0; j--) {
                median_res_mod = std::to_string((add + (s2[i] - '0') * (s1[j] - '0')) % 10 );
                add = (add + (s2[i] - '0') * (s1[j] - '0')) / 10;
                result.append(median_res_mod);
                median_res_mod.clear();
            }
        }
        if(add > 0) {
            result.append(std::to_string(add));
        }

    }
    else {
        int add{0};

        for(int i = s1.length() - 1; i >= 0; i--) {
            for(int j = s2.length() - 1; j >= 0; j--) {
                median_res_mod = std::to_string((add + (s1[i] - '0') * (s2[j] - '0')) % 10 );
                add = (add + (s1[i] - '0') * (s2[j] - '0')) / 10;
                result.append(median_res_mod);
                median_res_mod.clear();
            }
        }
        if(add > 0) {
            result.append(std::to_string(add));
        }
    }

    if(xor_check(minus_1, minus_2)) {
        result.append("-");
    }
    reverse(result.rbegin(), result.rend());

    return result;



}

std::string dividing_of_3(std::string a, int b) {
    //b.size() always less then a.size()
    std::vector <int> c(a.size());
    bool minus_a{false}, minus_b{false};
    std::string subber, result;
    if(a[0] == '-') {
        a.erase(a.begin());
        minus_a = true;
    }
    if(b < 0) {
        minus_b = true;
        b *= -1;
    }
    int i_div = 0, len = 0;
    subber.append(std::to_string(a[0] - '0'));
    while(len < a.size()) {
        if(std::stoi(subber) >= b or std::stoi(subber) == 0) {
            c[i_div] = std::stoi(subber) / b;
            subber = std::to_string(std::stoi(subber) % b);
            i_div++;
            len++;
            subber.append(std::to_string(a[i_div] - '0'));
        }
        else {
            subber.append(std::to_string(a[i_div + 1] - '0'));
            len++;
        }


    }

    if(xor_check(minus_a, minus_b)) {
        result.append("-");
    }

    for(int i = 0; i < i_div; i++) {
        result.append(std::to_string(c[i]));
    }
    c.clear();
    return result;
}


long double check_validate() {
    long double x;
    while (!(std::cin >> x) or std::cin.get() != '\n')
         {
             std::cout << "Error!" << std::endl << "Введите значение повторно "<< ": ";
             std::cin.clear();
             while (std::cin.get() != '\n');
         }

    return x;
}


std::string power_abs(std::string a_power_base, int n) {
    std::vector<std::string> c(n + 1);
    c[0] = "1";
    int cout{0};
    for (int i = 1; i < n + 1; i++) {
        c[1] = multyplus(a_power_base, c[0]);
        c.erase(c.begin());
    }
    return c[0];

}


int main(){

    bool screen = true;
    while(screen) {

        std::cout << "Введите первый член прогрессии (8-byte): " << std::endl;
        std::string b_0;
        std::cin>>b_0;

        std::cout<<"Введите колличество членов прогрессии (8-byte): " << std::endl;
        int n_number = check_validate();

         std::string result_of_2 = dividing_of_3(multyplus("1",minus_one(power_abs("-2", n_number))),-3);
         std::string result_final = multyplus(result_of_2,b_0);
        //
         std::cout<<result_final<<std::endl;
         // std::cout<<double_conventer("1234.5678");



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
    std::cout << "Завершение программы";
    return 0;

}

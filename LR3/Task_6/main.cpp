#include <iostream>
#include <cmath>
#include<algorithm>
#include <ranges>
#include<vector>



void contex_menu() {
    std::cout<<"Из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при\n"
                    "заданном х, определить и вывести на экран дисплея минимальное значение.\n"
                    "Использование стандартных математических методов запрещено\n";

    std::cout<<"Выполснено Савиновым Арсенией г.453503"<<std::endl;

    std::cout<<"Введите угол в градусах 16-byte"<<std::endl;
}



int compare(std::string str1, std::string str2) {
    if (str1.size() != str2.size()) {
        return str1.size() < str2.size() ? -1 : 1;
    }
    if(str1 == str2) {
        return 1;
    }
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - '0' < str2[i]-'0' ? -1 : 1;
        }
    }
}


std::string multiply(std::string num1, std::string num2) {

    std::vector<int> vec1(num1.size());
    for (int i = 0; i < num1.size(); i++) {
        vec1[i] = num1[num1.size() - i - 1] - '0';
    }
    std::vector<int> vec2(num2.size());
    for (int i = 0; i < num2.size(); i++) {
        vec2[i] = num2[num2.size() - i - 1] - '0';
    }


    std::vector<int> result(vec1.size() + vec2.size());


    for (int i = 0; i < vec2.size(); i++) {
        int carry = 0;
        for (int j = 0; j < vec1.size(); j++) {
            int product = vec1[j] * vec2[i] + carry + result[i + j];
            carry = product / 10;
            result[i + j] = product % 10;
        }
        result[i + vec1.size()] = carry;
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    std::string str(result.size(), '0');
    for (int i = 0; i < result.size(); i++) {
        str[result.size() - i - 1] = result[i] + '0';
    }
    return str;
}

std::string diif_find(std::string str1, std::string str2) {
    //str1.size always bigger than str2.size
    std::ranges::reverse(str1);
    std::ranges::reverse(str2);


    //out string
    std::string output;

    int carry = 0;

    for(int i = 0; i < str2.size(); i++) {
        int subber = (str1[i] - '0') - (str2[i] - '0') - carry;

        if(subber < 0) {
            subber += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }

        output.push_back(subber + '0');
    }

    for(unsigned int i = str2.size(); i < str1.size(); i++) {
        int subber = (str1[i] - '0') - carry;

        if(subber < 0) {
            subber += 10;
            carry = 1;
        }
        else {
            carry = 0;
        }
        output.push_back(subber + '0');
    }

    std::reverse(output.begin(), output.end());

    int i_step = 0;

    while(output[i_step] == '0') {
        output.erase(output.begin() + i_step);
    }
    return output;
}

std::pair<std::string, int> full_diff(std::string number1, const std::string& number2) {
    int n = 0;
    while(compare(number1, number2) == 1) {
        number1 = diif_find(number1, number2);
        n++;
    }
    if(number1.empty()) {
        number1.push_back('0');
    }

    return {number1, n};
}

std::string long_Dividing(const std::string& a, const std::string& b) {
    std::string div, adder_to_div;
    bool start = false;

    for(char i : a) {
        if(adder_to_div[0] == '0') {
            adder_to_div.clear();
        }
        adder_to_div.push_back(i);

        if(compare(adder_to_div, b) == 1) {
            std::string temp = adder_to_div;
            div.append(std::to_string(full_diff(temp, b).second));
            adder_to_div = full_diff(temp, b).first;
            start = true;

        }
        else if(start) {
            div.push_back('0');
        }
    }
    return div;

}

std::pair<unsigned int, std::string> point_check(std::string a) {


    unsigned int point_pos = a.find('.');

    a.erase(a.begin() + point_pos);
    unsigned after_point = a.size() - point_pos;

    return {after_point , a};


}

std::pair<bool, long double> minus_check(long double a) {
    if(a < 0) {
        return std::make_pair(true, -a);
    }
    else {
        return std::make_pair(false, a);
    }
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

long double minium(long double a, long double b) {
    return a <= b ? a : b;
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

int factorial( int n){

    return (n==0) || (n==1) ? 1 : n * factorial(n-1);
}

long double sinus(long double x) {
    if (x >= M_PI / 2) {
        x = M_PI  - x;
    }
    if (x <= -M_PI / 2) {
        x = -1 *(M_PI + x);
    }
    long double y{0};
    for (int i = 0; i <= 12; i++) {
        y +=  powl(-1, i) * (powl(x, 2 * i  + 1)) / factorial(2 * i + 1);
    }
    return y;
}

long double cosus(long double x) {
    long double y{0};
    int minus{1};
    x = x < 0? -1 * x : x;
    if(x > M_PI / 2) {
        x = M_PI - x;
        minus = -1;;
    };
    for(int i = 0 ; i <= 12; i++) {
        y += pow(-1, i) * (powl(x, 2 * i)) / factorial(2 * i);
    }
    return y * minus;
}

long double logos(long double x_1) {
    long double x = x_1 < 0? -1 * x_1 : x_1;

    if (x >= 2) {
        return logos(x/2.0) + 0.69314718;
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


std::string PI_s = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919";
std::string P_double = multiply(PI_s, "2");

std::string remqls(std::string str_1, int point_pos) {
    //add 100 nulls dor approximation

    for (int i = 0; i < 50 + P_double.size() - 1; i++) {
        str_1.push_back('0');
    }

    std::string division = long_Dividing(str_1, P_double);
    division.insert(division.size() - 50 - point_pos, ".");
    //delete all before point

    //std::cout << division << std::endl;

    while(division[0] != '.') {
        division.erase(division.begin());
    }

    division.erase(division.begin());

    str_1 = multiply(division, P_double);

    str_1.insert(str_1.size() - 50 - P_double.size() + 1 - point_pos, ".");
    if(str_1[0] == '.') {
        str_1.insert(0, "0");
    }

    return str_1;

}

int main() {

    bool screen = true;

    while(screen) {


        contex_menu();


        long double ugol;
        long double ugol_def_num = check_validate();

        bool minus_flag = minus_check(ugol_def_num).first;

        ugol_def_num = minus_check(ugol_def_num).second;
        unsigned int point_sdwig = point_check(std::to_string(ugol_def_num)).first;
        std::string ugol_10 = point_check(std::to_string(ugol_def_num)).second;

         if(ugol_def_num <= 2 * M_PI) {
             if (ugol_def_num < 2 * M_PI) {
                 ugol = ugol_def_num;
             } else {
                 ugol = 0;
             }
         } else {
            ugol = stold(remqls(ugol_10, point_sdwig));
        }
        if(minus_flag) {
            ugol *= -1;
        }
        std::cout << ugol<< std::endl;
        std::cout << "sin(x) = " <<  sinus(ugol) << std::endl;
        std::cout << "cos(x) = " <<cosus(ugol) << std::endl;
        if(ugol <= 0) {
            std::cout<<"BAN"<<std::endl;
        }else {
            std::cout << "ln(x) = "<<logos(ugol_def_num) << std::endl;
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

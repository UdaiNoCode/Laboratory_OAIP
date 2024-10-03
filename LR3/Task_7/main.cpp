#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <ctime>
#include <vector>

std::string return_num(long  int a) {
    std::string num_st = std::to_string(a);
    std::sort(num_st.begin(), num_st.end());
    return num_st;

}


long int int_cheker() {
    long int a;
    while (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите значение повторно:\n";
        std::cin >> a;
    }
    return a;
}


    int  main() {
    bool screen = true;
    while(screen) {
        unsigned int start_time = clock();

        long int n;
        std::cout << "Enter a number(8-byte): ";
        std::cin>>n;

        if(std::cin.fail()) {
            n = int_cheker();
        }

        std::string num_in, num_check, nuumy;;
        int a{10}, i_power = 1;
        int summaery{0}, buff;
        int powers[10][10];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                powers[i][j] = pow(i, j);
            }
        }
        for(int i=1;i<n;i++) {
            if(i / a != 0) {
                i_power += 1;
                a *= 10;

            }
            buff = i;
            while (buff != 0) {
                summaery += powers[buff % 10][i_power];//multy[buff % 10];
                buff /= 10;
            }
            if(i == summaery) {
                std::cout<<i<<"\n";
            }
            summaery = 0;

        }
        unsigned int end_time = clock(); // конечное время
        unsigned int search_time = end_time - start_time;
        std::cout<<search_time / 1000.0<<std::endl;

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




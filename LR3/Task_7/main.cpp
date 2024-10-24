#include <iostream>
#include <cmath>

long int int_input() {
    long int x;
    while (!(std::cin >> x) or std::cin.get() != '\n')
    {
        std::cout << "Error!" << std::endl << "Введите значение повторно "<< ": ";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return x;
}


    int  main() {

    std::cout<<"Программу, которая выводит все числа Армстронга, меньше введённого\n"
                "пользователем числа.\n";
    std::cout<<"Выполнено Савиновым Арсением г.453503\n";
    std::cout<<std::endl;
    bool screen = true;
    while(screen) {
        long int n;
        std::cout << "Enter a number(8-byte): ";
        n = int_input();

        std::string num_in, num_check, nuumy;;
        int a{10}, i_power = 1;
        int summaery{0};
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
            long long int buff = i;
            while (buff != 0) {
                summaery += powers[buff % 10][i_power];
                buff /= 10;
            }
            if(i == summaery) {
                std::cout<<i<<"\n";
            }
            summaery = 0;

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
    std::cout<<"Программа завершена";
}




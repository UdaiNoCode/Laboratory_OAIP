//
// Created by udainoko on 12/15/24.
//
#include "menuFunc.h"
#include <iostream>

namespace menu {
    void print_menu() {
        system("clear");  // очищаем экран
        std::cout<<"What do you want to do?\n";
        std::cout<<"1. Add person to list\n";
        std::cout<<"2. Print all persons in list\n";;
        std::cout<<"3. Clear the list\n";
        std::cout<<"4. Delete person\n";
        std::cout<<"5. Function\n";
        std::cout<<"6. Exit\n";
        std::cout<<">";
    }

    void clean_buffer(){
        char c;
        while ((c = getchar()) != EOF && c != '\n');
    } /* This will clean the buffer */


    void stop_system(){
        clean_buffer();
        printf("Press Enter to continue...");
        getchar();
    } /* This will wait for the user to press Enter, similar to system("pause") */

}

namespace inclmenu {
    void print_menu() {
        system("clear");  // очищаем экран
        std::cout<<"What do you want to do?\n";
        std::cout<<"1. Calculate salary(with taxes and bonuses)\n";
        std::cout<<"2. Change the persons\n";
        std::cout<<"3. Exit\n";
        std::cout<<">";
    }
}

namespace change {
    void print_menu() {

        system("clear");  // очищаем экран
        std::cout<<"What do you want to do?\n";
        std::cout<<"1. Change salary\n";
        std::cout<<"2. Change hours\n";
        std::cout<<"3. Exit\n";
        std::cout<<">";
    }
}
//
// Created by udainoko on 12/15/24.
//

#include "menu.h"
void print_menu() {
    system("clear");  // очищаем экран
    std::cout<<"What do you want to do?\n";
    std::cout<<"1. Add person to list\n";
    std::cout<<"2. Print all persons in list\n";
    std::cout<<"3. Find the person\n";
    std::cout<<"4. Sort alphabetical\n";
    std::cout<<"5. Clear the list\n";
    std::cout<<"6. Delete person\n";
    std::cout<<"7. Function\n";
    std::cout<<"8. Exit\n";
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

//
// Created by udainoko on 12/15/24.
//

#include<unordered_set>
#include<iomanip>
#include<format>


#include "MainTaskFunc.h"
#include "../Menu/menu.h"
#include "../StructFunc/StrucFunctions.h"



namespace mainFunc {
    //Counts middle ariffm
    double middleArifm(const int* array, size_t size) {

        double sum = 0;
        for (size_t i = 0; i < size; i++) {
            sum += array[i];
        }

        return sum / size;
    }

    //Menu showing
    void print_menu() {
        system("clear");  // очищаем экран
        std::cout<<"What do you want to do?\n";
        std::cout<<"1. Определить средний балл абитуриентов, проживающих в\n"
                    "городе Минске\n";
        std::cout<<"2. Подробная характеристика отметок\n";
        std::cout<<"3. Exit\n";
        std::cout<<">";
    }




    //Funtion that print persont who live in Minsk and their average marks
    void print_persons(Person *persons, size_t size, const std::unordered_set<size_t>& index) {
        std::cout.precision(3);
        std::cout<<"+-----------------------+---------------+\n";
        std::cout<<"|         Person        |  Average mark |\n";
        std::cout<<"+-----------------------+---------------+\n";

        if (size == 0)
            std::cout<<"|        No persons was founded...      |\n";

        for (auto i: index) {
            double average = (middleArifm(persons[i].marks.chemistry, persons[i].marks.n_size) +
                                middleArifm(persons[i].marks.math, persons[i].marks.n_size) +
                                middleArifm(persons[i].marks.physical, persons[i].marks.n_size)) / 3;


            std::cout<<std::setprecision(3)<< std::format("|{:^23}|{:^15.2f}|\n",
                                persons[i].name, average);

            std::cout.precision(3);
        }
        std::cout.precision(3);
        std::cout<<"+-----------------------+---------------+\n";
    }

    //Find indexes of Minsk living presons
    std::unordered_set<size_t> MainTaskFunc(Person* persons, size_t size) {
        std::unordered_set<size_t> persons_index;
        for (int i = 0; i < size; i++) {
            if (persons[i].address == "Minsk") {
                persons_index.insert(i);
            }
        }
        return persons_index;
    }



    void print_grades(const Person* students, size_t count, size_t index) {

        if (index > count) {
            std::cout<<"Wrong Input\n";
            return;
        }
        std::cout << std::left << std::setw(20) <<students[index - 1].name<< "Marks" << std::endl;
        std::cout << std::string(60, '-') << std::endl;


        std::cout << std::left << std::setw(20) << "Chemisrty";

        for (size_t i = 0; i < students[index - 1].marks.n_size; i++) {
                std::cout << std::fixed << std::setprecision(1) << students[index - 1].marks.chemistry[i] << " ";
            }
        std::cout << std::endl;



        std::cout << std::left << std::setw(20) << "Math";

        for (size_t i = 0; i < students[index - 1].marks.n_size; i++) {
            std::cout << std::fixed << std::setprecision(1) << students[index - 1].marks.math[i] << " ";
        }
        std::cout<<std::endl;


        std::cout << std::left << std::setw(20) << "Physics";

        for (size_t i = 0; i < students[index - 1].marks.n_size; i++) {
            std::cout << std::fixed << std::setprecision(1) << students[index - 1].marks.physical[i] << " ";
        }

        std::cout << std::endl;

    }


    //main function process
    void main_task(Person* persons, size_t size) {
        int variant;
        do {
            print_menu();
            std::cin>>variant;

            switch (variant) {
                case 1: { //Statement to whow MinskLiving people
                    std::unordered_set<size_t> persons_index = MainTaskFunc(persons, size);
                    print_persons(persons, size, persons_index);
                    break;
                }
                case 2: {
                    std::cout<<"Введите индекс ученика: \n";
                    std::cout<<">";

                    size_t index;
                    std::cin>>index;

                    print_grades(persons, size, index);

                    break;
                }
                default: {

                }
            }
            if (variant !=3 ) { //System stop
                stop_system();
            }

        }while(variant != 3);
    }


}

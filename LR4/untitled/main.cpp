#include <iostream>


int main() {
    int q,r,count = 0;
    std::cin >> q >> r;
    int a_1 = q;
    int a_2 = q*r;
    for(int i = 0; i <=a_1; i++) {
        for(int j = 1; j <= r; j++) {
            if((a_2 - i)  % j == 0) {
                count++;
                std::cout <<(j) << " ";
            }
        }
    }
    std::cout << count << std::endl;


}


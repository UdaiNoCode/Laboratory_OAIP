#include <iostream>


double maximum(int a, int b, int c, int d) {
    int arr[4]{a,b,c,d};
    int max = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    std::cout<<"Input size"<<std::endl;
    int n_size, diog_sum_1 = 0, diog_sum_2 = 0, diog_sum_3 = 0,diog_sum_4 = 0, summary = 0;
    std::cin>>n_size;

    int ***arr = new int** [n_size];
    for (int i = 0; i < n_size; i++) {
        arr[i] = new int* [n_size];

        for(int j = 0; j < n_size; j++) {
            arr[i][j] = new int[n_size];
        }
    }
    int k_sdwig = n_size - 1;
    int j_sdwig = n_size - 1;
    int i_sdwig = n_size - 1;
    for (int i = 0; i < n_size; i++) {
        for (int j = 0; j < n_size; j++) {
            for (int k = 0; k < n_size; k++) {
                std::cin>>arr[i][j][k];
            }
        }
    }

    for (int i = 0; i < n_size; i++) {
        diog_sum_1 +=  arr[i][i][i];
        diog_sum_2 +=  arr[i][i][k_sdwig];
        diog_sum_3 += arr[i][j_sdwig][i];
        diog_sum_4 += arr[i_sdwig][i][i];
        k_sdwig--;
    }

    std::cout<<maximum(diog_sum_1, diog_sum_2, diog_sum_3, diog_sum_4)<<std::endl;
}

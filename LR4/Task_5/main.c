#include <stdio.h>
#include <stdlib.h>


int check_validate_int()
{
    int input;
    while (scanf("%d",&input)==0)
    {
        printf("Invalid input. Please enter a number: ");
        scanf("%*s");
    }
    return input;
}

int checkinput() {

    char c;
    while (1) {
        c = getchar();
        if (c != '.' && c != '*') {
            continue;
        }
        if(c == '.') {
            return 0;
        }
        return -1;
    }
}
char programm_end_check() {

    while (1) {
        char c = getchar();
        if (c != 'q' && c != 'r') {
            printf("Введите згачение еще раз:\n"
                       "q - завершение\n"
                       "r - рестарт\n");
            continue;
        }
        return c;
    }
}

void nuller(int **matrix, int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            matrix[i][j] = 0;
        }
    }
}

void saper(int **matrix, int i , int j) {

    if(matrix[i+1][j] != -1 ) {matrix[i+1][j] += 1;}
    if(matrix[i+1][j+1] != -1 ) {matrix[i+1][j+1] += 1;}
    if(matrix[i][j+1] != -1 ) {matrix[i][j+1] += 1;}
    if(matrix[i-1][j+1] != -1 ) {matrix[i-1][j+1] += 1;}
    if(matrix[i-1][j-1] != -1 ) {matrix[i-1][j-1] += 1;}
    if(matrix[i+1][j-1] != -1 ) {matrix[i+1][j-1] += 1;}
    if(matrix[i][j-1] != -1 ) {matrix[i][j-1] += 1;}
    if(matrix[i-1][j] != -1 ) {matrix[i-1][j] += 1;}

}

int main() {
    while(1){
        printf("Введите размерность поля(m * n):\n");
        int m_side = check_validate_int();
        int n_side = check_validate_int();


        int **matrix =(int**) malloc((m_side + 2) * sizeof(int*));
        for(int i = 0; i < m_side + 2; i++) {
            matrix[i] = (int*) malloc((n_side + 2) * sizeof(int));
        }

        nuller(matrix, m_side, n_side);

        for(int i = 1; i < m_side + 1; i++) {
            for(int j = 1; j < n_side + 1; j++) {
                matrix[i][j] = checkinput();
            }
        }
        for(int i = 1; i < m_side + 1; i++) {
            for(int j = 1; j < n_side + 1; j++) {
                if(matrix[i][j] == -1 ) {
                    saper(matrix, i, j);
                }
            }
        }

        for(int i = 1; i <= m_side; i++) {
            for(int j = 1; j <= n_side; j++) {
                if(matrix[i][j] == -1) {
                    printf("* ");
                }
                else if(matrix[i][j] == 0) {
                    printf(". ");
                }
                else {
                    printf("%d ", matrix[i][j]);
                }
            }
            printf("\n");
        }
        for(int i = 0; i < m_side + 2; i++) {
            free(matrix[i]);
        }
        free(matrix);
        printf("Если хотите завершить программу нажмите q\nЧтобы повторить вывод нажмите r\n");

        char stop_check = programm_end_check();

        if (stop_check == 'q') {
            break;
        }
    }
    printf("Вы победили! Программа завершена.");
}

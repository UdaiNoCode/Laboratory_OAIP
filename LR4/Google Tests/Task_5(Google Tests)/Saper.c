#include <stdio.h>
#include <stdlib.h>
#include "Saper.h"



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


int** matrix_game(int m_side, int n_side, int** matrix_1) {

        int **matrix = (int**)malloc((m_side+2) * sizeof(int*));
        for(int i = 0; i < m_side + 2; i++) {
          matrix[i] = (int*)malloc((n_side+2) * sizeof(int));
        }

    for(int i = 0; i < m_side + 2; i++) {
            for(int j = 0; j < n_side + 2; j++) {
                matrix[i][j] = 0;
            }
        }


    for(int i = 1; i < m_side + 1; i++) {
            for(int j = 1; j < n_side + 1; j++) {
                matrix[i][j] = matrix_1[i - 1][j - 1];
            }
        }

    for(int i = 1; i < m_side + 1; i++) {
        for(int j = 1; j < n_side + 1; j++) {
            if(matrix[i][j] == -1 ) {
                saper(matrix, i, j);
            }
        }
    }

        for(int i = 0; i < m_side; i++) {
            if(matrix_1 != NULL ) {
            free(matrix_1[i]);
          }
        }
        free(matrix_1);
        return matrix;

}

int summer(int **matrix, int row, int col) {
    int sum = 0;
    for(int i = 1; i < row + 1; i++) {
        for(int j = 1; j < col + 1; j++) {
            if(matrix[i][j] != -1) {
                sum += matrix[i][j];
            }
        }
    }

    for(int i = 0; i < row + 2; i++) {
        if(matrix != NULL ) {
            free(matrix[i]);
        }
    }
    free(matrix);

    return sum;
}


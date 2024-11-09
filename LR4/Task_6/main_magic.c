#include<stdlib.h>
#include<stdio.h>
#pragma once;

int** evenDoubleSquare(int n);

int** oddMagicSquare(int n);

int** singlyEvenMagicSquare(int n);

void printSquare(int** matrix, int n);

int check_validate();



int main(int argC,char* argV[]){

    int n_size;
    scanf("%d",&n_size);

    if(n_size == 1) {
        printf("%d", 1);
    }
    else if(n_size == 2) {
        printf("NO");
    }
    else if(n_size % 4 == 0) {
        printSquare(evenDoubleSquare(n_size), n_size);
    }else if(n_size % 2 == 0) {
        printSquare(singlyEvenMagicSquare(n_size), n_size);
    }
    else {
        printSquare(oddMagicSquare(n_size), n_size);
    }
}


int check_validate() {

    int input;
    while (scanf("%d",&input)==0)
    {
        printf("Invalid input. Please enter a number: ");
        scanf("%*s");
    }
    return input;
}

int** evenDoubleSquare(int n) {
    int** matrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*) malloc(n * sizeof(int));
    }

    for ( int i = 0; i<n; i++)
    {
        for ( int j = 0; j<n; j++)

            matrix[i][j] = (n*i) + j + 1;
    }

    for ( int i = 0; i<n/4; i++)
    {
        for ( int j = 0; j<n/4; j++)
            matrix[i][j] = (n*n + 1) - matrix[i][j];
    }

    for ( long int i = 0; i< n/4; i++)
    {
        for ( long int j = 3* (n/4); j<n; j++)
            matrix[i][j] = (n*n + 1) - matrix[i][j];
    }


    for ( long int i = 3* n/4; i<n; i++)
    {
        for ( int j = 0; j<n/4; j++)
            matrix[i][j] = (n*n + 1) - matrix[i][j];
    }


    for ( long int i = 3* n/4; i<n; i++)
    {
        for ( long int j = 3* n/4; j<n; j++)
            matrix[i][j] = (n*n + 1) - matrix[i][j];
    }


    for ( long int i = n/4; i<3* n/4; i++)
    {
        for ( long int j = n/4; j<3* n/4; j++)
            matrix[i][j] = (n*n + 1) - matrix[i][j];
    }

    return matrix;
}

int** oddMagicSquare(int n) {

        int value = 0;
        int squareSize = n * n;
        int c = n / 2, r = 0;

        int** result = (int**)malloc(n*sizeof(int*));

		for(int i=0;i<n;i++) {
		    result[i] = (int*)malloc(n*sizeof(int));
		}

        while (++value <= squareSize) {
            result[r][c] = value;
            if (r == 0) {
                if (c == n - 1) {
                    r++;
                } else {
                    r = n - 1;
                    c++;
                }
            } else if (c == n - 1) {
                r--;
                c = 0;
            } else if (result[r - 1][c + 1] == 0) {
                r--;
                c++;
            } else {
                r++;
            }
        }
        return result;

    }

int** singlyEvenMagicSquare(int n) {
        if (n < 6 || (n - 2) % 4 != 0)
            return NULL;

        int size = n * n;
        int halfN = n / 2;
        int subGridSize = size / 4;

        int** subGrid = oddMagicSquare(halfN);

        int gridFactors[] = {0, 2, 3, 1};
        int** result = (int**)malloc(n*sizeof(int*));

		for(int i=0;i<n;i++) {
		    result[i] = (int*)malloc(n*sizeof(int));
		}

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int grid = (r / halfN) * 2 + (c / halfN);
                result[r][c] = subGrid[r % halfN][c % halfN];
                result[r][c] += gridFactors[grid] * subGridSize;
            }
        }

        int nColsLeft = halfN / 2;
        int nColsRight = nColsLeft - 1;

        for (int r = 0; r < halfN; r++)
            for (int c = 0; c < n; c++) {
                if (c < nColsLeft || c >= n - nColsRight
                        || (c == nColsLeft && r == nColsLeft)) {

                    if (c == 0 && r == nColsLeft)
                        continue;

                    int tmp = result[r][c];
                    result[r][c] = result[r + halfN][c];
                    result[r + halfN][c] = tmp;
                }
            }

        return result;

    }

void printSquare(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        if(matrix != NULL) {
            free(matrix[i]);
        }
    }
    free(matrix);
}


//행렬의 곱셈이 가능한지 판단
//행렬의 덧셈이 가능한지 판단&계산

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100

void print2Darray(int array[][100], int row, int col) {
    printf("====================================\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("[%4d] ", array[i][j]);
        printf("\n");
    }
}

void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            target[i][j] = s1[i][j] + s2[i][j];
    }
}

void input2DArray(int array[][100], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = rand() % 100;
        }
    }
}

int main() {
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int result[ROW][COL];

    int row1, col1, row2, col2;
    srand(time(NULL));

    printf("Input matrix 1 row & col: ");
    scanf("%d %d", &row1, &col1);
    printf("Input matrix 2 row & col: ");
    scanf("%d %d", &row2, &col2);

    input2DArray(matrix1, row1, col1);
    input2DArray(matrix2, row2, col2);

    printf("Matrix 1:\n");
    print2Darray(matrix1, row1, col1);
    printf("Matrix 2:\n");
    print2Darray(matrix2, row2, col2);

    if (row1 == row2 && col1 == col2) {
        addMatrix(matrix1, matrix2, result, row1, col1);
        printf("Added Matrix:\n");
        print2Darray(result, row1, col1);
    }
    else {
        printf("행렬 덧셈 불가능\n");
    }

    if (col1 == row2) {
        printf("행렬 곱셈 가능\n");
    }
    else {
        printf("Error\n");
    }

    return 0;
}

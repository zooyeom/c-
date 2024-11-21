#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100


void print2Darray(int array[][100], int row, int col) {
	printf("====================================\n");
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) printf("[%4d] ", array[i][j]);
		printf("\n");
	}
}
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < row;j++) target[i][j] = s1[i][j] + s2[i][j];
	}
}
void subMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col) {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < row;j++) target[i][j] = s1[i][j] - s2[i][j];
	}
}

int main() {
	int matrix1[ROW][COL];
	int matrix2[ROW][COL];
	int result[ROW][COL];

	int row1, col1, row2, col2;
	srand(time(NULL));
	printf("input matrix 1 row & col :");
	scanf("%d %d", &row1, &col1);
	printf("input matrix 2 row & col :");
	scanf("%d %d", &row2, &col2);
	
	if (col1 == row2) printf("ok");
	else printf("no");
	//input2DArray(matrix1, row, col);
	//input2DArray(matrix2, row, col);
	//addMatrix(matrix1, matrix2, row, col);
	
	//printf2Darray(matrix1, row, col);
	//printf2Darray(matrix2, row, col);
	//printf2Darray(result, row, col);
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main() {
	int number[SIZE];
	int MIDDLE = 0;
	int MAX = 0;
	int MIN = 100;
	int SUM = 0;
	int most, temp;
	
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		number[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < SIZE-1; i++) {
		most = i;
		for (int j = i+1; j < SIZE; j++) {
			if (number[most] < number[j]) {
				most = j;
			}
		}
		temp = number[i];
		number[i] = number[most];
		number[most] = temp;

	}
	for (int i = 0; i < SIZE; i++) {
		printf("%3d", number[i]);
		printf("  ");
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	for (int i = 0; i < SIZE; i++) {
			if (MAX < number[i]) {
				MAX = number[i];
			}
			if (MIN > number[i]) {
				MIN = number[i];
			}
		SUM += number[i];
	}

	MIDDLE = (double)SUM / SIZE;

	printf("최대값은: %d\n", MAX);
	printf("최소값은: %d\n", MIN);
	printf("평균값은: %d\n", MIDDLE);
	
}

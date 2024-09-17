#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100

void Random_number(int* array, int num) {
	
	for (int i = 0; i < size; i++) {
		*(array+i) = rand() % 100 + 1;
	}
}

void Print_number(int array[], int num) {

	for (int i = 0; i < size; i++) {
		printf("%3d", array[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
}

int main() {
	int number[size];

	srand(time(NULL));
	
	Random_number(number, size);

	Print_number(number, size);
}

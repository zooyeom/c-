#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 100
int main() {
	int number[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		number[i] = rand() % 100+1;
	}
	for (int i = 0; i < size; i++) {
		printf("%3d", number[i]);
		if ((i+1) % 10 == 0) {
			printf("\n");
		}
	}
}

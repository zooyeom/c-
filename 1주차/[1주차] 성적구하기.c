#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RE 100

int main() {
	int number[RE];
	int max = 0;
	int min = 100;
	int sum = 0;
	int avg = 0;

	srand(time(NULL));

	for (int i = 0; i < RE; i++) {
		number[i] = rand() % 100+1;
	}
	for (int i = 0; i < RE; i++) {
		printf("%3d", number[i]);
		printf("   ");
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	for (int i = 0; i < RE; i++) {
		if (max < number[i]) {
			max = number[i];
		}
		if (min > number[i]) {
			min = number[i];
		}
	}
	
	for (int i = 0; i < RE; i++) {
		sum += number[i];
	}
	avg = (double)sum / 100;
	printf("ÃÖ´ñ°ª: %d, ÃÖ¼Ú°ª: %d, Æò±Õ: %d\n", max, min, avg);
}

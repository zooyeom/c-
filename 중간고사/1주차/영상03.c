//[예시] 랜덤으로 1~100까지의 수를 100개 저장하고
//최대,최소,평균값을 구하고 10개에 1줄로 출력한다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main() {
	int number[SIZE];
	int max;
	int low;
	int sum = 0;

	srand(time(NULL));

	for (int i = 0; i < SIZE; i++) {
		number[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < SIZE; i++) {
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	max = number[0];
	low = number[0];
	for (int i = 0; i < 10; i++) {
		if (max < number[i]) max = number[i];
		if (low > number[i]) low = number[i];
		sum += number[i];
	}
	printf("최고점: %d 최저점: %d 평균: %.2f", max, low, (float)sum / 10);

}

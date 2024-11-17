#include <stdio.h>
#include <stdlib.h>

int main() {
	char* pChar;
	int* pInt;
	int count;

	scanf("%d", &count);
	pInt = (int*)malloc(count * sizeof(int));
	//int형 크기로 count개 공간을 만들어줘

	for (int i = 0;i < count;i++) pInt[i] = rand() % 100;
	for (int i = 0;i < count;i++) printf("%d ", pInt[i]);
	//pInt[i]의 포인터 표현: *(pInt+i)

	pChar = (char*)pInt;
	//char형으로 해석하라

	while (getchar() != '\n');

	gets(pChar);
	puts(pChar);
	//char형으로 사용할 수 있다.

	free(pInt);
}

//"array.bin"에 1~100을 입력한다. 단 파일을 확인했을때 깨져있을 수 있으나 2진수를 번역하면서 생겼기에 신경 안써도 ㄱㅊ

#include <stdio.h>
#define SIZE 100

int main() {
	int array[100];
	FILE* fp;

	for (int i = 0;i < 100;i++) array[i] = i;

	fp = fopen("array.bin", "wb");
	if (fp == NULL) return -1;

	fwrite(array, sizeof(array), 1, fp);

	fclose(fp);
}

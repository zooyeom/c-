#include <stdio.h>
#define SIZE 100

int main() {
	char input[SIZE];
	FILE* fp = NULL;

	if ((fp = fopen("output.bin", "wb")) == NULL) {
		printf("error...");
	}
	gets(input);
	fwrite(input,strlen(input), 1, fp);

	fclose(fp);
}

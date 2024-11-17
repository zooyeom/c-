//"output.bin"에 있는 내용을 읽어와서 보여준다

#include <stdio.h>
#define SIZE 100

int main() {
	char input[SIZE];
	FILE* fp = NULL;
	int i = 0;
	
	if ((fp = fopen("output.bin", "rb")) == NULL) {
		printf("error...");
	}
	while (!feof(fp)) {
		fread(&input[i], sizeof(char), 1, fp);
		i++;
	}
	input[--i] = '\0';
	puts(input);

	fclose(fp);
}

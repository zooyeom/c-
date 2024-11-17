//5번 입력이 가능하고 입력시에 output.txt파일을 만들어서 거기에 입력해준다.

#include <stdio.h>

int getline(char* line) {
	int ch;
	int i = 0;
	while ((ch = getchar()) != '\n') line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main() {
	char input[100];
	FILE* fp;

	if ((fp = fopen("output.txt", "w")) == NULL) {
		printf("error...");
		return 0;
	}
	for (int i = 0;i < 5;i++) {
		getline(input);
		fputs(input, fp);
		fputs("\n", fp);
	}

	fclose(fp);
	return 0;
}

#include <stdio.h>

int main() {
	int ch;
	int ch1;
	int ch2;
	int ch3;

	//1. 기본저인 getchar()와 putchar의 방식

	ch1 = getchar();
	putchar(ch1);

	//2. 키보드 버퍼에 Enter이전의 값을 저장하여 putchar(ch)에 해당하는 명령을 수행한다.

	ch = getchar();
	putchar(ch);

	ch = getchar();
	putchar(ch);

	//3. do while 문을 활용

	do {
		ch2 = getchar();
		putchar(ch2);
	} while (ch != EOF);   // 여기서는 do를 활용했기 때문에 EOF에 대한 출력값이 존재하게 된다.

	//4. while 문을 활용

	while ((ch3 = getchar()) != EOF) {
		putchar(ch3);
	}

	//5. 배열,포인터와 접목

	char message[100];
	int i = 0;
	int ch4;
	while ((ch4 = getchar()) != '\n') {
		message[i++] = ch;
	}
	message[i] = '\0';
	printf("%s", message[100]);
}

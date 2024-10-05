// 문자 배열에는 NULL이 자동으로 포함이 안되기 때문에 NULL이 나올때까지 %s가 역할을 수행한다.

#include <stdio.h>

int main() {

	char message[] = "Hello World";

	char ch[5] = { 'a','b','c','d','e' };
	char ch2[5] = "abcd";

	printf("%s %s\n", ch, ch2);

	printf("%s", message);
}

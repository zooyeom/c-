/*#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int a, b;
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("a+b = %d", a + b);
}*/

#include <stdio.h>

int main(int argc, char* argv[]) {
	for (int i = 0;i < argc;i++) {
		puts(argv[i]);
	}
}

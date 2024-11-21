#include <stdio.h>
#include <stdlib.h>
#include "report.h"
#include "wday.h"

int main(int argc, char* argv[]) {
	if (argc != 4) {
		printf("Usage: %s <year> <month> <day>\n", argv[0]);
		return 1;
	}

	int year = atoi(argv[1]);
	int month = atoi(argv[2]);
	int day = atoi(argv[3]);

	int diff = week2(year, month, day);
	const char* weekday = wday(year, month, day);

	printf("%d-%02d-%02d -> %s\n", year, month, day, weekday);
	printf("오늘로부터 %d일 후(-전)입니다.\n", diff);

	return 0;
}

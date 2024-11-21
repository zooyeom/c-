#ifndef _WDAY_H
#define _WDAY_H
const char* wday(int year, int month, int day) {
	time_t current;
	struct tm* timeinfo;

	char* WEEK[] = { "sun","mon","tue","wed","thu","fri","sat" };

	current = time(NULL);
	timeinfo = localtime(&current);

	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	mktime(timeinfo);

	return WEEK[timeinfo->tm_wday];
}
#endif

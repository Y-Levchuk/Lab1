#include <time.h>
#include"Date.h"

static const int monthLength[2][12] = { {0,31,59,90,120,151,181,212,243,273,304,334},{0,31,60,91,121,152,182,213,244,274,305,335} };

static long convert(int d, int m, int y) {
	int year = y;
	int days = year * 365 + year / 4 - year / 100 + year / 400;
	bool leap = IsLeapYear(y);
	if (leap) days--;
	return days + monthLength[leap][m - 1] + d;
}

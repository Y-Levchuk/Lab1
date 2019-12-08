#pragma once
#include <time.h>
#include "Date.h"

class UserDate : Date {
	int s, min, h, d, m, y;
public:
	UserDate(int s, int min, int h, int d, int m, int y) :s(s), min(min), h(h), d(d), m(m), y(y) {}
	UserDate() :s(1), min(1), h(1), d(29), m(5), y(1453) {}//29 травня 1453 року, завдяки артилерії, мусульманські війська взяли Константинополь штурмом.
	UserDate(const Date& date) { *this = date; }
	const char* GetDayOfTheWeek() {
		static const int monthLength[2][12] = { {0,31,59,90,120,151,181,212,243,273,304,334},{0,31,60,91,121,152,182,213,244,274,305,335} };
		int year = y;
		int days = year * 365 + year / 4 - year / 100 + year / 400;
		bool leap = IsLeapYear(y);
		if (leap) days--;
		switch ((days + monthLength[IsLeapYear(y)][m - 1] + d + 5) % 7 + 1)
		{
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
		case 7: return "Sunday";
		}
	}

	void SetSecond(int second) { s = second; }
	int GetSecond()const { return s; }

	void SetMinute(int minute) { min = minute; }
	int GetMinute()const { return min; }

	void SetHour(int hour) { h = hour; }
	int GetHour()const { return h; }

	void SetDate(int day) { d = day; }
	int GetDate()const { return d; }

	void SetMonth(int month);
	int GetMonth()const { return m; }

	void SetYear(int year);
	int GetYear() const { return y; }

	Date& AddSecond(int second = 1);
	Date& AddMinute(int minute = 1);
	Date& AddHour(int hour = 1);
	Date& AddDays(int days = 1);
	Date& AddMonth(int month = 1);
	Date& AddYear(int year = 1);
	Date& SubDays(int days = 1);
	Date& SubMonth(int month = 1);
	Date& SubYear(int year = 1);

	Date& operator=(const Date& date);
};
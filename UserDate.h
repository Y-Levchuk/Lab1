#pragma once
#include <time.h>
#include "Date.h"

class UserDate : Date {
private:
	int d;
	int m;
	int y;
public:
	UserDate(int d, int m, int y) :d(d), m(m), y(y) {}
	UserDate() {
		time_t tm;
		time(&tm);
		struct tm* dt = localtime(&tm);
		d = dt->tm_mday;
		m = dt->tm_mon - +1;
		y = dt->tm_year + 2000;
	}
	UserDate(const Date& date) { *this = date; }
	void SetDate(int day) { d = day; }
	int GetDate()const { return d; }


	void SetMonth(int month);
	int GetMonth()const { return m; }

	void SetYear(int year);
	int GetYear() const { return y; }

	Date& AddDays(int days = 1);
	Date& AddMonth(int month = 1);
	Date& AddYear(int year = 1);
	Date& SubDays(int days = 1);
	Date& SubMonth(int month = 1);
	Date& SubYear(int year = 1);

	Date& operator=(const Date& date);

	bool operator < (const Date& date) const;
	bool operator ==(const Date& date) const;
	bool operator > (const Date& date) const;
};
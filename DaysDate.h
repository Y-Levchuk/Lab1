#pragma once
#include"Date.h"

class DaysDate : Date {
private:
	int day;
public:
	DaysDate();
	DaysDate(const DaysDate& date) { day = date.day; }
	DaysDate(int d, int m, int y);
	void SetDate(int day);
	int GetDate() const;
	void SetMonth(int month);
	int GetMonth() const;
	void SetYear(int year);
	int GetYear() const;

	Date& AddDays(int days = 1);
	Date& SubDays(int days = 1);
	Date& AddMonth(int month = 1);
	Date& SubMonth(int month = 1);
	Date& AddYear(int year = 1);
	Date& SubYear(int year = 1);

	Date& operator=(const Date& date);

	bool operator < (const Date& date) const;
	bool operator ==(const Date& date) const;
	bool operator > (const Date& date) const;
	bool operator <=(const Date& date) const;
	bool operator !=(const Date& date) const;
	bool operator >=(const Date& date) const;
};
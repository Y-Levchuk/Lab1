#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include"UserDate.h"

void UserDate::SetMonth(int month) {
	m = month;
	int limit = GetDaysInMonth(m, y);
	if (d > limit) d = limit;
}

void UserDate::SetYear(int year) {
	y = year;
	if (d == 29 && m == FEBRUARY && !IsLeapYear(y)) d = 28;
}

Date & UserDate::AddDays(int days) {
	if (days < 0) return SubDays(-days);
	while (days > 0) {
		int mDay = GetDaysInMonth(m, y);
		if (d + days <= mDay) {
			d += days;
			days = 0;
		}
		else {
			days -= (mDay - d + 1);
			d = 1;
			if (d + days <= mDay) {
				d += days;
				days = 0;
			}
			else {
				days -= (mDay - d + 1);
				d = 1;
				if (++m > DECEMBER) {
					m = JANUARY;
					y++;
				}
			}
		}
	}
	return *this;
}

Date & UserDate::AddMonth(int month) {
	if (month < 0) return SubMonth(-month);
	y += month / 12;
	m += month % 12;
	if (m > DECEMBER) y++, m -= 12;
	int limit = GetDaysInMonth(m, y);
	if (d > limit) d = limit;
	return *this;
}

Date & UserDate::SubMonth(int month) {
	if (month < 0) return AddMonth(-month);
	y -= month / 12;
	m -= month % 12;
	if (m > JANUARY) y--, m += 12;
	int limit = GetDaysInMonth(m, y);
	if (d > limit) d = limit;
	return *this;
}

Date & UserDate::AddYear(int year) {
	y += year;
	if (d == 29 && m == FEBRUARY && !IsLeapYear(y)) d = 28;
	return *this;
}
Date & UserDate::SubYear(int year) {
	y -= year;
	if (d == 29 && m == FEBRUARY && !IsLeapYear(y)) d = 28;
	return *this;
}
Date & UserDate::operator =(const Date & date) {
	d = date.GetDate();
	m = date.GetMonth();
	y = date.GetYear();
	return *this;
}
bool UserDate::operator < (const Date & date) const {
	int date_d = date.GetDate();
	int date_m = date.GetMonth();
	int date_y = date.GetYear();
	return y < date_y || (y == date_y && (m < date_m || (m == date_m && d < date_d)));
}
bool UserDate::operator ==(const Date & date) const {
	return y == date.GetYear() && m == date.GetMonth()&& d == date.GetDate();
}
bool UserDate::operator >(const Date & date) const {
	int date_d = date.GetDate();
	int date_m = date.GetMonth();
	int  date_y = date.GetYear();
	return y > date_y || (y == date_y && (m > date_m || (m == date_m && d > date_d)));
}
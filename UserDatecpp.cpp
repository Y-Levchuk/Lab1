#include <stdio.h>
#include "UserDate.h"

int dif(UserDate date1, UserDate date2,int mode) {
	if (mode == 1) return date1.GetHour() * 3600 + date1.GetMinute() * 60 + date1.GetSecond() - (date2.GetHour() * 3600 + date2.GetMinute() * 60 + date2.GetSecond());
	if (mode == 2) return date1.GetHour() * 60 + date1.GetMinute() - (date2.GetHour() * 60 + date2.GetMinute());
	if (mode == 3) return date1.GetHour() - date2.GetHour();
}

Date& UserDate::AddSecond(int second) {
	h += (second / 3600) % 24;
	min += (second / 60) % 60;
	s += second % 60;
	return *this;
}
Date& UserDate::AddMinute(int minute) { return AddSecond(minute * 60); }
Date& UserDate::AddHour(int hour) { return AddSecond(hour * 3600); }

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

Date & UserDate::SubDays(int days)
{
	if (days < 0) return AddDays(-days);
	while (days > 0) {
		if (d - days >= 0) {
			d -= days;
			days = 0;
		}
		else {
			int mDay;
			days -= d;
			if (m != 1) mDay = GetDaysInMonth(m - 1, y);
			else mDay = GetDaysInMonth(12, y - 1);

			if (days < mDay) {
				d = mDay - days;
				if (--m < JANUARY) {
					m = DECEMBER;
					y--;
				}
				days = 0;
			}
			else {
				days -= mDay;
				d = 0;
				if (--m < JANUARY) {
					m = DECEMBER;
					y--;
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
	h = date.GetHour();
	min = date.GetMinute();
	s = date.GetSecond();
	return *this;
}
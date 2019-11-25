#pragma once
enum Month { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

class Date {
public:
	virtual ~Date() {}
	virtual int GetSecond() const = 0;
	virtual void SetSecond(int second) = 0;
	virtual int GetMinute() const = 0;
	virtual void SetMinute(int minute) = 0;
	virtual int GetHour() const = 0;
	virtual void SetHour(int hour) = 0;
	virtual int GetDate() const = 0;
	virtual void SetDate(int day) = 0;
	virtual int GetMonth() const = 0;
	virtual void SetMonth(int month) = 0;
	virtual int GetYear() const = 0;
	virtual void SetYear(int year) = 0;

	virtual Date& AddDays(int days = 1) = 0;
	virtual Date& SubDays(int days = 1) = 0;
	virtual Date& AddMonth(int month = 1) = 0;
	virtual Date& SubMonth(int month = 1) = 0;
	virtual Date& AddYear(int year = 1) = 0;
	virtual Date& SubYear(int year = 1) = 0;

	virtual Date& operator = (const Date& date) = 0;
	virtual Date& operator +=(int days) { return AddDays(days); }
	virtual Date& operator -=(int days) { return SubDays(days); }
	virtual Date& operator ++() { return AddDays(); }
	virtual Date& operator --() { return SubDays(); }

	virtual const char* GetString() const;

};

bool IsLeapYear(int year);
int GetDaysInMonth(int month, int year);
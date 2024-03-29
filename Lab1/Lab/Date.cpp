#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"Date.h"

/*
	Перевірка року на те ,що він є високосним
	Приймає як параметр рік
*/
bool IsLeapYear(int year) { return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0); }

/*
	Повертає кількість днів у місяці для відповідного року і місяця
	Приймає як параметри: рік і місяць
*/
int GetDaysInMonth(int month, int year) {
	static int monthLength[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return monthLength[month - 1] + (month == FEBRUARY && IsLeapYear(year));
}

/*
	Повертає дату у вигляді рядка ДД-ММ-РРРР
	Не приймає параметрів 
*/
const char* Date::GetString() const {
	static const char* monthName[] = { "January", "February","March","April","May","June","July","August","September","October","November","December" };
	char* res = new char[20];
	sprintf(res, "%2d-%s-%4d", GetDate(), monthName[GetMonth() - 1], GetYear());
	return res;
}
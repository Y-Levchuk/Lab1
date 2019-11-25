#include <iostream>
#include "UserDate.h"

int main()
{
	UserDate f;
	f.SetDate(26);
	f.SetYear(2019);
	f.SetMonth(11);
	std::cout << f.GetDate() << '.' << f.GetMonth() << '.' << f.GetYear()<<"  "<<f.GetDayOfTheWeek();

	return 0;
}
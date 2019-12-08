#include <iostream>
#include "UserDate.h"
#include "MatrixGraph.h"
using namespace std;

std::ostream& operator<< (std::ostream& out, UserDate& f)
{
	out << f.GetSecond() << ':' << f.GetMinute() << ':' << f.GetHour() << "  ";
	out << f.GetDate() << '.' << f.GetMonth() << '.' << f.GetYear() << "  " << f.GetDayOfTheWeek() << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, UserDate& f)
{
	int tmp;
	cout << "Enter second" << endl;
	in >> tmp;
	f.SetSecond(tmp % 60);
	cout << "Enter minute" << endl;
	in >> tmp;
	f.SetMinute(tmp % 60);
	cout << "Enter hour" << endl;
	in >> tmp;
	f.SetHour(tmp % 24);
	cout << "Enter day" << endl;
	in >> tmp;
	f.SetDate(tmp % 32);
	cout << "Enter mounth" << endl;
	in >> tmp;
	f.SetMonth(tmp % 13);
	cout << "Enter year" << endl;
	in >> tmp;
	f.SetYear(tmp);
	return in;
}

int main()
{
	int n,n1,n2;
	MatrixGraph a(63);
	UserDate user_date;
again:
	cout << "1) Graph" << endl;
	cout << "2) UserDate" << endl;
	cout << "3) Clear" << endl;
	cout << "4) Exit" << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "1) SetNvertex" << endl;
		cout << "2) ShortWay" << endl;
		cout << "3) AddArc" << endl;
		cout << "4) HasArc" << endl;
		cout << "5) CountVertex" << endl;
		cout << "6) Create new graph" << endl;
		cout << "7) Exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "Enter count of vertex" << endl;
			cin >> n;
			a.SetNvertex(n);
			break;
		case 2:
			cout << "Enter number first vertex" << endl;
			cin >> n;
			cout << "Enter number second vertex" << endl;
			cin >> n1;
			cout << a.ShortWay(n, n1) << endl;
			cin.get();
			break;
		case 3:
			cout << "Enter number first vertex" << endl;
			cin >> n;
			cout << "Enter number second vertex" << endl;
			cin >> n1;
			cout << "1) Enter user_date" << endl;
			cout << "2) Skip" << endl;
			cin >> n2;
			if (n2 == 1) {
				cin >> user_date;
				a.AddArc(n, n1, &user_date);
			}
			else a.AddArc(n, n1, nullptr);
			break;
		case 4:
			cout << "Enter number first vertex" << endl;
			cin >> n;
			cout << "Enter number second vertex" << endl;
			cin >> n1;
			cout << *a.HasArc(n, n1) << endl;
			cin.get();
			break;
		case 5:
			cout << a.CountVertex() << endl;
			cin.get();
			break;
		case 6:
			cout << "Enter count of vertex" << endl;
			cin >> n;
			a.SetNvertex(n);
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < n; j++)
				{
					if (i != j) {
						cout << "1) Enter user_date[" << i << "][" << j << ']' << endl;
						cout << "2) Skip" << endl;
						cin >> n2;
						if (n2 == 1) {
							cin >> user_date;
							a.AddArc(i, j, &user_date);
						}
						else a.AddArc(i, j, nullptr);
					}
					else a.AddArc(i, j, nullptr);
				}
			break;
		default: goto again;
		}
		break;
	case 2:
		cout << "1) Create new user_date" << endl; 
		cout << "2) Show user_date" << endl;
		cout << "3) Add" << endl; 
		cout << "4) Exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cin >> user_date;
			break;
		case 2:
			cout << user_date;
			break;
		case 3:
			cout << "1) Add second" << endl;
			cout << "2) Add minute" << endl;
			cout << "3) Add hour" << endl;
			cout << "4) Add day" << endl;
			cout << "5) Add mounth" << endl;
			cout << "6) Add year" << endl;
			cout << "7) Exit" << endl;
			cin >> n;
			switch (n)
			{
			case 1:
				cout << "Enter second" << endl;
				cin >> n;
				user_date.AddSecond(n);
				break;
			case 2:
				cout << "Enter minute" << endl;
				cin >> n;
				user_date.AddMinute(n);
				break;
			case 3:
				cout << "Enter hour" << endl;
				cin >> n;
				user_date.AddHour(n);
				break;
			case 4:
				cout << "Enter day" << endl;
				cin >> n;
				user_date.AddDays(n); 
				break;
			case 5:
				cout << "Enter mounth" << endl;
				cin >> n;
				user_date.AddMonth(n);
				break;
			case 6:
				cout << "Enter year" << endl;
				cin >> n;
				user_date.AddYear(n);
				break;
			default: goto again;
			}
			break;
		default: goto again;
		}
		break;
	case 3: system("cls"); break;
	case 4: return 0;
	default: goto again;
	}
	goto again;
	return 0;
}
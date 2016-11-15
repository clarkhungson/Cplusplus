#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include <iomanip>

char month_table[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char leap_month_table[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Check leap year or not
#define IS_LEAP_YEAR(year) ((year%400 == 0) || (year%4 == 0 && year % 100 != 0))

class CDate
{
private:
	int day;
	int month;
	int year;
public:
	CDate(int d = 0, int m = 0, int y = 0): day(d), month(m), year(y)
	{

	}
	~CDate()
	{

	}
	void print()
	{
		cout << setfill('0') << setw(2) << day << "-" << setfill('0') << setw(2) 
		<< month << "-" << setfill('0') << setw(4) << year << endl;
	}
	void nextDay()
	{
		day++;
		if (IS_LEAP_YEAR(year))
		{
			if (day > leap_month_table[month - 1])
			{
				day = 1;
				month++;
				if (month > 12)
				{
					month = 1;
					year++;
				}
			}
		}
		else
		{
			if (day > month_table[month - 1])
			{
				day = 1;
				month++;
				if (month > 12)
				{
					month = 1;
					year++;
				}
			}
		}
	}

	bool validDate()
	{
		//validate dd/mm/yyy
		if (year < 1 || year > 9999 ||
			month < 1 || month > 12 ||
			day < 1 || day > 31)
		{
			return false;
		}

		if (IS_LEAP_YEAR(year))
		{
			if (day > leap_month_table[month - 1])
			{
				return false;
			}
		}
		else
		{
			if (day > month_table[month - 1])
			{
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	int date, month, year;
	date = atoi(argv[1]);
	month = atoi(argv[2]);
	year = atoi(argv[3]);

	CDate date_obj(date, month, year);
	if (date_obj.validDate())
	{
		date_obj.print();
		date_obj.nextDay();
		date_obj.print();
	}
	else
	{
		cout << "Invalid Date" << endl;
	}
	return 0;
}
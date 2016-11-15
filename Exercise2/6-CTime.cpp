#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>
#include <iomanip>

class CTime
{
private:
	int hour;
	int minute;
	int second;
public:
	CTime(int h = 0, int m = 0, int s = 0): hour(h), minute(m), second(s)
	{

	}
	void set(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}
	void setHour(int h) {hour = h;}
	void setMinue(int m) {minute = m;}
	void setSecond(int s) {second = s;}
	int getHour() {return hour;}
	int getMinute() {return minute;}
	int getSecond() {return second;}
	bool checkValidTime();
	void display24();
	void display12();
};

void CTime::display24()
{
	if (checkValidTime())
	{
		cout << "display24   "
			 << setfill('0') << setw(2) << hour << ":"
			 << setfill('0') << setw(2) << minute << ":"
			 << setfill('0') << setw(2) << second << endl;
	}
	else
	{
		cout << "display24   "
		     << setfill('0') << setw(2) << hour << ":"
			 << setfill('0') << setw(2) << minute << ":"
			 << setfill('0') << setw(2) << second << " is invalid" << endl;
	}
}

void CTime::display12()
{
	if (checkValidTime())
	{
		if (hour >= 12)
			cout << "display12   "
				 << setfill('0') << setw(2) << hour - 12 << ":"
				 << setfill('0') << setw(2) << minute << ":"
				 << setfill('0') << setw(2) << second << " PM" << endl;
		else
			cout << "display12   "
		         << setfill('0') << setw(2) << hour << ":"
				 << setfill('0') << setw(2) << minute << ":"
				 << setfill('0') << setw(2) << second << " AM" << endl;
	}
	else
	{
		cout << setfill('0') << setw(2) << hour << ":"
			 << setfill('0') << setw(2) << minute << ":"
			 << setfill('0') << setw(2) << second << " is invalid" << endl;
	}
}

bool CTime::checkValidTime()
{
	int h, m, s;
	h = getHour();
	m = getMinute();
	s = getSecond();
	if (h < 0 || h > 23 ||
		m < 0 || m > 59 ||
		s < 0 || s > 59)
	{
		return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int hour = atoi(argv[1]);
	int minute = atoi(argv[2]);
	int second = atoi(argv[3]);

	CTime time(hour, minute, second);
	time.display24();
	time.display12();
	return 0;
}
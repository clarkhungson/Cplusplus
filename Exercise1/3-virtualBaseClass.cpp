#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

class student
{
	int id;
public:
	void getNumber()
	{
		cout << "Id: " << id << endl;
	}
	void putNumber()
	{
		cout << "Input id: ";
		cin >> id;
	}
};

class mark: virtual public student
{
public:
	int mark1, mark2;
	void getMark()
	{
		cout << "Mark1: " << mark1 << endl;
		cout << "Mark2: " << mark2 << endl;
	}
	void putMark()
	{
		cout << "Input mark1: ";
		cin >> mark1;
		cout << "Input mark2: ";
		cin >> mark2;
	}
};
class english: virtual public student
{
public:
	int english;
	void getScore()
	{
		cout << "English: " << english << endl;
	}
	void putScore()
	{
		cout << "Input english:";
		cin >> english;
	}
};

class result: public mark, public english
{
	int sum;
public:
	void display()
	{
		sum = mark1 + mark2 + english;
		getNumber();
		getMark();
		getScore();
		cout << "Sum = " << sum;
	}
};
int main()
{
	result obj;
	obj.putNumber();
	obj.putMark();
	obj.putScore();
	obj.display();
	return 0;
}
#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

class staff
{
public:
	int id;
	char name[30];
	char rank[20];
	void getInfo()
	{
		cout << "Id: ";
		cin >> id;
		cout << "Name: ";
		cin >> name;
		cout << "Rank: ";
		cin >> rank;
	}
};

class salary: public staff
{
public:
	float basicSalary, allowancePosition, allowanceResponsibility, sum;
	void get()
	{
		cout << "basicSalary: ";
		cin >> basicSalary;
		cout << "allowancePosition: ";
		cin >> allowancePosition;
		cout << "allowanceResponsibility: ";
		cin >> allowanceResponsibility;
	}
	void calculate()
	{
		sum = basicSalary + allowancePosition + allowanceResponsibility;
	}
	void display()
	{
		cout << "Id: " << id << ", name: " << name << ", rank: " << rank << ", sum: " << sum << endl;
	}
};

int main()
{
	int i, n;
	char ch;
	salary s[10];
	cout << "Number of staffs: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		s[i].getInfo();
		s[i].get();
		s[i].calculate();
	}
	
	cout << "-----------------------------------------------------------------------------------";
	for (i = 0; i < n; i++)
	{
		s[i].display();
	}
	cout << "-----------------------------------------------------------------------------------";
	return 0;
}
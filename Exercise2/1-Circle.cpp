#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

class Cpoint
{
private:
	double x, y;
public:
	char name[20];
	Cpoint()
	{
		x = 0;
		y = 0;
		strcpy(name, "Point");
	}
	Cpoint(double x, double y)
	{
		this -> x = x;
		this -> y = y;
		strcpy(name, "Point");
	}
	void getArea()
	{

	}
	void showXY()
	{
		cout << "It is a/an " << name << endl;
		cout << "x = " << x << ", y = " << y << endl;
	}

};

class Ccircle: Cpoint
{
private:
	double r;
public:
	Ccircle()
	{
		r = 0;
		strcpy(name, "Circle");
	}
	Ccircle(double x, double y, double r) :Cpoint(x, y)
	{
		this -> r = r;
		strcpy(name, "Circle");
	}
	void getArea()
	{
		cout << "Area = " << 3.14 * r * r << endl;
	}
	void showXYr()
	{
		showXY();
		cout << "r = " << r << endl;
	}
};

int main()
{
	Cpoint A(3, -4);
	A.showXY();
	Ccircle c(3, 2, 2);
	c.getArea();
	c.showXYr();
	
	return 0;
}
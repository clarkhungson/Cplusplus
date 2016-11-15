#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

class CPolygon
{
protected:
	int width, height;
public:
	void set_values(int a, int b)
	{
		width = a;
		height = b;
	}
};

class CRectangle: public CPolygon
{
public:
	int area()
	{
		return width * height;
	}
};

class CTriangle: public CPolygon
{
public:
	int area()
	{
		return width * height / 2;
	}
};

int main()
{
	CRectangle rect;
	CTriangle trg1;
	rect.set_values(4, 5);
	trg1.set_values(4, 5);
	cout << "Area of rectangle: " << rect.area() << endl;
	cout << "Area of triangle: " << trg1.area() << endl;
	return 0;
}


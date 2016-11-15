#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

class Rectangle
{
	int width, height;
public:
	Rectangle(){}
	Rectangle(int x, int y) : width(x), height(y) {}
	int area() {return width * height;}
	friend Rectangle duplicate (const Rectangle& );
};
Rectangle duplicate (const Rectangle & param)
{
	Rectangle res;
	res.width = param.width * 2;
	res.height = param.height * 2;
	return res;
}

int main()
{
	Rectangle r1;
	Rectangle r2 (2, 3);
	r1 = duplicate(r2);
	cout << r1.area() << endl;
	return 0;
}
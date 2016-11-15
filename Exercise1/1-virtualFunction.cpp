#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

class coso
{
public:
	coso()
	{

	}
	virtual void show()
	{
		cout << "Hien ti lop co so" << endl;
	}
	void display()
	{
		cout << "Trung bay lop co so" << endl;
	}

};

class kethua: public coso
{
public:
	void show()
	{
		cout << "Hien thi lop con" << endl;
	}
	void display()
	{
		cout << "Trung bay lop con" << endl;
	}
};

int main()
{
	coso doituong;
	doituong.display();
	doituong.show();

	kethua doituong2;
	doituong2.display();
	doituong2.show();
}
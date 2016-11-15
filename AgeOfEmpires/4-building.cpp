#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <vector>
#include "3-unit.cpp"

typedef struct {
	int attack;

} k_S_upgrade;

class Building
{
	char * name;
	int blood;
	int price;
	vector<Unit *> vec;

public:
	Building()
	{
		name = new char[10];
		strcpy(name, "");
		blood = 0;
		price = 0;
	}
	Building(const char * name, int blood, int price)
	{
		this -> name = new char[10];
		strcpy(this -> name, name);
		this -> blood = blood;
		this -> price = price;
	}

	void attach(Unit *unit)
	{
		vec.push_back(unit);
	}
	void upgrade()
	{
		for (vector<Unit *>::iterator v = vec.begin(); v != vec.end(); v++)
		{
			(*v) -> upgrade();
		}
	}
};

// int main()
// {
// 	building("S", 200, 125);
// 	return 0;
// }